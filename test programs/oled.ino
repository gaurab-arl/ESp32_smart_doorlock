#include <Wire.h>
#include <U8g2lib.h>

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

void setup() {
  Serial.begin(115200);
  u8g2.begin();
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.drawStr(0, 10, "OLED Test");
  u8g2.drawStr(0, 30, "Display Working!");
  u8g2.sendBuffer();
  Serial.println("OLED Test Started");
}

void loop() {
  static int counter = 0;
  
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.drawStr(0, 10, "OLED Test");
  u8g2.setCursor(0, 30);
  u8g2.print("Counter: ");
  u8g2.print(counter);
  u8g2.sendBuffer();
  
  counter++;
  delay(1000);
}