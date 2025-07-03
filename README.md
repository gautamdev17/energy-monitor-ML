# Smart Energy Monitor

This is a personal project where I'm building a real-time **Smart Energy Monitor** using the **ESP32**, current and voltage sensors, and integrating it with **Machine Learning** to predict electricity bills.

The goal is to combine hands-on hardware, embedded firmware, and ML deployment into a single, practical system. 

---

## Features

-  Real-time current and voltage sensing  
-  Power and energy calculation using EmonLib  
-  Electricity bill prediction using a trained ML model  
-  Plans for app/web interface integration  
-  ESP32-based data transmission and control
---

## Hardware Overview

| Component         | Description                        |
|------------------|-------------------------------------|
| ESP32            | Main microcontroller (Wi-Fi enabled)|
| SCT-013-000      | Current sensor                      |
| ACS712           | Current sensor                      |
| ZMPT101B         | Voltage sensor                      |
| 100-ohm Resistor | Burden resistor for current sensing |
| Power Supply     | For safe AC-DC conversion           |
| PCB              | Custom designed in KiCad            |
| 2x10kohm Resistor| Voltage divider for SCT-013-000     |
| 10uF capacitor   | To stabilize signal from SCT-013-000|

---
## ML Integration
1. Model Training
	A linear regression model is trained using historical monthly data: total energy consumed (kWh), median temperature (°C), and humidity (%) for each month.
2.Feature Engineering
	The input features are:
	Month (1–12), Median Temperature, and Median Humidity.
	The output is the predicted power consumption in kWh.
3.Model Deployment
	The trained model is saved using joblib and loaded into the Tkinter UI app for real-time predictions. No cloud/edge inference needed—pure local ML!
4.Smart Prediction UI
	The user selects a month; temperature and humidity are fetched from the ESP32. The app then predicts electricity usage and estimated bill instantly.

---

## Current Progress

--HARDWARE PART IS COMPLETED, voltage,current and temperature sensors are working perfectly
--chose ACS712 sensor for accurate values since SCT sensor had a lot of interference
--ML code is over, the model can predict your bill using linear regression
--problem of overfitting is also addressed
--What now?
  Looking for a good UI for esp32 and the ML model can talk and present to the user
---

## License

MIT License. Feel free to explore, learn from, and build on this — just give appropriate credit where due.

---

## Why I Built This

As part of my exploration into embedded systems, IoT, and machine learning, this project represents a major step in applying what I’ve learned in a practical, meaningful way.  
It blends hardware, firmware, and AI.

---

## Contributions / Feedback

If you're working on similar energy projects, or have experience with AC sensing or embedded ML — feel free to connect. I’m always open to collaborations and ideas.

---
