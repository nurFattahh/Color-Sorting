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
  //ROBOTIC ARM KE PENAMPUNGAN BIRU   
               ArmMotion(0, 90, 180, 10, 400);
               ArmMotion(3, 0, 120, 10, 400);
               ArmMotion(2, 0, 110, 10, 400);  
               ArmMotionReverse(3, 150, 30, 10, 400);
               ArmMotionReverse(2, 120, 60, 10, 400);
               ArmMotionReverse(0, 180, 60, 10, 400); // MENUJU PENAMPUNG BIRU
               ArmMotion(3, 30, 110, 10, 400);
}

//FUNGSI

//FUNGSI GERAK SERVO
void ArmMotion(uint8_t servoNum, uint16_t fromPos, uint16_t toPos, uint8_t stepSize, unsigned long time) {
  for (uint16_t pos = fromPos; pos <= toPos; pos += stepSize) {
    pwm.setPWM(servoNum, 0, map(pos, 0, 180, SERVOMIN, SERVOMAX));
    delay(time); 
  }
}

//FUNGSI GERAK SERVO REVERSE
void ArmMotionReverse(uint8_t servoNum, uint16_t fromPos, uint16_t toPos, uint8_t stepSize, unsigned long time) {
  for (uint16_t pos = fromPos; pos >= toPos; pos -= stepSize) {
    pwm.setPWM(servoNum, 0, map(pos, 0, 180, SERVOMIN, SERVOMAX));
    delay(time); 
  }
}
