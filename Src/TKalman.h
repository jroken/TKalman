#ifndef TKALMAN_H
#define TKALMAN_H

class TKalman {
public:
    // Kalman filtresi için varsayılan parametreler.
    TKalman(double process_variance = 0.0001, double measurement_variance = 0.1, 
            double initial_estimate = 0.0, double initial_error = 1.0);
    
    // Ölçüm verisi ile Kalman filtresini güncelle
    double update(double measurement);
    
    // Parametreleri değiştirmek için fonksiyonlar
    void setProcessVariance(double var);
    void setMeasurementVariance(double var);
    void reset(double new_estimate = 0.0, double new_error = 1.0);

private:
    double estimate;
    double error;
    double process_variance;
    double measurement_variance;
};

#endif // TKALMAN_H
