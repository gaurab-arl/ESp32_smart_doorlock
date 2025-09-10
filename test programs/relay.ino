#define RELAY_PIN 4

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  Serial.begin(115200);
  Serial.println("Relay Test Started");
}

void loop() {
  Serial.println("Relay ON");
  digitalWrite(RELAY_PIN, HIGH);
  delay(2000);
  
  Serial.println("Relay OFF");
  digitalWrite(RELAY_PIN, LOW);
  delay(2000);
}