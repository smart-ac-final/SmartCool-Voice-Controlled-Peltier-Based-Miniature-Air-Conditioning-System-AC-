# SmartCool: Voice-Controlled Peltier-Based Miniature Air Conditioning System

## 📖 Overview

**SmartCool** is our final-year B.Tech project that demonstrates a compact, energy-efficient, and IoT-enabled miniature air conditioning system. The system uses a **Peltier (Thermoelectric) Module** to provide cooling and can be controlled through **voice commands** using the **Blynk IoT platform** and **Google Assistant**.

The project is designed as a low-cost prototype to showcase smart home automation, IoT integration, and thermoelectric cooling technology.

---

## ✨ Features

- 🎤 Voice control using Google Assistant
- 📱 Remote control through the Blynk IoT app
- ❄️ Peltier-based cooling system
- 🌡️ Temperature monitoring
- 📶 Wi-Fi connectivity using ESP8266 (NodeMCU)
- ⚡ Low-power and portable prototype
- 🔄 Real-time ON/OFF control

---

## 🛠️ Hardware Components

- ESP8266 NodeMCU
- Peltier Module (TEC1-12706)
- Heat Sink
- Cooling Fan
- MOSFET Module
- 12V DC Power Supply
- Jumper Wires
- Breadboard / PCB
- Temperature Sensor (Optional)

---

## 💻 Software Requirements

- Arduino IDE
- ESP8266 Board Package
- Blynk Library
- ESP8266WiFi Library
- Google Assistant
- Blynk IoT Platform

---

## 📂 Repository Structure

```
SmartCool/
│
├── SmartCool.ino        # Arduino source code
├── README.md            # Project documentation
└── images/              # Project images (optional)
```

---

## 🚀 Getting Started

### 1. Clone the Repository

```bash
git clone https://github.com/your-username/SmartCool.git
```

### 2. Open the Project

Open the `.ino` file using **Arduino IDE**.

### 3. Install Required Libraries

Install the following libraries using Arduino Library Manager:

- Blynk
- ESP8266WiFi

### 4. Configure Credentials

Update the following values in the Arduino code:

```cpp
#define BLYNK_TEMPLATE_ID ""
#define BLYNK_TEMPLATE_NAME ""
#define BLYNK_AUTH_TOKEN ""

char ssid[] = "Your_WiFi_Name";
char pass[] = "Your_WiFi_Password";
```

### 5. Select Board

Choose:

```
NodeMCU 1.0 (ESP-12E Module)
```

### 6. Upload

Upload the code to the ESP8266.

---

## ⚙️ Working Principle

1. ESP8266 connects to the Wi-Fi network.
2. Blynk IoT platform receives commands from the mobile app or Google Assistant.
3. When the user gives a voice command (e.g., "Turn on SmartCool"), Google Assistant triggers Blynk.
4. ESP8266 receives the command.
5. The MOSFET switches the Peltier module ON/OFF.
6. The fan dissipates heat from the heat sink while the cold side provides cooling.

---

## 📱 Voice Commands

Example commands:

- "Turn on SmartCool"
- "Turn off SmartCool"

---

## 📷 Project Images

You can add images here.

```
images/
├── prototype.jpg
├── circuit_diagram.png
├── block_diagram.png
```

---

## 🎯 Applications

- Personal desktop cooling
- Smart home automation
- Educational IoT projects
- Thermoelectric cooling demonstrations
- Miniature cooling systems

---

## 🔮 Future Improvements

- Automatic temperature control
- Mobile notifications
- LCD/OLED temperature display
- Battery-powered portable version
- AI-based energy optimization
- Voice feedback system

---

## 👨‍💻 Team Members

- Tulsidas Mandal
- *(Add other team members here)*

Department of Electronics & Communication Engineering

---

## 📜 License

This project is developed for academic and educational purposes.

---

## ⭐ Support

If you found this project useful, please consider giving it a ⭐ on GitHub.

Thank you for visiting our project repository!
