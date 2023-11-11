#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define SERVO_DRIVER_ADDRESS 0x40  // Alamat I2C default Servo Driver PCA9685
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(SERVO_DRIVER_ADDRESS);

void setup() {
  Serial.begin(9600);
  Serial.println("Adafruit PWM Servo Driver Test");

  pwm.begin();
  pwm.setPWMFreq(60);  // Set frekuensi PWM ke 60 Hz (sesuaikan dengan servo)
}

void loop() {
  moveServoSlowly(0, 90, 180, 5);  // Gerakkan servo dari posisi 0 ke 180 derajat dengan langkah 5 derajat
}

void moveServoSlowly(uint8_t servoNum, uint16_t fromPos, uint16_t toPos, uint8_t stepSize) {
  // Gerakkan servo dari posisi awal ke posisi akhir dengan langkah tertentu
  for (uint16_t pos = fromPos; pos <= toPos; pos += stepSize) {
    pwm.setPWM(servoNum, 0, map(pos, 0, 180, SERVOMIN, SERVOMAX));
    delay(50);  // Sesuaikan nilai delay sesuai kebutuhan untuk memperlambat gerakan
  }
}