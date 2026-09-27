# C Foundations

A learning repository for building strong foundations in the C programming language through coursework, independent exercises, and small projects.

I am studying Electrical and Electronics Engineering and currently following the **Duke University Introduction to Programming in C Specialization**. My long-term goal is to apply C and C++ to embedded systems, sensor interfaces, telemetry, and an electronic control panel built around microcontrollers such as the ESP32 or STM32.

## Progression Queue 

- C syntax and program structure
- Variables, expressions, conditionals, and loops
- Functions and decomposition
- Arrays, pointers, and memory
- Compiling, testing, and debugging on Linux
- Preparing for embedded systems programming

## Repo Structure

The structure will grow gradually as I complete new subjects. I'd rather add files only when they represent actual work than creating empty directories in advance.

## Development Environment

- Ubuntu Linux
- Visual Studio Code
- GCC
- Git and GitHub

Programs are compiled locally with warnings enabled:

```bash
gcc -Wall -Wextra -Wpedantic source.c -o program
./program
```

## Academic Integrity

This repository is intended to document my learning and original work. Graded course solutions will not be published when doing so would violate course rules or academic-integrity requirements.

The knowledge developed here will later support projects involving:

- Microcontroller programming
- Sensor data acquisition
- Telemetry and fault logging
- Power-distribution and radar-system control

## License

This repository is licensed under the MIT License.

## İlk uygulama — Sıcaklık eşik kontrolü

[Alıştırmaya başla](exercises/01-temperature-monitor/README.md): değişkenler ve koşullarla tek bir sıcaklığı sınıflandır; ardından döngüyle beş örnek ölçümü işle ve alarmları say. Açıklamalar Türkçe, kod ve algoritma İngilizcedir. Başlangıç kodu ve ayrı referans çözümü vardır; bu kayıt alıştırmanın öğrenci tarafından tamamlandığı anlamına gelmez.

| Konum | İçerik |
| --- | --- |
| `exercises/01-temperature-monitor/` | Görev, algoritma, başlangıç kodu ve referans çözümü |
| `build/` | Yerel derleme çıktıları; Git'e eklenmez |

Derleme komutları ve sınır değeri kontrolleri alıştırmanın README dosyasındadır. Sonraki adım, çalışan sınıflandırma mantığını bir fonksiyona ayırmak olacak.
