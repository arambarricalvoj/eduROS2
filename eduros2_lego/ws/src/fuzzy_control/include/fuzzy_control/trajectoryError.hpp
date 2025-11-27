// TrajectoryError.hpp
#pragma once
#include <cmath>

class TrajectoryError {
public:
    TrajectoryError(double wheel_diameter, double axle_track)
        : wheel_diameter_(wheel_diameter),
          axle_track_(axle_track),
          accumulated_error_(0.0) {}

    // Actualiza el error de trayectoria con las velocidades de las ruedas (deg/s)
    void update(double v_left_deg_s, double v_right_deg_s, double dt) {
        // Convertir a rad/s
        double w_left = v_left_deg_s * M_PI / 180.0;
        double w_right = v_right_deg_s * M_PI / 180.0;

        // Velocidades lineales de cada rueda
        double v_left = w_left * (wheel_diameter_ / 2.0);
        double v_right = w_right * (wheel_diameter_ / 2.0);

        // Velocidad angular del robot (yaw rate)
        double yaw_rate = (v_right - v_left) / axle_track_;

        // Integrar para obtener error acumulado de trayectoria
        accumulated_error_ += yaw_rate * dt;
    }

    // Devuelve el error acumulado (radianes)
    double getError() const { return accumulated_error_; }

    // Reinicia el acumulador
    void reset() { accumulated_error_ = 0.0; }

private:
    double wheel_diameter_;
    double axle_track_;
    double accumulated_error_;
};
