#include <Wire.h>
#define PIR_PIN 7
#define LED_PIN 13
#define BUZZER_PIN 12
bool alarmArmed = false;
bool motionDetected = false;
void setup() {
 pinMode(PIR_PIN, INPUT);
 pinMode(LED_PIN, OUTPUT);
 pinMode(BUZZER_PIN, OUTPUT);
 Wire.begin(8);
 Wire.onReceive(receiveEvent);
 Wire.onRequest(requestEvent);
}
void loop() {
 static bool prevMotionDetected = false;
 if (alarmArmed) {
 static unsigned long lastBlinkTime = 0;
 if (millis() - lastBlinkTime >= 1000) {
 lastBlinkTime = millis();
 digitalWrite(LED_PIN, !digitalRead(LED_PIN));
 }
 
 motionDetected = digitalRead(PIR_PIN) == HIGH;
 if (motionDetected) {
 digitalWrite(LED_PIN, HIGH);
 digitalWrite(BUZZER_PIN, HIGH);
 } else {
 digitalWrite(BUZZER_PIN, LOW);
 }
 } else {
 motionDetected = false;
 digitalWrite(LED_PIN, LOW);
 digitalWrite(BUZZER_PIN, LOW);
 }
 delay(100); // Evitar debouncing do PIR
}
void receiveEvent(int howMany) {
 String command = "";
 while (Wire.available()) {
 char c = Wire.read();
 command += c;
 }
 command.trim();
 if (command.equalsIgnoreCase("ARMAR")) {
 alarmArmed = true;
 } else if (command.equalsIgnoreCase("DESARMAR")) {
 alarmArmed = false;
 digitalWrite(LED_PIN, LOW);
 digitalWrite(BUZZER_PIN, LOW);
 }
}
void requestEvent() {
 if (motionDetected && alarmArmed) {
 Wire.write("1");
 } else {
 Wire.write("0");
 }
}