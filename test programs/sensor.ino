#define PIR_SENSOR_PIN 19
#define LED_PIN 2

void setup() {
  pinMode(PIR_SENSOR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  Serial.println("PIR Sensor Test Started");
}

void loop() {
  int motion = digitalRead(PIR_SENSOR_PIN);
  
  if (motion == HIGH) {
    Serial.println("Motion detected!");
    digitalWrite(LED_PIN, HIGH);
    delay(1000);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
  
  delay(100);
}