#include <Joystick.h>

#define HANDBRAKE_PIN A0

int sensorMinValue = 9999;
int sensorMaxValue = -9999;

void setup() {
  pinMode(HANDBRAKE_PIN, INPUT); 
  Joystick.begin();
}

void loop() {
  int sensorValue = analogRead(HANDBRAKE_PIN);
  sensorMinValue = min(sensorMinValue, sensorValue);
  sensorMaxValue = max(sensorMaxValue, sensorValue);

  int mappedValue = map(sensorValue, sensorMinValue, sensorMaxValue, 0, 255);
  Joystick.setThrottle(mappedValue);
}