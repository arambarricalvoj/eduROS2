#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "mezuak/msg/mugimendu_kodetzaileak.hpp"
#include "sensor_msgs/msg/range.hpp"
#include "std_msgs/msg/int32.hpp"
#include "fuzzy_control/fuzzyEngine.hpp"
#include "fuzzy_control/trajectoryError.hpp"

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
        // valores posibles: "abiadura", "posizioa", "nbs"

        abiadura_ = this->get_parameter("abiadura").as_double();
        eten_distantzia_ = this->get_parameter("eten_distantzia").as_double();
        kontrol_mota_ = this->get_parameter("kontrol_mota").as_string();

        // Suscripciones comunes
        sub_encoders_ = this->create_subscription<mezuak::msg::MugimenduKodetzaileak>(
            "/kodetzaileak", 10,
            std::bind(&FuzzyControlNode::encoder_callback, this, _1));

        sub_range_ = this->create_subscription<sensor_msgs::msg::Range>(
            "distantzia", 10,
            std::bind(&FuzzyControlNode::range_callback, this, _1));

        pub_ = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);

        // Suscripción al yaw solo si kontrol_mota == "nbs"
        if (kontrol_mota_ == "nbs") {
            sub_yaw_ = this->create_subscription<std_msgs::msg::Int32>(
                "yaw_angelua", 10,
                std::bind(&FuzzyControlNode::yaw_callback, this, _1));
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
        double factor = 1.0;

        if (kontrol_mota_ == "nag") { // norabide abiadura geometrikoa
            // --- Lógica con velocidades ---
            double v_izq = static_cast<double>(msg->abiadurak[0]);
            double v_der = static_cast<double>(msg->abiadurak[1]);

            static rclcpp::Time last_time = this->now();
            rclcpp::Time current_time = this->now();
            double dt = (current_time - last_time).seconds();
            last_time = current_time;

            trajectory_error_.update(v_izq, v_der, dt);
            e_traj = trajectory_error_.getErrorPct();

            RCLCPP_INFO(this->get_logger(),
                "[ABIADURA] Vel izq=%.2f, der=%.2f | e_traj=%.2f%% | Dist=%.2f",
                v_izq, v_der, e_traj, ultrasoinu_distantzia_.value());

        } else if (kontrol_mota_ == "npg") { // norabide posizio geometrikoa
            factor = 0.4;
            // --- Lógica con posiciones ---
            double pos_izq = static_cast<double>(msg->graduak[0]);
            double pos_der = static_cast<double>(msg->graduak[1]);

            trajectory_error_.updateFromPosition(pos_izq, pos_der);
            e_traj = trajectory_error_.getErrorPctPosition();

            RCLCPP_INFO(this->get_logger(),
                "[POSIZIOA] Pos izq=%.2f, der=%.2f | e_traj=%.2f%% | Dist=%.2f",
                pos_izq, pos_der, e_traj, ultrasoinu_distantzia_.value());

        } else if (kontrol_mota_ == "nbs") { // norabide biraketa sentsorea
            factor = 2.5;
            if (!yaw_initialized_) return;

            double error = (yaw_angle_ - yaw_offset_);
            e_traj = (error * 100.0 / 360.0);

            RCLCPP_INFO(this->get_logger(),
                "[NBS] yaw=%d | e_traj=%.2f%% | Dist=%.2f",
                yaw_angle_, e_traj, ultrasoinu_distantzia_.value());
        }

        // inferencia fuzzy sobre el error de trayectoria
        double delta_v = fuzzy_.infer_delta_v(e_traj) * factor;

        RCLCPP_INFO(this->get_logger(),
                "[DELTA] %.2f",
                delta_v);

        auto twist = geometry_msgs::msg::Twist();
        twist.linear.x = abiadura_;
        twist.angular.z = (delta_v / 100.0) * abiadura_;
        pub_->publish(twist);
    }

    // Subscripciones y publicador
    rclcpp::Subscription<mezuak::msg::MugimenduKodetzaileak>::SharedPtr sub_encoders_;
    rclcpp::Subscription<sensor_msgs::msg::Range>::SharedPtr sub_range_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr pub_;
    rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr sub_yaw_;

    // Motor difuso y error de trayectoria
    FuzzyEngine fuzzy_;
    TrajectoryError trajectory_error_;

    // Parámetros
    double abiadura_;
    double eten_distantzia_;
    std::string kontrol_mota_;
    std::optional<double> ultrasoinu_distantzia_;

    // Yaw sensor
    int yaw_angle_ = 0;
    int yaw_offset_ = 0;
    bool yaw_initialized_ = false;
};

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<FuzzyControlNode>());
    rclcpp::shutdown();
    return 0;
}
