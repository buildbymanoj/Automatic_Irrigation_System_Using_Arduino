# Automatic_Irrigation_System_Using_Arduino
This project is designed to automate irrigation by monitoring soil moisture levels using a sensor and controlling a water pump accordingly. The system helps ensure that plants receive water only when necessary, improving water efficiency and supporting healthy plant growth.

# 🌱 Smart Soil Moisture Monitoring and Irrigation System

This Arduino-based project automatically controls a water pump based on the soil moisture level. It provides visual and audible alerts using LEDs and a buzzer. It’s ideal for small gardens, indoor plants, or agriculture prototypes.

---

## 🔧 Components Used

- **Arduino Uno / Nano**
- **Soil Moisture Sensor**
- **5V Relay Module**
- **Water Pump (5V/12V as per relay & power supply)**
- **Red LED** (Low Moisture Indicator)
- **Green LED** (Moisture OK Indicator)
- **Buzzer** (Low Moisture Alert)
- **External Power Supply** for Pump and Relay (e.g., 9V–12V battery or adapter)
- **Breadboard & Jumper Wires**

---

## ⚙️ Working Principle

1. **Sensor Reading:** Soil moisture is read via an analog pin.
2. **Decision Logic:**
   - **Low Moisture:** Pump turns ON, red LED lights up, buzzer sounds.
   - **Medium Moisture:** Pump stays OFF, green LED lights up.
   - **High Moisture:** Everything remains OFF except green LED.
3. **Relay Activation:** The relay controls the pump based on sensor data.

---

## 📌 Threshold Calibration

Adjust these two thresholds based on your soil and sensor type:

```cpp
const int lowThreshold = 300;      // Below this → Dry soil
const int mediumThreshold = 600;   // Above this → Moist soil
```

To find the right values:
- Insert the sensor in **dry soil** and note the value.
- Insert the sensor in **wet soil** and note the value.
- Use values **in-between** for `lowThreshold` and `mediumThreshold`.

---

## 🪫 Power Supply Notes

🔋 **IMPORTANT:**  
Use a **separate battery or power source** for the **pump and relay**, because:

- The **pump motor draws high current**, which can reset or damage the Arduino if powered from the same source.
- A **flyback diode** is recommended across the pump terminals to protect against voltage spikes.

---

## 🔌 Pin Configuration

| Component          | Arduino Pin |
|--------------------|-------------|
| Soil Sensor (AOUT) | A0          |
| Relay (Pump Ctrl)  | 7           |
| Red LED            | 12          |
| Green LED          | 13          |
| Buzzer             | 8           |

---

## 🖥️ Serial Monitor

Monitor moisture values via Serial at **9600 baud**. This helps in threshold calibration and debugging.

---

## ⏳ Delay

The system checks moisture every **1 second (1000 ms)** using `delay(1000);`.

---

## ✅ How to Use

1. Upload the code to your Arduino.
2. Power the pump circuit separately.
3. Adjust thresholds if necessary.
4. Watch your system take care of plant watering automatically!

---

## 📷 Optional Upgrades

- Use an **LCD or OLED screen** to display moisture level.
- Add **WiFi (ESP8266/ESP32)** to send moisture data to your phone.
- Add a **real-time clock (RTC)** to restrict watering to specific times.

---

## 👨‍🔧 Author & License

Created by an ECE student for educational and prototyping purposes.  
Feel free to modify and expand as needed! ✨
