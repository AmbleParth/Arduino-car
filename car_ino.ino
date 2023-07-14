#include <AFMotor.h>

AF_DCMotor motor1(1); //the pin in which your motor 1 is in adafruit motor shield
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  motor1.setSpeed(500);
  motor2.setSpeed(500);
  motor3.setSpeed(500);
  motor4.setSpeed(500);

  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);

  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) { // Check if there is data available to be read
    char command = Serial.read(); // Read the incoming command

    if (command == 'b') {
      motor1.run(BACKWARD);
      motor2.run(BACKWARD);
      motor3.run(BACKWARD);
      motor4.run(BACKWARD);
    } else if (command == 'f') {
      motor1.run(FORWARD);
      motor2.run(FORWARD);
      motor3.run(FORWARD);
      motor4.run(FORWARD);
    } else if (command == 'l') {
      motor1.run(FORWARD);
      motor2.run(BACKWARD);
      motor3.run(BACKWARD);
      motor4.run(FORWARD);
    } else if (command == 'r') {
      motor1.run(BACKWARD);
      motor2.run(FORWARD);
      motor3.run(FORWARD);
      motor4.run(BACKWARD);
    } else if (command == 's') {
      motor1.run(RELEASE);
      motor2.run(RELEASE);
      motor3.run(RELEASE);
      motor4.run(RELEASE);
    }
  }
}