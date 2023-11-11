#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm;

// Define servo parameters
#define NUM_SERVOS 4
#define SERVO_MIN 150
#define SERVO_MAX 600

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  delay(10);
}

void loop() {
  for (int servoNum = 0; servoNum < NUM_SERVOS; servoNum++) {
    // Move each servo to the minimum position
    Serial.print("Moving Servo ");
    Serial.print(servoNum + 1);
    Serial.println(" to minimum position");
    pwm.setPWM(servoNum, 0, SERVO_MIN);
    delay(3000);  // Wait for the servo to reach the minimum position

    // Move each servo to the maximum position
    Serial.print("Moving Servo ");
    Serial.print(servoNum + 1);
    Serial.println(" to maximum position");
    pwm.setPWM(servoNum, 0, SERVO_MAX);
    delay(3000);  // Wait for the servo to reach the maximum position

    // Return each servo to the center position
    Serial.print("Returning Servo ");
    Serial.print(servoNum + 1);
    Serial.println(" to center position");
    int centerPosition = (SERVO_MIN + SERVO_MAX) / 2;
    pwm.setPWM(servoNum, 0, centerPosition);
    delay(3000);  // Wait for the servo to return to the center position
  }
}
