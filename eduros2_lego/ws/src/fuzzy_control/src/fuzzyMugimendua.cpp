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
    std::deque<double> buffer_izq_;
    std::deque<double> buffer_der_;
    const size_t N = 5;  // tamaño de ventana
    double error_acumulado_ = 0.0;

    void range_callback(const sensor_msgs::msg::Range::SharedPtr msg) {
        ultrasoinu_distantzia_ = msg->range;
    }

    double filtrar(std::deque<double>& buffer, double nueva) {
    buffer.push_back(nueva);
    if (buffer.size() > N) buffer.pop_front();
    double suma = 0.0;
    for (auto v : buffer) suma += v;
    return suma / buffer.size();  // media móvil
    }

    // miembros privados
double ultima_correccion_ = 0.0;
bool corrigiendo_ = false;

void encoder_callback(const mezuak::msg::MugimenduKodetzaileak::SharedPtr msg) {
    if (!ultrasoinu_distantzia_.has_value()) return;
    if (ultrasoinu_distantzia_.value() <= eten_distantzia_) {
        pub_->publish(geometry_msgs::msg::Twist());
        return;
    }

    double v_izq = filtrar(buffer_izq_, static_cast<double>(msg->abiadurak[0]));
    double v_der = filtrar(buffer_der_, static_cast<double>(msg->abiadurak[1]));
    double e_v = std::abs(v_izq) - std::abs(v_der);

    // Histéresis
    const double umbral_alto = 8.0;
    const double umbral_bajo = 3.0;

    if (!corrigiendo_ && std::abs(e_v) > umbral_alto) {
        corrigiendo_ = true;
    } else if (corrigiendo_ && std::abs(e_v) < umbral_bajo) {
        corrigiendo_ = false;
    }

    // Acumulador integral
    if (corrigiendo_) {
        error_acumulado_ += e_v;
        error_acumulado_ = std::clamp(error_acumulado_, -100.0, 100.0);
        double delta_v = fuzzy_.infer_delta_v(error_acumulado_);
        ultima_correccion_ = (delta_v / 200.0) * abiadura_;
    }

    geometry_msgs::msg::Twist twist;
    twist.linear.x = abiadura_;
    twist.angular.z = ultima_correccion_;  // mantener corrección hasta que se libere

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
