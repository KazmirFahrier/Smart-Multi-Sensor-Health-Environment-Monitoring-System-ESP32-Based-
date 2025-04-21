# 🧠💨📍⛰️ Smart Multi-Sensor Health & Environment Monitoring System (ESP32-Based)

This embedded system project integrates multiple real-time sensors on the ESP32 platform to monitor **human vitals** and **environmental conditions**. Designed for portability, modularity, and scalability, it can be used in health tracking, air quality assessment, GPS-based location monitoring, and weather awareness applications.

---

## 🧰 Modules & Features

### ❤️ Heart Rate Monitor
- Uses the **MAX30102** pulse sensor.
- Measures heartbeats using IR values.
- Computes both **instant BPM** and **average BPM**.
- Detects finger placement quality.

### 🌫️ Gas/Smoke Detection
- Integrates an **MQ2 sensor** to detect smoke.
- Outputs real-time status (Smoke: Detected / Not Detected).
- Includes a 20-second warm-up period for sensor calibration.

### 🌍 GPS Module
- Uses **Serial1 (GPIO 16 & 17)** on the ESP32 to read live NMEA GPS data.
- Streams raw GPS sentences for location tracking or logging.
- Compatible with **TinyGPS++** for advanced parsing (optional).

### 🏔️ Atmospheric Pressure & Altitude
- Reads **temperature**, **absolute & sea-level pressure**, and **calculated altitude** using a **BMP180 barometric sensor**.
- Helpful for environmental monitoring and altitude awareness in real-time.


---

## 📦 Dependencies

Install the following libraries via Library Manager or GitHub:

- [SparkFun MAX3010x Pulse Oximeter Library](https://github.com/sparkfun/SparkFun_MAX3010x_Sensor_Library)
- [heartRate.h helper](https://github.com/sparkfun/SparkFun_MAX3010x_Sensor_Library/blob/main/examples/Example6_HeartRate/heartRate.h)
- [Adafruit BMP180 Library](https://github.com/adafruit/Adafruit-BMP085-Library)
- (Optional) [TinyGPS++](https://github.com/mikalhart/TinyGPSPlus)

---

## ⚙️ Hardware & Pin Setup (ESP32)

| Module              | Sensor         | Pins Used             |
|---------------------|----------------|------------------------|
| Heart Rate          | MAX30102       | I2C (GPIO 21: SDA, 22: SCL) |
| Gas Sensor          | MQ2            | Digital GPIO 8         |
| GPS Module          | Serial GPS     | RX: GPIO 16, TX: GPIO 17 |
| Pressure Sensor     | BMP180         | I2C (GPIO 21: SDA, 22: SCL) |

---

## 🚀 How to Use

1. Flash any of the `.ino` files to your ESP32 using Arduino IDE or PlatformIO.
2. Open **Serial Monitor** at the appropriate baud rate (typically `9600` or `115200`).
3. Observe live sensor outputs and adapt integration as needed.

---

## 🛡️ Disclaimer

This project is designed for educational and prototyping purposes. It does not replace certified medical or environmental monitoring equipment.

---

## 🙌 Acknowledgments

- SparkFun & Adafruit for sensor libraries
- Arduino and ESP32 community

