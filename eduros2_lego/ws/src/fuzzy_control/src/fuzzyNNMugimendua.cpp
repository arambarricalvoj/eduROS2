#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "mezuak/msg/mugimendu_kodetzaileak.hpp"
#include "sensor_msgs/msg/range.hpp"
#include "std_msgs/msg/int32.hpp"

#include <torch/script.h> // LibTorch
#include <optional>
#include <vector>
#include <fstream>
#include <chrono>
#include <string>

using std::placeholders::_1;

class NNControlNode : public rclcpp::Node {
public:
    NNControlNode() : Node("nn_control_node") {

        // Parámetros
        this->declare_parameter<double>("eten_distantzia", 0.15);
        this->declare_parameter<bool>("seinalea_gorde", true);
        this->declare_parameter<std::string>("kontrol_mota", "nbs");   // nbs | nag | npg
        this->declare_parameter<double>("factor", 1.0);                // ganancia aplicada al delta_v
        this->declare_parameter<std::string>("modeloa", "/home/javierac/eduros2_lego/ws/install/fuzzy_control/share/ikas_datuak/model.pt"); 

        eten_distantzia_ = this->get_parameter("eten_distantzia").as_double();
        seinalea_gorde_  = this->get_parameter("seinalea_gorde").as_bool();
        kontrol_mota_    = this->get_parameter("kontrol_mota").as_string();
        factor_          = this->get_parameter("factor").as_double();
        path = this->get_parameter("modeloa").as_string();

        // Suscripciones
        sub_encoders_ = this->create_subscription<mezuak::msg::MugimenduKodetzaileak>(
            "/kodetzaileak", 10, std::bind(&NNControlNode::encoder_callback, this, _1));

        sub_range_ = this->create_subscription<sensor_msgs::msg::Range>(
            "distantzia", 10, std::bind(&NNControlNode::range_callback, this, _1));

        sub_yaw_ = this->create_subscription<std_msgs::msg::Int32>(
            "yaw_angelua", 10, std::bind(&NNControlNode::yaw_callback, this, _1));

        // Publicador
        pub_cmd_vel_ = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);

        // Cargar el modelo TorchScript
        try {
            torch::jit::script::Module m = torch::jit::load(path);
            module_ = std::move(m);
            RCLCPP_INFO(this->get_logger(), "Modelo cargado correctamente: %s", path.c_str());
        } catch (const c10::Error& e) {
            RCLCPP_ERROR(this->get_logger(), "Error cargando el modelo: %s", e.what());
        }

        // Inicializar CSV
        if (seinalea_gorde_) {
            csv_name_ = "registro_nn.csv";
            csv_.open(csv_name_, std::ios::out);
            if (!csv_.is_open()) {
                RCLCPP_WARN(this->get_logger(), "No se pudo abrir el CSV: %s", csv_name_.c_str());
            } else {
                csv_ << "timestamp,pos_izq,pos_der,vel_izq,vel_der,yaw,distancia,"
                        "delta_v,delta_v_aplicado\n";
            }
        }
    }

    ~NNControlNode() override {
        if (csv_.is_open()) {
            csv_.flush();
            csv_.close();
        }
    }

private:
    // Callbacks de sensores
    void range_callback(const sensor_msgs::msg::Range::SharedPtr msg) {
        ultrasoinu_distantzia_ = msg->range;
    }

    void yaw_callback(const std_msgs::msg::Int32::SharedPtr msg) {
        yaw_angle_ = msg->data; // yaw en grados
    }

    // Callback principal
    void encoder_callback(const mezuak::msg::MugimenduKodetzaileak::SharedPtr msg) {
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

        if (dist <= eten_distantzia_) {
            auto stop_twist = geometry_msgs::msg::Twist();
            pub_cmd_vel_->publish(stop_twist);
            RCLCPP_INFO(this->get_logger(),
                        "Objeto cercano (%.3f m <= %.3f m). Robot detenido.",
                        dist, eten_distantzia_);
            return;
        }

        // Inferencia de la red
        std::vector<float> input_data = {
            static_cast<float>(msg->graduak[0]),   
            static_cast<float>(msg->graduak[1]),   
            static_cast<float>(msg->abiadurak[0]),
            static_cast<float>(msg->abiadurak[1]), 
            static_cast<float>(yaw_angle_),        
            static_cast<float>(0.0f),              
            static_cast<float>(dist)               
        };

        torch::Tensor input = torch::tensor(input_data).reshape({1, 7});
        torch::Tensor output = module_.value().forward({input}).toTensor();
        double delta_v = output.item<double>();

        // Aplicar ganancia "factor" al delta_v
        double delta_v_aplicado = delta_v * factor_;

        // Publicar cmd_vel
        auto twist = geometry_msgs::msg::Twist();
        twist.linear.x = 25.0; // velocidad base
        twist.angular.z = (delta_v_aplicado / 100.0) * twist.linear.x;
        pub_cmd_vel_->publish(twist);

        // Guardar paso al CSV
        log_csv(delta_v, delta_v_aplicado, msg, dist);
    }

    // Logging CSV
    void log_csv(double delta_v, double delta_v_aplicado,
                 const mezuak::msg::MugimenduKodetzaileak::SharedPtr& msg,
                 double dist) {
        if (!seinalea_gorde_ || !csv_.is_open()) return;
        auto ts = std::chrono::system_clock::now().time_since_epoch();
        long long timestamp_ms = std::chrono::duration_cast<std::chrono::milliseconds>(ts).count();
        csv_ << timestamp_ms << ","
             << static_cast<int>(msg->graduak[0]) << ","
             << static_cast<int>(msg->graduak[1]) << ","
             << static_cast<int>(msg->abiadurak[0]) << ","
             << static_cast<int>(msg->abiadurak[1]) << ","
             << yaw_angle_ << ","
             << dist << ","
             << delta_v << ","
             << delta_v_aplicado
             << "\n";
    }

    // Suscriptores y publicadores
    rclcpp::Subscription<mezuak::msg::MugimenduKodetzaileak>::SharedPtr sub_encoders_;
    rclcpp::Subscription<sensor_msgs::msg::Range>::SharedPtr sub_range_;
    rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr sub_yaw_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr pub_cmd_vel_;

    // Estado interno
    std::optional<double> ultrasoinu_distantzia_;
    double eten_distantzia_;
    int yaw_angle_ = 0;

    // Modelo
    std::optional<torch::jit::script::Module> module_;

    // CSV
    bool seinalea_gorde_ = true;
    std::ofstream csv_;
    std::string csv_name_;
    std::string kontrol_mota_;
    std::string path;
    double factor_;
};

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<NNControlNode>());
    rclcpp::shutdown();
    return 0;
}
