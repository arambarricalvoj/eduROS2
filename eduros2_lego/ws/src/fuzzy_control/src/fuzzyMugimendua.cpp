#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "mezuak/msg/mugimendu_kodetzaileak.hpp"
#include "sensor_msgs/msg/range.hpp"
#include "fuzzy_control/fuzzyEngine.hpp"

using std::placeholders::_1;

class FuzzyControlNode : public rclcpp::Node {
public:
    FuzzyControlNode() : Node("fuzzy_control_node") {
        // Suscripción a los encoders
        sub_encoders_ = this->create_subscription<mezuak::msg::MugimenduKodetzaileak>(
            "/kodetzaileak", 10,
            std::bind(&FuzzyControlNode::encoder_callback, this, _1));

        // Suscripción al sensor ultrasónico
        sub_range_ = this->create_subscription<sensor_msgs::msg::Range>(
            "distantzia", 10,
            std::bind(&FuzzyControlNode::range_callback, this, _1));

        // Publicador en cmd_vel
        pub_ = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);

        // Parámetros
        this->declare_parameter<double>("abiadura", 25.0);
        this->declare_parameter<double>("eten_distantzia", 0.15);

        abiadura_ = this->get_parameter("abiadura").as_double();
        eten_distantzia_ = this->get_parameter("eten_distantzia").as_double();
    }

private:
    void range_callback(const sensor_msgs::msg::Range::SharedPtr msg) {
        ultrasoinu_distantzia_ = msg->range;
    }

    void encoder_callback(const mezuak::msg::MugimenduKodetzaileak::SharedPtr msg) {
        if (!ultrasoinu_distantzia_.has_value()) {
            // No tenemos aún medida de distancia
            return;
        }

        if (ultrasoinu_distantzia_.value() <= eten_distantzia_) {
            // Objeto demasiado cerca → detener
            auto stop_twist = geometry_msgs::msg::Twist();
            pub_->publish(stop_twist);
            RCLCPP_INFO(this->get_logger(), "Objeto cercano (%.2f m). Robot detenido.",
                        ultrasoinu_distantzia_.value());
            return;
        }

        // Calcular corrección difusa
        double v_izq = static_cast<double>(msg->abiadurak[0]);
        double v_der = static_cast<double>(msg->abiadurak[1]);

        double e_v = std::abs(v_izq) - std::abs(v_der);
        double delta_v = fuzzy_.infer_delta_v(e_v);

        RCLCPP_INFO(this->get_logger(),
            "Vel izq=%.2f, der=%.2f | e_v=%.2f | Delta=%.2f | Dist=%.2f",
            v_izq, v_der, e_v, delta_v, ultrasoinu_distantzia_.value());

        // Construir Twist
        auto twist = geometry_msgs::msg::Twist();
        twist.linear.x = abiadura_;                       // velocidad base
        twist.angular.z = (delta_v / 100.0) * abiadura_;  // corrección proporcional

        pub_->publish(twist);
    }

    // Subscripciones y publicador
    rclcpp::Subscription<mezuak::msg::MugimenduKodetzaileak>::SharedPtr sub_encoders_;
    rclcpp::Subscription<sensor_msgs::msg::Range>::SharedPtr sub_range_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr pub_;

    // Motor difuso
    FuzzyEngine fuzzy_;

    // Parámetros
    double abiadura_;
    double eten_distantzia_;
    std::optional<double> ultrasoinu_distantzia_;
};

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<FuzzyControlNode>());
    rclcpp::shutdown();
    return 0;
}
