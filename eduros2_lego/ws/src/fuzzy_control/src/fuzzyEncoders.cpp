/*#include "rclcpp/rclcpp.hpp"
#include "mezuak/msg/mugimendu_kodetzaileak.hpp"
#include "fuzzy_control/fuzzyEngine.hpp"

using std::placeholders::_1;

class FuzzyControlNode : public rclcpp::Node {
public:
    FuzzyControlNode() : Node("fuzzy_control_node") {
        sub_ = this->create_subscription<mezuak::msg::MugimenduKodetzaileak>(
            "/kodetzaileak", 10,
            std::bind(&FuzzyControlNode::encoder_callback, this, _1));
    }

private:
    void encoder_callback(const mezuak::msg::MugimenduKodetzaileak::SharedPtr msg) {
        
        RCLCPP_INFO(this->get_logger(), 
                    "graduak: [%d, %d], abiadurak: [%d, %d]",
                    static_cast<int>(msg->graduak[0]), 
                    static_cast<int>(msg->graduak[1]), 
                    static_cast<int>(msg->abiadurak[0]), 
                    static_cast<int>(msg->abiadurak[1]) 
        );

        double v_izq = static_cast<int>(msg->abiadurak[0]);
        double v_der = static_cast<int>(msg->abiadurak[1]);

        double e_v = v_izq - v_der;
        double delta_v = fuzzy_.infer_delta_v(e_v);

        RCLCPP_INFO(this->get_logger(),
            "Velocidades -> izq: %.2f, der: %.2f | e_v: %.2f | Delta_v: %.2f",
            v_izq, v_der, e_v, delta_v);
    }

    rclcpp::Subscription<mezuak::msg::MugimenduKodetzaileak>::SharedPtr sub_;
    FuzzyEngine fuzzy_;
};

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<FuzzyControlNode>());
    rclcpp::shutdown();
    return 0;
}*/

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "mezuak/msg/mugimendu_kodetzaileak.hpp"
#include "fuzzy_control/fuzzyEngine.hpp"

using std::placeholders::_1;

class FuzzyControlNode : public rclcpp::Node {
public:
    FuzzyControlNode() : Node("fuzzy_control_node") {
        // Suscripción a los encoders
        sub_ = this->create_subscription<mezuak::msg::MugimenduKodetzaileak>(
            "/kodetzaileak", 10,
            std::bind(&FuzzyControlNode::encoder_callback, this, _1));

        // Publicador en cmd_vel
        pub_ = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);

        // Parámetro de velocidad base
        this->declare_parameter<double>("abiadura", 25.0);
        abiadura_ = this->get_parameter("abiadura").as_double();
    }

private:
    void encoder_callback(const mezuak::msg::MugimenduKodetzaileak::SharedPtr msg) {
        double v_izq = static_cast<double>(msg->abiadurak[0]);
        double v_der = static_cast<double>(msg->abiadurak[1]);

        double e_v = v_izq - v_der;
        double delta_v = fuzzy_.infer_delta_v(e_v);

        RCLCPP_INFO(this->get_logger(),
            "Velocidades -> izq: %.2f, der: %.2f | e_v: %.2f | Delta_v: %.2f",
            v_izq, v_der, e_v, delta_v);

        // Construir Twist
        auto twist = geometry_msgs::msg::Twist();
        twist.linear.x = abiadura_;                       // velocidad base
        twist.angular.z = (delta_v / 100.0) * abiadura_;  // corrección proporcional

        pub_->publish(twist);
    }

    rclcpp::Subscription<mezuak::msg::MugimenduKodetzaileak>::SharedPtr sub_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr pub_;
    FuzzyEngine fuzzy_;
    double abiadura_;
};

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<FuzzyControlNode>());
    rclcpp::shutdown();
    return 0;
}

