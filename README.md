# Smart Energy Monitor

This is a personal project where I'm building a real-time **Smart Energy Monitor** using the **ESP32**, current and voltage sensors, and integrating it with **Machine Learning** to predict electricity bills.

The goal? To combine hands-on hardware, embedded firmware, and ML deployment into a single, practical system — the kind of project that not only tracks energy consumption, but actually *makes sense of it*.

---

## Features

-  Real-time current and voltage sensing  
-  Power and energy calculation using EmonLib  
-  Electricity bill prediction using a trained ML model  
-  Plans for app/web interface integration  
-  ESP32-based data transmission and control  
-  Drafted for submission to *Electronics For You (EFY)* magazine

---

## Hardware Overview

| Component         | Description                         |
|------------------|-------------------------------------|
| ESP32            | Main microcontroller (Wi-Fi enabled)|
| SCT-013-000      | Current sensor                      |
| ZMPT101B         | Voltage sensor                      |
| 100-ohm Resistor | Burden resistor for current sensing |
| Power Supply     | For safe AC-DC conversion           |
| PCB              | Custom designed in KiCad            |
| 2x10kohm Resistor| Voltage divider for SCT-013-000     |
| 10uF capacitor   | To stabilize signal from SCT-013-000|

---
//coming soon...
## ML Integration

- Trained a regression model using collected data  
- Used **TinyML** concepts to deploy model on the ESP32  
- Predicts monthly electricity bill based on live usage trends  
- Code built and trained using Python & scikit-learn
---

## Current Progress

- Hardware circuit built and tested (AC-side debugging in progress)
- Firmware code functional (voltage readings stable, current under testing)
- ML model trained, conversion to TinyML in progress
- Working on integration + EFY documentation
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
