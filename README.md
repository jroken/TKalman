
# TKalman Kütüphanesi

**TKalman**, basit bir Kalman filtresi implementasyonu sağlayan bir Arduino kütüphanesidir. Bu kütüphane, ölçümlerden gelen verilerin gürültüsünü filtreleyerek daha doğru tahminler elde etmenizi sağlar. Özellikle, sensör verilerini işlerken kullanabileceğiniz hızlı ve verimli bir çözümdür.

## Özellikler

-   **Basit Kullanım**: Kalman filtresini kolayca kullanabilirsiniz.
-   **Parametre Ayarları**: Process ve Measurement variance gibi parametreleri dinamik olarak değiştirme olanağı.
-   **Minimal Kaynak Kullanımı**: Arduino gibi düşük kaynaklı platformlarda verimli çalışır.

## Kurulum

1.  **Kütüphaneyi İndirin**:
    
    -   Bu kütüphaneyi GitHub'dan [buradan](https://github.com/jroken/TKalman) indirerek Arduino IDE'ye yükleyebilirsiniz.
2.  **Arduino IDE'ye Ekleyin**:
    
    -   Kütüphaneyi Arduino IDE'ye eklemek için, indirdiğiniz dosyayı zip kütüphanesi olarak ekleyin.
3.  **Kütüphaneyi Arduino Projenize Dahil Edin**:
    
    -   Projenize eklemek için `#include <TKalman.h>` ifadesini kullanabilirsiniz.

## Kullanım

### Kalman Filtresi Sınıfı

`TKalman` sınıfı, Kalman filtresinin temel işlevlerini içerir. Sınıf, şu parametrelerle başlatılabilir:

-   `process_variance`: Filtre için süreç varyansı (varsayılan: 0.0001)
-   `measurement_variance`: Ölçüm varyansı (varsayılan: 0.1)
-   `initial_estimate`: Başlangıç tahmini (varsayılan: 0.0)
-   `initial_error`: Başlangıç hata tahmini (varsayılan: 1.0)

### Örnek Kullanım

Aşağıdaki örnek, Kalman filtresinin nasıl kullanılacağını gösterir.


```cpp
#include <TKalman.h>

TKalman kalman; // Varsayılan değerler değiştirmek için https://github.com/jroken/TKalman

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

```



### Parametreleri Değiştirme

Kütüphanede, filtre parametrelerini dinamik olarak değiştirebilirsiniz. Örneğin:


```cpp
kalman.setProcessVariance(0.001); // Process variance'ı güncelle 
kalman.setMeasurementVariance(0.05); // Measurement variance'ı güncelle
```
### Resetleme

Kalman filtresini sıfırlamak için `reset()` fonksiyonu kullanılabilir:

```cpp
kalman.reset(); // Başlangıç değerleriyle sıfırlama
```

### Fonksiyonlar

-   **`update(double measurement)`**: Ölçüm değeri ile Kalman filtresini günceller ve filtrelenmiş değeri döndürür.
    
-   **`setProcessVariance(double var)`**: Süreç varyansını ayarlar.
    
-   **`setMeasurementVariance(double var)`**: Ölçüm varyansını ayarlar.
    
-   **`reset(double new_estimate = 0.0, double new_error = 1.0)`**: Kalman filtresini sıfırlar ve başlangıç tahmini ile hata değerini günceller.
    


## Hata Ayıklama

Eğer Kalman filtresi beklediğiniz gibi çalışmıyorsa:

-   `process_variance` ve `measurement_variance` değerlerini kontrol edin. Bu parametrelerin doğru ayarlanması, filtrelemenin başarısı için çok önemlidir.
-   Ölçüm verilerinizin doğruluğuna dikkat edin. Filtre, doğru verilerle daha etkili çalışır.
