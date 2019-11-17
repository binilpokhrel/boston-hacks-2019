#include <Servo.h>

Servo servo[2];

void setup() {
  Serial.begin(9600);
  servo[0].attach(9);
  servo[1].attach(10);
}

void loop() {
  while(!Serial.available());

  int value = Serial.read() - 48;

  int numPills = value <= 3 ? value: value - 4;
  int id = value <= 3 ? 0 : 1;

  servo[id].write(numPills*60);
}
