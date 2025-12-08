#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "mezuak/msg/mugimendu_kodetzaileak.hpp"
#include "mezuak/msg/ikas_datuak.hpp"
#include "sensor_msgs/msg/range.hpp"
#include "std_msgs/msg/int32.hpp"

#include <torch/script.h> // LibTorch
#include <optional>
#include <vector>
#include <cmath>

using std::placeholders::_1;

class NNControlNode : public rclcpp::Node {
public:
    NNControlNode() : Node("nn_control_node") {
        // Ruta del modelo (TorchScript)
        std::string path = "/home/javierac/eduros2_lego/ws/install/ikas_datuak/model.pt";

        // Parámetros
        this->declare_parameter<double>("eten_distantzia", 0.15);
        eten_distantzia_ = this->get_parameter("eten_distantzia").as_double();

        this->declare_parameter<std::string>("ikas_modua", "False");
        ikas_modua_ = this->get_parameter("ikas_modua").as_string();

        // Suscripciones
        sub_encoders_ = this->create_subscription<mezuak::msg::MugimenduKodetzaileak>(
            "/kodetzaileak", 10, std::bind(&NNControlNode::encoder_callback, this, _1));

        sub_range_ = this->create_subscription<sensor_msgs::msg::Range>(
            "distantzia", 10, std::bind(&NNControlNode::range_callback, this, _1));

        sub_yaw_ = this->create_subscription<std_msgs::msg::Int32>(
            "yaw_angelua", 10, std::bind(&NNControlNode::yaw_callback, this, _1));

        // Publicadores
        pub_cmd_vel_ = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
        pub_training_ = this->create_publisher<mezuak::msg::IkasDatuak>("ikasteko_datuak", 10);

        // Cargar el modelo TorchScript
        try {
            torch::jit::script::Module m = torch::jit::load(path);
            module_ = std::move(m);
            RCLCPP_INFO(this->get_logger(), "Modelo cargado correctamente: %s", path.c_str());
        } catch (const c10::Error& e) {
            RCLCPP_ERROR(this->get_logger(), "Error cargando el modelo: %s", e.what());
        }
    }

private:
    // Callbacks de sensores
    void range_callback(const sensor_msgs::msg::Range::SharedPtr msg) {
        ultrasoinu_distantzia_ = msg->range;
    }

    void yaw_callback(const std_msgs::msg::Int32::SharedPtr msg) {
        yaw_angle_ = msg->data; // Se asume yaw en grados
    }

    // Callback principal
    void encoder_callback(const mezuak::msg::MugimenduKodetzaileak::SharedPtr msg) {
        // Comprobaciones de disponibilidad
        if (!ultrasoinu_distantzia_.has_value()) {
            RCLCPP_WARN_THROTTLE(this->get_logger(), *this->get_clock(), 2000,
                                 "Aún no hay datos de distancia. Ignorando callback.");
            return;
        }
        if (!module_.has_value()) {
            RCLCPP_WARN_THROTTLE(this->get_logger(), *this->get_clock(), 5000,
                                 "Modelo no cargado. Ignorando control.");
            return;
        }

        const double dist = ultrasoinu_distantzia_.value();

        // Inicio de episodio: primer registro tras terminar o al arrancar
        if (!episodio_activo_) {
            yaw_offset_ = static_cast<double>(yaw_angle_);
            episodio_activo_ = true;
            episodio_terminado_ = false;
            RCLCPP_INFO(this->get_logger(), "Inicio de episodio. Yaw offset = %.2f", yaw_offset_);
        }

        // Condición de parada por obstáculo: fin de episodio
        if (dist <= eten_distantzia_) {
            auto stop_twist = geometry_msgs::msg::Twist();
            pub_cmd_vel_->publish(stop_twist);
            RCLCPP_INFO(this->get_logger(), "Objeto cercano (%.3f m <= %.3f m). Robot detenido.",
                        dist, eten_distantzia_);

            // Publicar SOLO una vez la transición final con done = true
            if (!episodio_terminado_) {
                auto sample = mezuak::msg::IkasDatuak();
                // Estado actual
                sample.pos_izq = msg->graduak[0];
                sample.pos_der = msg->graduak[1];
                sample.vel_izq = msg->abiadurak[0];
                sample.vel_der = msg->abiadurak[1];
                sample.yaw = yaw_angle_;
                sample.error_traj = 0.0f; // si lo calculas, ponlo aquí

                // Acción final (0 al detener)
                sample.delta_v = 0.0;

                // Distancia restante respecto al umbral
                sample.dist_restante = dist - eten_distantzia_;

                // Marcar fin y asignar recompensa según yaw final ~ yaw inicial (±2 grados)
                const double yaw_diff = std::abs(static_cast<double>(yaw_angle_) - yaw_offset_);
                const bool exito = (yaw_diff <= 2.0);

                sample.done = true;
                sample.reward = exito ? +10.0f : -10.0f;

                pub_training_->publish(sample);
                RCLCPP_INFO(this->get_logger(),
                            "Episodio %s. yaw_final=%.2f, yaw_inicial=%.2f, diff=%.2f, reward=%.1f",
                            exito ? "exitoso" : "fallido",
                            static_cast<double>(yaw_angle_), yaw_offset_, yaw_diff, sample.reward);

                // Reset de flags para próximo episodio
                episodio_terminado_ = true;
                episodio_activo_ = false;
            }
            return; // fin de callback tras detener
        }

        // Inferencia de la red (features: 7)
        std::vector<float> input_data = {
            static_cast<float>(msg->graduak[0]),   // pos_izq
            static_cast<float>(msg->graduak[1]),   // pos_der
            static_cast<float>(msg->abiadurak[0]), // vel_izq
            static_cast<float>(msg->abiadurak[1]), // vel_der
            static_cast<float>(yaw_angle_),        // yaw (grados)
            static_cast<float>(0.0f),              // error_traj (si lo calculas aparte)
            static_cast<float>(dist)               // distancia absoluta al obstáculo
        };

        torch::Tensor input = torch::tensor(input_data).reshape({1, 7});
        torch::Tensor output = module_.value().forward({input}).toTensor();
        double delta_v = output.item<double>();
        /*torch::Tensor state = torch::tensor(input_data).reshape({1, 7});
        torch::Tensor action = torch::tensor({0.0f}).reshape({1, 1}); // ejemplo acción
        torch::Tensor output = module_.value().forward({state, action}).toTensor();
        double delta_v = output.item<double>();*/


        // Publicar cmd_vel
        auto twist = geometry_msgs::msg::Twist();
        twist.linear.x = 25.0; // velocidad base
        twist.angular.z = (delta_v / 100.0) * twist.linear.x;
        pub_cmd_vel_->publish(twist);

        // Publicar transición de entrenamiento (cada paso)
        if (ikas_modua_ == "True") {
            auto sample = mezuak::msg::IkasDatuak();
            sample.pos_izq = msg->graduak[0];
            sample.pos_der = msg->graduak[1];
            sample.vel_izq = msg->abiadurak[0];
            sample.vel_der = msg->abiadurak[1];
            sample.yaw = yaw_angle_;
            sample.error_traj = 0.0f; // o el valor calculado si lo tienes
            sample.delta_v = delta_v;
            sample.dist_restante = dist - eten_distantzia_;

            // Recompensa paso a paso (opcional). Si no quieres shaping, déjala en 0.
            sample.reward = 0.0f;
            sample.done = false;

            pub_training_->publish(sample);
        }
    }

    // Suscriptores y publicadores
    rclcpp::Subscription<mezuak::msg::MugimenduKodetzaileak>::SharedPtr sub_encoders_;
    rclcpp::Subscription<sensor_msgs::msg::Range>::SharedPtr sub_range_;
    rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr sub_yaw_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr pub_cmd_vel_;
    rclcpp::Publisher<mezuak::msg::IkasDatuak>::SharedPtr pub_training_;

    // Estado interno
    std::optional<double> ultrasoinu_distantzia_;
    std::string ikas_modua_;
    double eten_distantzia_;
    int yaw_angle_ = 0;

    // Gestión de episodios
    bool episodio_activo_ = false;
    bool episodio_terminado_ = false;
    double yaw_offset_ = 0.0;

    // Modelo
    std::optional<torch::jit::script::Module> module_;
};

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<NNControlNode>());
    rclcpp::shutdown();
    return 0;
}
