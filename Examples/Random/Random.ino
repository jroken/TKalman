#include <TKalman.h>

TKalman kalman; // Varsayılan değerler ayarlama yapmak için lütfen github sayfasını inceleyin https://github.com/jroken/TKalman

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("TKalman Kalman Filtresi Örneği");
}

void loop() {
  double measurement = random(100) / 10.0;

  // Kalman filtresini ölçüm ile güncelle
  double filtered_value = kalman.update(measurement);

  Serial.print("Ölçüm: ");
  Serial.print(measurement);
  Serial.print(" | Filtrelenmiş Değer: ");
  Serial.println(filtered_value);

  delay(500);
}
