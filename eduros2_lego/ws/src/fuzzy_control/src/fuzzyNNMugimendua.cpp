#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "mezuak/msg/mugimendu_kodetzaileak.hpp"
#include "sensor_msgs/msg/range.hpp"
#include "std_msgs/msg/int32.hpp"

#include <torch/script.h> // LibTorch
#include <optional>
#include <vector>

using std::placeholders::_1;

class NNControlNode : public rclcpp::Node {
public:
    NNControlNode() : Node("nn_control_node") {
        std::string path = "/home/javierac/eduros2_lego/ws/install/ikas_datuak/model.pt";

        /*#include "ament_index_cpp/get_package_share_directory.hpp"
        std::string package_share = ament_index_cpp::get_package_share_directory("fuzzy_control");
        std::string path = package_share + "/models/model.pt";
        module_ = torch::jit::load(path);*/

        this->declare_parameter<double>("eten_distantzia", 0.15);
        eten_distantzia_ = this->get_parameter("eten_distantzia").as_double();

        // Suscripciones
        sub_encoders_ = this->create_subscription<mezuak::msg::MugimenduKodetzaileak>(
            "/kodetzaileak", 10,
            std::bind(&NNControlNode::encoder_callback, this, _1));

        sub_range_ = this->create_subscription<sensor_msgs::msg::Range>(
            "distantzia", 10,
            std::bind(&NNControlNode::range_callback, this, _1));

        sub_yaw_ = this->create_subscription<std_msgs::msg::Int32>(
            "yaw_angelua", 10,
            std::bind(&NNControlNode::yaw_callback, this, _1));

        pub_cmd_vel_ = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);

        // Cargar el modelo TorchScript
        try {
            module_ = torch::jit::load(path);
            RCLCPP_INFO(this->get_logger(), "Modelo cargado correctamente.");
        } catch (const c10::Error& e) {
            RCLCPP_ERROR(this->get_logger(), "Error cargando el modelo: %s", e.what());
        }
    }

private:
    void range_callback(const sensor_msgs::msg::Range::SharedPtr msg) {
        ultrasoinu_distantzia_ = msg->range;
    }

    void yaw_callback(const std_msgs::msg::Int32::SharedPtr msg) {
        yaw_angle_ = msg->data;
    }

    void encoder_callback(const mezuak::msg::MugimenduKodetzaileak::SharedPtr msg) {
        if (ultrasoinu_distantzia_.value() <= eten_distantzia_) {
            auto stop_twist = geometry_msgs::msg::Twist();
            pub_cmd_vel_->publish(stop_twist);
            RCLCPP_INFO(this->get_logger(), "Objeto cercano (%.2f m). Robot detenido.",
                        ultrasoinu_distantzia_.value());
            return;
        }
        
        if (!ultrasoinu_distantzia_.has_value()) return;
        if (!module_) return;

        // Preparar entrada para la red (7 features)
        std::vector<float> input_data = {
            static_cast<float>(msg->graduak[0]),   // pos_izq
            static_cast<float>(msg->graduak[1]),   // pos_der
            static_cast<float>(msg->abiadurak[0]), // vel_izq
            static_cast<float>(msg->abiadurak[1]), // vel_der
            static_cast<float>(yaw_angle_),        // yaw
            static_cast<float>(0.0),               // error_traj (si lo calculas aparte)
            static_cast<float>(ultrasoinu_distantzia_.value()) // dist_restante
        };

        torch::Tensor input = torch::tensor(input_data).reshape({1,7});
        torch::Tensor output = module_->forward({input}).toTensor();
        double delta_v = output.item<double>();

        // Publicar cmd_vel
        auto twist = geometry_msgs::msg::Twist();
        twist.linear.x = 25.0; // velocidad base
        twist.angular.z = (delta_v / 100.0) * twist.linear.x;
        pub_cmd_vel_->publish(twist);
    }

    rclcpp::Subscription<mezuak::msg::MugimenduKodetzaileak>::SharedPtr sub_encoders_;
    rclcpp::Subscription<sensor_msgs::msg::Range>::SharedPtr sub_range_;
    rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr sub_yaw_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr pub_cmd_vel_;

    std::optional<double> ultrasoinu_distantzia_;
    double eten_distantzia_;
    int yaw_angle_ = 0;

    std::optional<torch::jit::script::Module> module_;
};

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<NNControlNode>());
    rclcpp::shutdown();
    return 0;
}
