# ⚡ Smart Energy Monitor with ESP32 + ML

This is a personal project where I’m building a real-time **Smart Energy Monitor** using the **ESP32**, **current and voltage sensors**, and integrating it with **Machine Learning** to predict electricity bills.  

The goal? Combine **hands-on hardware**, **embedded firmware**, and **local ML inference** into one practical, nerdgasmic system.

---

## 🚀 Features

- Real-time voltage and current sensing  
- Power and energy calculation using **EmonLib**  
- Electricity bill prediction using a trained **ML model**  
- Tkinter-based smart UI (coming soon 👀)  
- ESP32-based wireless data transmission and control

---

## 🔩 Hardware Overview

| Component           | Description                              |
|---------------------|------------------------------------------|
| **ESP32**           | Main microcontroller (Wi-Fi enabled)     |
| **SCT-013-000**     | Current sensor (initial option)          |
| **ACS712**          | Current sensor (final choice)            |
| **ZMPT101B**        | Voltage sensor                           |
| **100Ω Resistor**   | Burden resistor for current sensing      |
| **2×10kΩ Resistors**| Voltage divider for SCT-013-000          |
| **10μF Capacitor**  | Signal smoothing for SCT-013-000         |
| **Power Supply**    | For safe AC-DC conversion                |
| **Custom PCB**      | Designed using **KiCad**                 |

---

## 🧠 ML Integration

1. **Model Training**  
   A **linear regression** model is trained on historical monthly data:  
   → total energy consumed (kWh)  
   → median temperature (°C)  
   → median humidity (%)

2. **Feature Engineering**  
   Input features:  
   - `Month (1–12)`  
   - `Median Temp (°C)`  
   - `Median Humidity (%)`  
   Output:  
   - `Predicted Power Consumption (kWh)`

3. **Model Deployment**  
   The trained model is saved using `joblib` and integrated into a **Tkinter GUI** for real-time, local predictions.  
   No cloud. No nonsense. Just fast and local.

4. **Smart Prediction UI**  
   The user selects a month → ESP32 sends real-time sensor values → ML model predicts the electricity usage and bill instantly ⚡

---

## ✅ Current Progress

- ✅ Hardware setup complete: all sensors tested and working  
- ✅ **ACS712** chosen over SCT due to noise/interference  
- ✅ ML model built with excellent **R² score (~0.95)**  
- ✅ Overfitting issue handled  
- ✅ Live predictions tested  
- 🔜 Building the Python UI to unify ESP32 + ML + user interface

---

## 📜 License

MIT License.  
Explore. Fork. Build your own. Just don’t forget to give credit, my guy.

---

## 🤔 Why I Built This

As part of my deep dive into **Embedded Systems**, **IoT**, and **Machine Learning**, I wanted a project that touches every layer — from low-level sensing to high-level intelligence.

This is that project.  
**Code meets current. AI meets AC.**

---

## 💬 Contributions / Feedback

Working on energy monitoring, embedded ML, or ESP32 projects?  
Have ideas, feature requests, or optimizations?  
Let’s connect — I’m always open to collaboration and conversation!
