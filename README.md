# 🚗 Advanced Driver Assistance System (ADAS)

This project demonstrates a simplified **ADAS (Advanced Driver Assistance System)** using embedded systems and sensors to enhance vehicle safety and assist the driver in real-time decision-making.

## 📌 Project Overview

The ADAS prototype simulates several core safety features used in modern vehicles:

1. **Adaptive Cruise Control (ACC)** – Maintains a safe distance from the car ahead.
2. **Lane Departure Warning (LDW)** – Alerts when the vehicle drifts out of its lane.
3. **Automated Emergency Braking (AEB)** – Activates brakes automatically in emergency situations.
4. **Lane Keeping Support (LKS)** – Adjusts steering to keep the vehicle in lane.

Each feature utilizes sensors and feedback mechanisms to emulate real-world safety systems.

---

## 👥 Team Members

- Farida Waheed
- Omar Atif
- Rahaf Ashraf
- John Fawzy
- Ritaj Mahmoud

---

## 🧠 Features and Functions

### 🔄 Adaptive Cruise Control (ACC)
- **Sensor:** Ultrasonic
- **Function:** Monitors vehicle distance
- **Logic:**
  - Stops vehicle if distance < 10 cm
  - Displays “Obstacle detected!!!” or “Cruising...” on LCD

### 🛑 Automated Emergency Braking (AEB)
- **Sensor:** Ultrasonic
- **Function:** Prevents collisions
- **Logic:**
  - Triggers brake if object detected < 5 cm
  - Buzzer + LCD alert: “Emergency Braking!!!!!”

### 🚧 Lane Departure Warning (LDW)
- **Sensor:** IR Sensors
- **Function:** Warns when vehicle drifts left/right
- **Logic:**
  - Buzzer + LCD alert for lane exit

### 🧭 Lane Keeping Support (LKS)
- **Sensor:** IR Sensors
- **Function:** Maintains lane alignment
- **Logic:**
  - Motor driver adjusts vehicle direction
  - LCD messages: “Adjusting left...” / “Adjusting right...”

---

## 🔩 System Components

| Component        | Role                                              |
|------------------|---------------------------------------------------|
| **ATmega MCU**   | Core processor for logic handling                |
| **Ultrasonic Sensor** | Detects distance to objects                  |
| **IR Sensors**   | Detects lane lines                               |
| **Buzzer**       | Audio feedback for alerts                        |
| **Motor Driver** | Controls motors for vehicle motion               |
| **LCD Display**  | Real-time system messages                        |

---

## 🧪 Simulations & Demonstrations

This project includes simulation videos demonstrating each function:

- ✅ Obstacle detection and automatic stopping
- ✅ Lane drifting warnings and feedback
- ✅ Automatic lane correction via motor control

📁 **Files Included:**
- `.pptx` and `.pdf` for detailed explanation
- Simulation videos: `Video 1.mp4`, `Video 2.mp4`, `Video 3.mp4`

---

## 🧠 Conclusion

The ADAS prototype showcases how embedded systems can be used to replicate advanced vehicle safety systems. With features like collision prevention and automated lane correction, the project aims to simulate how real-world ADAS improves driver safety and comfort.

