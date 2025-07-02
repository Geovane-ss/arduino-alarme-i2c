#include <Wire.h>
#define LED_PIN 13
#define BUZZER_PIN 12
#define SLAVE_ADDRESS 8
bool alarmArmed = false;
bool alarmTriggered = false;
void setup() {
 pinMode(LED_PIN, OUTPUT);
 pinMode(BUZZER_PIN, OUTPUT);
 Wire.begin();
 Serial.begin(9600);
}
void loop() {
 if (Serial.available()) {
 String command = Serial.readStringUntil('\n');
 command.trim();
 if (command.equalsIgnoreCase("ARMAR")) {
 Wire.beginTransmission(SLAVE_ADDRESS);
 Wire.write("ARMAR");
 Wire.endTransmission();
 alarmArmed = true;
 alarmTriggered = false;
 Serial.println("ALARME ARMADO");
 } else if (command.equalsIgnoreCase("DESARMAR")) {
 Wire.beginTransmission(SLAVE_ADDRESS);
 Wire.write("DESARMAR");
 Wire.endTransmission();
 alarmArmed = false;
 alarmTriggered = false;
 Serial.println("ALARME DESARMADO");
 }
 }
 if (alarmArmed && !alarmTriggered) {
 static unsigned long lastBlinkTime = 0;
 if (millis() - lastBlinkTime >= 1000) {
 lastBlinkTime = millis();
 digitalWrite(LED_PIN, !digitalRead(LED_PIN));
 }
 } else {
 digitalWrite(LED_PIN, LOW);
 }
 Wire.requestFrom(SLAVE_ADDRESS, 1);
 if (Wire.available()) {
 char response = Wire.read();
 if (response == '1') {
 alarmTriggered = true;
 digitalWrite(LED_PIN, HIGH);
 digitalWrite(BUZZER_PIN, HIGH);
 Serial.println("MOVIMENTO DETECTADO! ALARME ATIVADO!");
 } else if (response == '0') {
 alarmTriggered = false;
 digitalWrite(BUZZER_PIN, LOW);
 }
 }
}