#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "mezuak/msg/mugimendu_kodetzaileak.hpp"
#include "mezuak/msg/ikas_datuak.hpp"
#include "sensor_msgs/msg/range.hpp"
#include "std_msgs/msg/int32.hpp"
#include "fuzzy_control/fuzzyEngine.hpp"
#include "fuzzy_control/trajectoryError.hpp"

#include <fstream>
#include <chrono>
#include <optional>
#include <string>

using std::placeholders::_1;

class FuzzyControlNode : public rclcpp::Node {
public:
    FuzzyControlNode() 
    : Node("fuzzy_control_node"),
      trajectory_error_(0.0624, 0.011) // diámetro rueda=62.4mm, axle_track=11mm
    {
        // Parámetros
        this->declare_parameter<double>("abiadura", 25.0);
        this->declare_parameter<double>("eten_distantzia", 0.15);
        this->declare_parameter<std::string>("kontrol_mota", "abiadura"); 
        this->declare_parameter<std::string>("ikas_modua", "False"); 
        this->declare_parameter<bool>("seinalea_gorde", true);

        abiadura_ = this->get_parameter("abiadura").as_double();
        eten_distantzia_ = this->get_parameter("eten_distantzia").as_double();
        kontrol_mota_ = this->get_parameter("kontrol_mota").as_string();
        ikas_modua_ = this->get_parameter("ikas_modua").as_string();
        seinalea_gorde_ = this->get_parameter("seinalea_gorde").as_bool();

        // Suscripciones comunes
        sub_encoders_ = this->create_subscription<mezuak::msg::MugimenduKodetzaileak>(
            "/kodetzaileak", 10,
            std::bind(&FuzzyControlNode::encoder_callback, this, _1));

        sub_range_ = this->create_subscription<sensor_msgs::msg::Range>(
            "distantzia", 10,
            std::bind(&FuzzyControlNode::range_callback, this, _1));

        pub_ = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);

        pub_training_ = this->create_publisher<mezuak::msg::IkasDatuak>(
            "ikasteko_datuak", 10);

        // Suscripción al yaw solo si kontrol_mota == "nbs"
        if (kontrol_mota_ == "nbs") {
            sub_yaw_ = this->create_subscription<std_msgs::msg::Int32>(
                "yaw_angelua", 10,
                std::bind(&FuzzyControlNode::yaw_callback, this, _1));
        }

        // Establecer factor según el tipo de control (para nombre del CSV)
        if (kontrol_mota_ == "nbs") {
            factor_ = 2.5;
        } else if (kontrol_mota_ == "npg") {
            factor_ = 0.4;
        } else {
            factor_ = 1.0; // "nag" y resto por defecto
        }

        // Inicializar CSV si está activado
        if (seinalea_gorde_) {
            csv_file_name_ = "registro_" + kontrol_mota_ + "_factor_" + std::to_string(factor_) + ".csv";
            csv_file_.open(csv_file_name_, std::ios::out);
            if (!csv_file_.is_open()) {
                RCLCPP_WARN(this->get_logger(), "No se pudo abrir el archivo CSV: %s", csv_file_name_.c_str());
            } else {
                csv_file_ << "timestamp,kontrol_mota,factor,error_traj,delta_v,yaw,distancia\n";
            }
        }
    }

    ~FuzzyControlNode() override {
        if (csv_file_.is_open()) {
            csv_file_.flush();
            csv_file_.close();
        }
    }

private:
    void range_callback(const sensor_msgs::msg::Range::SharedPtr msg) {
        ultrasoinu_distantzia_ = msg->range;
    }

    void yaw_callback(const std_msgs::msg::Int32::SharedPtr msg) {
        yaw_angle_ = msg->data;
        if (!yaw_initialized_) {
            yaw_offset_ = yaw_angle_;
            yaw_initialized_ = true;
            RCLCPP_INFO(this->get_logger(), "Offset yaw=%d", yaw_offset_);
        }
    }

    void encoder_callback(const mezuak::msg::MugimenduKodetzaileak::SharedPtr msg) {
        if (!ultrasoinu_distantzia_.has_value()) return;

        if (ultrasoinu_distantzia_.value() <= eten_distantzia_) {
            auto stop_twist = geometry_msgs::msg::Twist();
            pub_->publish(stop_twist);
            RCLCPP_INFO(this->get_logger(), "Objeto cercano (%.2f m). Robot detenido.",
                        ultrasoinu_distantzia_.value());
            return;
        }

        double e_traj = 0.0;
        double local_factor = 1.0;

        if (kontrol_mota_ == "nag") { // norabide abiadura geometrikoa
            double v_izq = static_cast<double>(msg->abiadurak[0]);
            double v_der = static_cast<double>(msg->abiadurak[1]);

            static rclcpp::Time last_time = this->now();
            rclcpp::Time current_time = this->now();
            double dt = (current_time - last_time).seconds();
            last_time = current_time;

            trajectory_error_.update(v_izq, v_der, dt);
            e_traj = trajectory_error_.getErrorPct();
            local_factor = 1.0;

            RCLCPP_INFO(this->get_logger(),
                "[ABIADURA] Vel izq=%.2f, der=%.2f | e_traj=%.2f%% | Dist=%.2f",
                v_izq, v_der, e_traj, ultrasoinu_distantzia_.value());

        } else if (kontrol_mota_ == "npg") { // norabide posizio geometrikoa
            double pos_izq = static_cast<double>(msg->graduak[0]);
            double pos_der = static_cast<double>(msg->graduak[1]);

            trajectory_error_.updateFromPosition(pos_izq, pos_der);
            e_traj = trajectory_error_.getErrorPctPosition();
            local_factor = 0.4;

            RCLCPP_INFO(this->get_logger(),
                "[POSIZIOA] Pos izq=%.2f, der=%.2f | e_traj=%.2f%% | Dist=%.2f",
                pos_izq, pos_der, e_traj, ultrasoinu_distantzia_.value());

        } else if (kontrol_mota_ == "nbs") { // norabide biraketa sentsorea
            if (!yaw_initialized_) return;

            double error = (yaw_angle_ - yaw_offset_);
            e_traj = (error * 100.0 / 360.0);
            local_factor = 2.5;

            RCLCPP_INFO(this->get_logger(),
                "[NBS] yaw=%d | e_traj=%.2f%% | Dist=%.2f",
                yaw_angle_, e_traj, ultrasoinu_distantzia_.value());
        } else {
            // Modo "abiadura" u otros: sin cálculo específico, mantener factor por defecto
            local_factor = 1.0;
        }

        // inferencia fuzzy sobre el error de trayectoria
        double delta_v = fuzzy_.infer_delta_v(e_traj) * local_factor;

        RCLCPP_INFO(this->get_logger(), "[DELTA] %.2f", delta_v);

        auto twist = geometry_msgs::msg::Twist();
        twist.linear.x = abiadura_;
        twist.angular.z = (delta_v / 100.0) * abiadura_;
        pub_->publish(twist);

        // Guardar en CSV
        if (seinalea_gorde_ && csv_file_.is_open()) {
            auto ts = std::chrono::system_clock::now().time_since_epoch();
            double timestamp = std::chrono::duration<double>(ts).count();
            csv_file_ << timestamp << ","
                      << kontrol_mota_ << ","
                      << local_factor << ","
                      << e_traj << ","
                      << delta_v << ","
                      << yaw_angle_ << ","
                      << ultrasoinu_distantzia_.value() << "\n";
        }

        // Publicar datos de entrenamiento si aplica
        if (kontrol_mota_ == "nbs" && ikas_modua_ == "True"){
            auto sample = mezuak::msg::IkasDatuak();
            sample.pos_izq = msg->graduak[0];
            sample.pos_der = msg->graduak[1];
            sample.vel_izq = msg->abiadurak[0];
            sample.vel_der = msg->abiadurak[1];
            sample.yaw = yaw_angle_;
            sample.error_traj = e_traj;
            sample.delta_v = delta_v;
            sample.dist_restante = ultrasoinu_distantzia_.value() - eten_distantzia_;
            pub_training_->publish(sample);
        }
    }

    // Subscripciones y publicadores
    rclcpp::Subscription<mezuak::msg::MugimenduKodetzaileak>::SharedPtr sub_encoders_;
    rclcpp::Subscription<sensor_msgs::msg::Range>::SharedPtr sub_range_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr pub_;
    rclcpp::Publisher<mezuak::msg::IkasDatuak>::SharedPtr pub_training_;
    rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr sub_yaw_;

    // Motor difuso y error de trayectoria
    FuzzyEngine fuzzy_;
    TrajectoryError trajectory_error_;

    // Parámetros y estado
    double abiadura_;
    double eten_distantzia_;
    std::string kontrol_mota_, ikas_modua_;
    std::optional<double> ultrasoinu_distantzia_;

    // Yaw sensor
    int yaw_angle_ = 0;
    int yaw_offset_ = 0;
    bool yaw_initialized_ = false;

    // CSV
    bool seinalea_gorde_ = true;
    std::string csv_file_name_;
    std::ofstream csv_file_;
    double factor_ = 1.0;
};

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<FuzzyControlNode>());
    rclcpp::shutdown();
    return 0;
}
