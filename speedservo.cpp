#include <Wire.h>
#include <Adafruit_ServoDriver.h>

Adafruit_PWMServoDriver ;

int servoNum = 0;  // Servo number on the PCA9685 driver

int pos = 0;
int increment = 2.5;
int delaytime = 40;
int jeda = 1000;

void setup() {
  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
}

void loop() {
  for (pos = 0; pos <= 180; pos += increment) {
    pwm.setPWM(servoNum, 0, map(pos, 0, 180, SERVOMIN, SERVOMAX));
    delay(delaytime);
  }
}
