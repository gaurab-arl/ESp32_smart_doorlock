#define PIR_SENSOR_OUTPUT_PIN 19
#define BUZZER_PIN 23
#define LED_PIN 2  // Onboard LED
#define DOOR_LOCK_PIN 4 

#include <Wire.h>
#include <Keypad.h>
#include <U8g2lib.h>

// OLED SH1106 via I2C
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

// Keypad setup
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = { 
   {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {13, 27, 26, 25};  // Adjust for your wiring
byte colPins[COLS] = {33, 32, 5, 18};   // Adjust for your wiring
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Password management
String password = "1212";
String input = "";
String newPassword = "";
bool isChangingPassword = false;

bool lastPIRState = LOW;
bool currentPIRState = LOW;

void setup() {
  pinMode(PIR_SENSOR_OUTPUT_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(115200);
  Wire.begin(21, 22); // SDA = 21, SCL = 22
  u8g2.begin();
    pinMode(DOOR_LOCK_PIN, OUTPUT);      // ✅ Setup for door lock
  digitalWrite(DOOR_LOCK_PIN, LOW);   // ✅ Door locked initially

  showMessage("System Ready");
}

void loop() {
  currentPIRState = digitalRead(PIR_SENSOR_OUTPUT_PIN);

  // Detect rising edge (LOW → HIGH)
  if (currentPIRState == HIGH && lastPIRState == LOW) {
    Serial.println("🚶 Motion Detected!");

    digitalWrite(LED_PIN, HIGH);
    tone(BUZZER_PIN, 2000);
    delay(300);  // short beep
    noTone(BUZZER_PIN);
    digitalWrite(LED_PIN, LOW);
  }

  lastPIRState = currentPIRState;

  char key = keypad.getKey();

  if (key) {
    Serial.print("Key Pressed: ");
    Serial.println(key);

    if (isChangingPassword) {
      if (key == '*') {
        if (newPassword.length() >= 4) {
          password = newPassword;
          showMessage("Password Changed");
          Serial.println("Password changed.");
        } else {
          showMessage("Min 4 digits");
          Serial.println("Too short.");
        }
        newPassword = "";
        isChangingPassword = false;
      } else {
        newPassword += key;
        showMessage("New: " + newPassword);
      }
    } else {
      if (key == 'A') {
        isChangingPassword = true;
        newPassword = "";
        showMessage("Enter New Pass");
      } else if (key == '*') {
        input = "";
        showMessage("Input Cleared");
      } else if (key == '#') {
        checkPassword();
      } else {
        input += key;
        showInput();
      }
    }
  }
}

void checkPassword() {
  if (input == password) {
    Serial.println("Access Granted");
    showMessage("Access Granted!");
    // Optionally trigger relay or unlock
    digitalWrite(DOOR_LOCK_PIN, HIGH);   // ✅ Unlock door
    delay(3000);                         // Keep door unlocked for 3 seconds
    digitalWrite(DOOR_LOCK_PIN, LOW); 
  } else {
    Serial.println("Wrong Password");
    showMessage("Wrong Password!");
  }
  input = ""; 
}

void showMessage(String msg) {
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.drawStr(0, 24, msg.c_str());
  u8g2.sendBuffer();
}

void showInput() {
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.drawStr(0, 10, "Enter PIN:");
  u8g2.drawStr(0, 30, input.c_str());
  u8g2.sendBuffer();
}
