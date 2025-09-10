# ESp32_smart_doorlock

This project implements a security system using an ESP32 microcontroller, featuring password-based access control, motion detection, and an OLED display interface.

--- 

# 📋 Project Overview
```
The system combines multiple components to create a secure access control system:
Keypad input for password entry and system control
PIR motion sensor to detect movement
OLED display for user feedback
Buzzer for audible alerts
Door lock relay control for access granting
Onboard LED for visual indicators
```
--- 

# 🛠 Hardware Components
```
ESP32 Development Board
4×4 Matrix Keypad
PIR Motion Sensor (HC-SR501)
OLED Display (SH1106, 128×64)
Buzzer (Passive)
5V Relay Module (for door lock)
Jumper Wires
Breadboard or PCB
Transistor
Resistor 10000 0hm
```
---

# 🔌 Wiring Diagram
```
Component	ESP32 Pin
PIR Sensor Output	GPIO 19
Buzzer	GPIO 23
Onboard LED	GPIO 2
Door Lock Relay	GPIO 4
Keypad Rows	GPIO 13, 27, 26, 25
Keypad Columns	GPIO 33, 32, 5, 18
OLED SDA	GPIO 21
OLED SCL	GPIO 22
```
---

# 📝 Software Installation

1. Install Arduino IDE
    Download Arduino IDE from arduino.cc
    Install the application on your computer

2. Install ESP32 Board Support
    Open Arduino IDE
    Go to File → Preferences
    In "Additional Boards Manager URLs", add:
```
https://dl.espressif.com/dl/package_esp32_index.json
```

    Go to Tools → Board → Boards Manager
    Search for "esp32" and install the "ESP32 by Espressif Systems" package

3. Install Required Libraries
    Go to Sketch → Include Library → Manage Libraries

    Install the following libraries:
```
    Keypad by Mark Stanley, Alexander Brevig
    U8g2 by Oliver Kraus
```

4. Configure Arduino IDE for ESP32
    Connect your ESP32 to your computer via USB

    1.  In Arduino IDE:
    ```
        Select Tools → Board → ESP32 Arduino
        Choose your specific ESP32 model (usually "ESP32 Dev Module")
        Select the correct PORT (COMX on Windows)
    ```

    2.  Set other parameters as follows:
    ```
        Upload Speed: "115200"
        CPU Frequency: "240MHz (WiFi/BT)"
        Flash Frequency: "80MHz"
        Flash Mode: "QIO"
        Flash Size: "4MB (32Mb)"
     ```
---

# 🎮 System Operation
Default Password : 1212

Keypad Functions
    Digits (0-9): Password input
    A: Start password change process
    *: Clear input or confirm new password
    #: Submit entered password

Normal Operation
    Enter your 4-digit password
    Press # to submit

If correct, the door will unlock for 3 seconds
Changing Password
    Press A to begin password change
    Enter your new password (minimum 4 digits)
    Press * to confirm the new password

Motion Detection
The PIR sensor will detect motion and trigger:
    A brief beep from the buzzer

--- 

# 🔧 Troubleshooting
Common Issues
1. Port not showing up:
  Install ESP32 USB drivers (CP210x or CH340)
  Try a different USB cable (some only provide power)

2. Upload fails:
  Press and hold the "BOOT" button while uploading
  Check your board selection and port settings

3. OLED not displaying:
  Check I2C connections (SDA/SCL)
  Verify the SH1106 library is installed

4. Keypad not working:
  Verify row and column connections match the code
  Check for loose connections

--- 

# 📁 Project Structure
```
esp32-security-system/
│
├── main.ino                   # Main Arduino sketch
├── README.md                  # This file
├── ....                       # Other files
└── drivers/                   # Required drivers 
---

## 🔌 Driver Links

To upload code to the ESP32 via USB (CP2102):

- [CP210x Windows Drivers – Random Nerd Tutorials](https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/)
- [Official CP210x Drivers – Silicon Labs](https://www.silabs.com/software-and-tools/usb-to-uart-bridge-vcp-drivers)

---

📄 License
This project is open source and available under the MIT License.