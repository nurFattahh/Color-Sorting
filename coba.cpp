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
               ArmMotion(0, 90, 180, 3, 100); // MENUJU CONVEYOR
               //ArmMotion(3, 30, 130, 10, 400); // MEMBUKA CAPIT
               ArmMotion(2, 60, 120, 5, 200); // MENDEKATI CONVEYOR
               ArmMotionReverse(3, 130, 30, 10, 400); // MENUTUP CAPIT
               ArmMotionReverse(2, 120, 60, 5, 200); // MENJAUHI CONVEYOT
               ArmMotionReverse(0, 180, 10, 3, 100); // MENUJU PENAMPUNG MERAH
               ArmMotion(3, 30, 130, 10, 400); //MEMBUKA CAPIT
               exit(0);

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
