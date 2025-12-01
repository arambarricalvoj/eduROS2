#include "rclcpp/rclcpp.hpp"
#include "mezuak/msg/ikas_datuak.hpp"
#include <fstream>
#include <string>
#include <filesystem>   // para crear directorios

using std::placeholders::_1;
namespace fs = std::filesystem;

class LoggerNode : public rclcpp::Node {
public:
    LoggerNode() : Node("logger_node") {
        // Suscripción al tópico de datos de entrenamiento
        sub_ = this->create_subscription<mezuak::msg::IkasDatuak>(
            "ikasteko_datuak", 10,
            std::bind(&LoggerNode::callback, this, _1));

        // Ruta del archivo CSV
        std::string path = "/home/javierac/eduros2_lego/ws/install/ikas_datuak/dataset.csv";

        // Crear directorio si no existe
        fs::create_directories(fs::path(path).parent_path());

        // Abrir archivo CSV
        file_.open(path, std::ios::out);
        if (!file_.is_open()) {
            RCLCPP_ERROR(this->get_logger(), "No se pudo abrir %s", path.c_str());
        } else {
            // Cabecera del CSV
            file_ << "pos_izq,pos_der,vel_izq,vel_der,yaw,error_traj,delta_v,dist_restante\n";
            RCLCPP_INFO(this->get_logger(), "Archivo CSV abierto en %s", path.c_str());
        }
    }

    ~LoggerNode() {
        if (file_.is_open()) {
            file_.close();
        }
    }

private:
    void callback(const mezuak::msg::IkasDatuak::SharedPtr msg) {
        if (!file_.is_open()) return;

        file_ << msg->pos_izq << ","
              << msg->pos_der << ","
              << msg->vel_izq << ","
              << msg->vel_der << ","
              << msg->yaw << ","
              << msg->error_traj << ","
              << msg->delta_v << ","
              << msg->dist_restante << "\n";
    }

    rclcpp::Subscription<mezuak::msg::IkasDatuak>::SharedPtr sub_;
    std::ofstream file_;
};

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<LoggerNode>());
    rclcpp::shutdown();
    return 0;
}
