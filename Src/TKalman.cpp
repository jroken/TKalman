#include "TKalman.h"

TKalman::TKalman(double process_variance, double measurement_variance, 
                 double initial_estimate, double initial_error)
    : process_variance(process_variance), measurement_variance(measurement_variance),
      estimate(initial_estimate), error(initial_error) {}

double TKalman::update(double measurement) {
    // Ön tahmin güncellemesi
    error += process_variance;

    // Ölçüm güncellemesi
    double gain = error / (error + measurement_variance);
    estimate = estimate + gain * (measurement - estimate);
    error = (1 - gain) * error;

    return estimate;
}

void TKalman::setProcessVariance(double var) {
    process_variance = var;
}

void TKalman::setMeasurementVariance(double var) {
    measurement_variance = var;
}

void TKalman::reset(double new_estimate, double new_error) {
    estimate = new_estimate;
    error = new_error;
}
