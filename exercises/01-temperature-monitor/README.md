# 01 — Sıcaklık eşik kontrolü

Bu bağımsız alıştırmada hayalî bir sensörün sıcaklık değerini değerlendirip terminale durum yazdıracaksın. Duke kursunun bir ödev çözümü değildir. Donanım gerekmez; C17 ve GCC ile bilgisayarında çalışır.

## Öğrenme hedefi

`int`, `const`, `printf`, karşılaştırmalar, `if / else if / else`, `for` ve sayaç kullanımı. Diziler, işaretçiler, kullanıcı girdisi ve mikrodenetleyici kütüphaneleri sonraki çalışmalara bırakıldı.

## Dosyalar

| Dosya | Kullanımı |
| --- | --- |
| `src/main.c` | Derlenebilir başlangıç kodu; TODO kısımlarını sen tamamlayacaksın. |
| `ALGORITHM.md` | İngilizce algoritma ve pseudocode. |
| `solution/main.c` | İki aşamanın tamamlanmış referans çözümü; önce kendin dene. |

## Görev

Önce `ALGORITHM.md` dosyasındaki ilk aşamayı oku. Başlangıç kodunda `temperature_c = 25` değerini aşağıdaki kurallarla sınıflandır. Her ölçüm için yalnızca bir durum yazdır.

| Sıcaklık | Terminal çıktısı |
| --- | --- |
| 40 °C altı | `NORMAL` |
| 40 °C dahil, 60 °C altı | `WARNING` |
| 60 °C ve üzeri | `ALARM` |

Eşikler yalnızca bu alıştırmanın örnek değerleridir. Önce yüksek eşiği kontrol etmeyi dene: 65 değeri hem 40 hem 60 eşiğini aşar; kontrol sırası bu nedenle önemlidir.

İlk aşama çalıştıktan sonra ikinci aşamaya geç. `for` döngüsüyle 25, 35, 45, 55 ve 65 °C değerlerini sırayla işle. Başlangıçtaki tek ölçüm değişkenini döngü değişkenine dönüştür. Döngüden önce sıfırlanan `alarm_count` değişkenini yalnızca ALARM durumunda artır ve döngü bittikten sonra yazdır. Eşik değişkenlerini karşılaştırmalarda kullan.

## Derleme ve çalıştırma

Terminali deponun ana klasöründe aç. GCC kuruluysa aşağıdaki komutlar yeterlidir:

```bash
mkdir -p build
gcc -std=c17 -Wall -Wextra -Wpedantic exercises/01-temperature-monitor/src/main.c -o build/temperature-monitor
./build/temperature-monitor
```

`gcc` kaynak kodunu çalıştırılabilir dosyaya dönüştürür. `-std=c17` dil standardını, `-Wall -Wextra -Wpedantic` uyarıları, `-o` çıktı dosyasının adını belirler. `./` bulunduğun klasöre göre çalıştırılacak dosyayı gösterir. `build/` derleme çıktıları içindir ve Git tarafından yok sayılır. Başlangıç kodu ilk derlemede ölçüm ve eşikleri yazdırır; sınıflandırma senin görevin.

Referans çözümü ayrı bir program olarak derleyebilirsin:

```bash
gcc -std=c17 -Wall -Wextra -Wpedantic exercises/01-temperature-monitor/solution/main.c -o build/temperature-monitor-solution
./build/temperature-monitor-solution
```

## Beklenen sonuç ve kontrol

İlk aşamada ölçüm değerini aşağıdaki değerlerle tek tek değiştir, her değişiklikten sonra tekrar derleyip çalıştır:

| Değer (°C) | Beklenen durum |
| --- | --- |
| -5 | `NORMAL` |
| 39 | `NORMAL` |
| 40 | `WARNING` |
| 59 | `WARNING` |
| 60 | `ALARM` |
| 65 | `ALARM` |

İkinci aşamanın referans çıktısı:

```text
Temperature: 25 C | Status: NORMAL
Temperature: 35 C | Status: NORMAL
Temperature: 45 C | Status: WARNING
Temperature: 55 C | Status: WARNING
Temperature: 65 C | Status: ALARM
Alarm count: 1
```

Başarı ölçütü: uyarısız derleme, sınır değerlerinde doğru sınıflandırma, tam beş ölçüm ve bir alarm. Ayrıca tamamladığın döngüde başlangıç/bitiş değerlerini geçici olarak 20/30 yapıp sıfır alarmı, 60/80 yapıp üç alarmı kontrol et. Sonra 25/65 ayarına dön.

## Syntax nasıl okunur?

- `#include <stdio.h>` terminale yazdırmak için kullanılan standart kütüphane bildirimlerini getirir.
- `int main(void)` programın giriş noktasıdır; `return 0;` başarılı bitiş bildirir.
- `int` tam sayı saklar; `const int` bu program içinde değiştirmeyeceğin bir tam sayıyı belirtir.
- `=` atamadır; `>=` karşılaştırmadır. C'de eşitlik karşılaştırması `==` ile yapılır.
- `printf` içindeki `%d` bir `int` değerini, `\n` yeni satırı temsil eder.
- `for` parantezindeki üç bölüm başlangıç, devam koşulu ve her tur sonundaki güncellemedir.
- `alarm_count++` sayacı bir artırır. Sayaç döngünün içinde sıfırlanırsa toplam birikmez.
- `{ }` bir kod bloğunu sınırlar; bildirim ve basit ifadelerin sonunda `;` bulunur.

## Embedded sistemlerle bağlantısı

Buradaki değerler sentetiktir: döngü gerçek zamanlı ölçüm veya bir saniyelik bekleme yapmaz. STM32/ESP32 projesinde sıcaklık değeri bir sensör sürücüsünden gelir; karar mantığı aynı şekilde kullanılabilir. Terminal çıktısının yerini daha sonra UART mesajı, ekran veya GPIO çıkışı alabilir. Bu dosya bilgisayar programıdır; karta yüklenebilir firmware değildir. Sensörün çözünürlüğü, hata durumları, zamanlama ve eşik çevresinde kararsızlığı azaltan histerezis ileride ayrı konular olacak.

## Kendi notun

Çalışmayı tamamlayınca bu klasöre `NOTES.md` ekleyip Türkçe olarak hangi koşulu neden önce yazdığını, 40 ve 60 değerlerinde ne olduğunu ve döngü sayacının nasıl değiştiğini anlat. Ardından yaptığın değişiklikleri Git ile kaydet. Bu, yalnızca hazır çözümü çalıştırmaktan daha iyi bir öğrenme kaydı oluşturur.
