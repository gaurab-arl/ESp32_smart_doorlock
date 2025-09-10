#define BUZZER_PIN 23

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(115200);
  Serial.println("Buzzer Test Started");
}

void loop() {
  // Play a simple melody
  tone(BUZZER_PIN, 1000); // 1kHz
  delay(500);
  tone(BUZZER_PIN, 1500); // 1.5kHz
  delay(500);
  noTone(BUZZER_PIN);
  delay(1000);
  
  // Short beeps
  for(int i = 0; i < 3; i++) {
    tone(BUZZER_PIN, 2000);
    delay(100);
    noTone(BUZZER_PIN);
    delay(100);
  }
  
  delay(2000);
}