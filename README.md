# ESp32_smart_doorlock

This project implements a security system using an ESP32 microcontroller, featuring password-based access control, motion detection, and an OLED display interface.

--- 

# 📋 Project Overview

The system combines multiple components to create a secure access control system:
Keypad input for password entry and system control
PIR motion sensor to detect movement
OLED display for user feedback
Buzzer for audible alerts
Door lock relay control for access granting
Onboard LED for visual indicators

--- 

# 🛠 Hardware Components

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

---

# 🔌 Wiring Diagram

Component	ESP32 Pin
PIR Sensor Output	GPIO 19
Buzzer	GPIO 23
Onboard LED	GPIO 2
Door Lock Relay	GPIO 4
Keypad Rows	GPIO 13, 27, 26, 25
Keypad Columns	GPIO 33, 32, 5, 18
OLED SDA	GPIO 21
OLED SCL	GPIO 22

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
Click OK
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

In Arduino IDE:
Select Tools → Board → ESP32 Arduino
Choose your specific ESP32 model (usually "ESP32 Dev Module")
Select the correct PORT (COMX on Windows, /dev/ttyUSBX on Linux)

Set other parameters as follows:
Upload Speed: "115200"
CPU Frequency: "240MHz (WiFi/BT)"
Flash Frequency: "80MHz"
Flash Mode: "QIO"
Flash Size: "4MB (32Mb)"

Partition Scheme: "Default 4MB with spiffs (1.2MB APP/1.5MB SPIFFS)"

---

# 🚀 Uploading the Code
Open the provided code in Arduino IDE
Verify the code by clicking the checkmark (✓) button
Upload the code to your ESP32 by clicking the right-arrow (→) button
During upload, you may need to press the "BOOT" button on your ESP32

--- 

# 🎮 System Operation
Default Password
The system starts with the default password: 1212

Keypad Functions
Digits (0-9): Password input
A: Start password change process
***: Clear input or confirm new password
#: Submit entered password

Normal Operation
Enter your 4-digit password
Press # to submit

If correct, the door will unlock for 3 seconds
Changing Password
Press A to begin password change
Enter your new password (minimum 4 digits)
Press *** to confirm the new password

Motion Detection
The PIR sensor will detect motion and trigger:

A brief beep from the buzzer
A flash from the onboard LED

--- 

# 🔧 Troubleshooting
Common Issues
Port not showing up:

Install ESP32 USB drivers (CP210x or CH340)
Try a different USB cable (some only provide power)

Upload fails:
Press and hold the "BOOT" button while uploading
Check your board selection and port settings

OLED not displaying:
Check I2C connections (SDA/SCL)
Verify the SH1106 library is installed

Keypad not working:
Verify row and column connections match the code
Check for loose connections

--- 

# 📁 Project Structure
```
esp32-security-system/
│
├── esp32_security_system.ino  # Main Arduino sketch
├── README.md                  # This file
└── libraries/                 # Required libraries (installed via Arduino IDE)
```
---

🔄 Modifying the Code
Changing Default Password
Locate this line in the code and change the value:

```
String password = "1212";  // Change this value
Adjusting Pin Assignments
Modify the pin definitions at the top of the code if your wiring differs:
```

---

📞 Support
If you encounter issues:
Check all hardware connections
Verify library installations
Ensure correct board and port selection in Arduino IDE
Check the Serial Monitor (Tools → Serial Monitor) for debug messages

----

📄 License
This project is open source and available under the MIT License.