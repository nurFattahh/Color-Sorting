#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Define servo parameters
#define NUM_SERVOS 4
#define SERVOMIN 150
#define SERVOMAX 600

#define SERVO_DRIVER_ADDRESS 0x40  // Alamat I2C default Servo Driver PCA9685
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(SERVO_DRIVER_ADDRESS);

void setup() {
  Serial.begin(9600);
  Serial.println("Adafruit PWM Servo Driver Test");

  pwm.begin();
  pwm.setPWMFreq(60);  // Set frekuensi PWM ke 60 Hz (sesuaikan dengan servo)
}

void loop() {
  // //maks servo 1
  // moveServoSlowly(0, 0, 180, 5);  // Gerakkan servo dari posisi 0 ke 180 derajat dengan langkah 5 derajat
  // //min servo 1
  // moveServoSlowlymin(0, 180, 0, 5);
  //maks servo 2
  moveServoSlowly(0,0,90,5);
  //min servo 2
  
  moveServoSlowly(0, 0, 180, 5, 400);  // Gerakkan servo dari posisi 0 ke 180 derajat dengan langkah 5 derajat
  moveServoSlowlymin(0, 180, 0, 5, 400);
}

void moveServoSlowly(uint8_t servoNum, uint16_t fromPos, uint16_t toPos, uint8_t stepSize, unsigned long time) {
  // Gerakkan servo dari posisi awal ke posisi akhir dengan langkah tertentu
  for (uint16_t pos = fromPos; pos <= toPos; pos += stepSize) {
    pwm.setPWM(servoNum, 0, map(pos, 0, 180, SERVOMIN, SERVOMAX));
    delay(time);  // Sesuaikan nilai delay sesuai kebutuhan untuk memperlambat gerakan
  }
}

void moveServoSlowlymin(uint8_t servoNum, uint16_t fromPos, uint16_t toPos, uint8_t stepSize, unsigned long time) {
  // Gerakkan servo dari posisi awal ke posisi akhir dengan langkah tertentu
  for (uint16_t pos = fromPos; pos >= toPos; pos -= stepSize) {
    pwm.setPWM(servoNum, 0, map(pos, 0, 180, SERVOMIN, SERVOMAX));
    delay(time);  // Sesuaikan nilai delay sesuai kebutuhan untuk memperlambat gerakan
  }
}

