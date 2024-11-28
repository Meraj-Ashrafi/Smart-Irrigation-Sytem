# Smart Irrigation System

## Overview
The **Smart Irrigation System** is an IoT-based project designed to monitor soil moisture levels and automate irrigation. The system uses a NodeMCU ESP8266, soil moisture sensor, LED, buzzer, and Blynk platform for cloud-based monitoring and control. It ensures optimal water usage by providing real-time data and alerts when the soil requires water.

---

## Features
- **Real-time Soil Moisture Monitoring:** Displays soil moisture levels on the Blynk app.
- **Automated Alerts:** Sends notifications when soil moisture falls below a predefined threshold.
- **LED Indicator:** Lights up when irrigation is needed.
- **Blynk Integration:** Uses Blynk as a cloud platform for remote monitoring and event logging.

---

## Components Required
1. **NodeMCU ESP8266**: Microcontroller for IoT applications.
2. **Soil Moisture Sensor**: Measures soil moisture levels.
3. **1 LED**: Indicates irrigation need.
4. **Buzzer** *(Optional)*: Alerts user with sound.
5. **Blynk Platform**: Cloud platform for IoT integration.
6. **Wi-Fi Network**: For connecting NodeMCU to the internet.

---

## Circuit Diagram
- **Soil Moisture Sensor**: Analog pin `A0` of NodeMCU.
- **LED**: Pin `D4` of NodeMCU.
- **Power Supply**: Connect NodeMCU to a 5V power source via USB.

---

## Code Configuration
Below is the main configuration of the project:

### Blynk Template Information
```cpp
#define BLYNK_TEMPLATE_ID "TMPL3v3Pe2I0n"
#define BLYNK_TEMPLATE_NAME "Smart Irrigation System"
#define BLYNK_AUTH_TOKEN "l2yXzH5HUAyOPFG4bFXAvrtmAGyfem5S"
