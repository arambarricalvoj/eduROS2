#pragma once
#include <cmath>

inline double wrap_to_pi(double x) {
    while (x > M_PI)  x -= 2.0 * M_PI;
    while (x < -M_PI) x += 2.0 * M_PI;
    return x;
}


class TrajectoryError {
public:
    TrajectoryError(double wheel_diameter, double axle_track)
        : wheel_diameter_(wheel_diameter),
          axle_track_(axle_track),
          accumulated_error_(0.0),
          last_left_deg_(0.0),
          last_right_deg_(0.0),
          offset_left_deg_(0.0),
          offset_right_deg_(0.0),
          offsets_initialized_(false) {}

    // --- Actualización con VELOCIDADES (deg/s) ---
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

    // --- Inicializa offsets con la posición actual de los encoders ---
    void setOffsets(double pos_left_deg, double pos_right_deg) {
        offset_left_deg_ = pos_left_deg;
        offset_right_deg_ = pos_right_deg;
        last_left_deg_ = 0.0;
        last_right_deg_ = 0.0;
        offsets_initialized_ = true;
    }

    // --- Actualización con POSICIONES absolutas (deg) ---
    void updateFromPosition(double pos_left_deg, double pos_right_deg) {
        if (!offsets_initialized_) {
            // Si no se han inicializado offsets, los fijamos en la primera llamada
            setOffsets(pos_left_deg, pos_right_deg);
            return;
        }

        // Aplicar offset → posiciones relativas desde el arranque
        double adj_left = pos_left_deg - offset_left_deg_;
        double adj_right = pos_right_deg - offset_right_deg_;

        // Diferencia de incremento desde la última lectura
        double delta_left_deg = adj_left - last_left_deg_;
        double delta_right_deg = adj_right - last_right_deg_;

        last_left_deg_ = adj_left;
        last_right_deg_ = adj_right;

        // Convertir a radianes
        double delta_left_rad = delta_left_deg * M_PI / 180.0;
        double delta_right_rad = delta_right_deg * M_PI / 180.0;

        // Distancia lineal recorrida por cada rueda
        double d_left = delta_left_rad * (wheel_diameter_ / 2.0);
        double d_right = delta_right_rad * (wheel_diameter_ / 2.0);

        // Diferencia de desplazamiento → yaw incremental
        double yaw_delta = (d_right - d_left) / axle_track_;
        accumulated_error_ += yaw_delta;
    }

    // --- Getters ---
    double getError() const { return accumulated_error_; }

    // Error acumulado normalizado en porcentaje (±360° = ±100%)
    double getErrorPct() const {
        double max_error_rad = 2.0 * M_PI; // 360°
        return (accumulated_error_ / max_error_rad) * 100.0;
    }

    double getErrorPctPosition() const {
        double wrapped = wrap_to_pi(accumulated_error_);
        return (wrapped / M_PI) * 100.0; // ahora siempre entre -100 y +100
    }


    // Reinicia el acumulador y offsets
    void reset() {
        accumulated_error_ = 0.0;
        last_left_deg_ = 0.0;
        last_right_deg_ = 0.0;
        offset_left_deg_ = 0.0;
        offset_right_deg_ = 0.0;
        offsets_initialized_ = false;
    }

private:
    double wheel_diameter_;
    double axle_track_;
    double accumulated_error_;

    // Para cálculo con posiciones
    double last_left_deg_;
    double last_right_deg_;
    double offset_left_deg_;
    double offset_right_deg_;
    bool offsets_initialized_;
};
