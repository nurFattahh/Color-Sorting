
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define NUM_SERVOS 4
#define SERVOMIN 150
#define SERVOMAX 600
#define SERVO_DRIVER_ADDRESS 0x40  // Alamat I2C default Servo Driver PCA9685
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(SERVO_DRIVER_ADDRESS);

//DEKLARASI PIN


//RELAY
int relay = 7;

//OBSTACLE
int obstacle = 8;


//TCS3200
int tcs_s0 = 2;
int tcs_s1 = 3;
int tcs_s2 = 4;
int tcs_s3 = 5;
int tcs_out = 6;

//DEKLARASI VARIABEL
int obstacle_state = HIGH;

//FUNGSI PROTOTYPE

//CLASS
class TCS3200 {
     private:
     int pin_s0, pin_s1, pin_s2, pin_s3, pin_out; 

     public :

     TCS3200 (int s0, int s1, int s2, int s3, int out) {
          pin_s0 = s0;
          pin_s1 = s1;
          pin_s2 = s2;
          pin_s3 = s3;
          pin_out = out;
     }

     int readColor (int state_s2, int state_s3) {
          digitalWrite (pin_s2, state_s2);
          digitalWrite (pin_s3, state_s3);
          return pulseIn (pin_out, LOW);
     }

     void printWarna (int data) {
     Serial.print(map(data, 60, 15, 0, 100));
     Serial.print("\t");
     delay(100);
     }
};

//MAIN
void setup() {
     Serial.begin(9600);
     Serial.println("Mulai Program");
     pwm.begin();
     pwm.setPWMFreq(60);  // Set frekuensi PWM ke 60 Hz (sesuaikan dengan servo)

  //RELAY
     pinMode(relay, OUTPUT);

     //OBSTACLE
     pinMode(obstacle, INPUT);

     //TCS3200
     pinMode(tcs_s0,OUTPUT);
     pinMode(tcs_s1,OUTPUT);
     pinMode(tcs_s2,OUTPUT);
     pinMode(tcs_s3,OUTPUT);
     pinMode(tcs_out,INPUT);
     digitalWrite(tcs_s0,HIGH);
     digitalWrite(tcs_s1,HIGH);
     digitalWrite(relay, LOW);
} 

void loop() {

     
     //CONVEYOR BERJALAN
     digitalWrite(relay, LOW);
     obstacle_state = HIGH; //memberi nilai HIGH agar obstacle tidak mendeteksi benda

     //SENSOR OBJEK MENDETEKSI BENDA
     while (obstacle_state == HIGH) {
          obstacle_state = digitalRead(obstacle);
          Serial.println("Tidak terdeteksi");
          if (obstacle_state == LOW) {
               Serial.println("Terdeteksi");
               //MEMATIKAN RELAY
               digitalWrite(relay, HIGH);
          }
     }
     delay(2000);

     //TCS3200 MENDETEKSI WARNA PADA BENDA
     TCS3200 sensor(tcs_s0, tcs_s1, tcs_s2, tcs_s3, tcs_out);
     int red = 0;
     int green = 0;
     int blue = 0;
     
     while (red == 0 || green == 0 || blue == 0) {
          red = sensor.readColor(LOW, LOW);
          Serial.print("Red value: ");
          sensor.printWarna(red);

          blue = sensor.readColor(LOW, HIGH);
          Serial.print("Blue value: ");
          sensor.printWarna(blue);

          green = sensor.readColor(HIGH, HIGH);
          Serial.print("Green value: ");
          sensor.printWarna(green);

          Serial.print('\n');
          delay(1000);
     }

     //SORTIR WARNA
     int warna;
     if(red < green && red < blue) {
          warna = 0; // 0 = MERAH
          Serial.print("Hasil warna: ");
          Serial.println("Merah");
     } else if (green < red && green < blue){
          warna = 2; // 2 = HIJAU
          Serial.print("Hasil warna: ");
          Serial.println("Hijau");
     } else if (blue < red && blue < green) {
          warna = 1; // 1 = BIRU
          Serial.print("Hasil warna: ");
          Serial.println("Biru");
     }

     switch (warna) {
          case 0: {
               //ROBOTIC ARM KE PENAMPUNGAN MERAH
               ArmMotion(0, 90, 180, 10, 250); // MENUJU CONVEYOR
               ArmMotion(3, 0, 120, 10, 250); // MEMBUKA CAPIT
               ArmMotion(2, 0, 110, 10, 250); // MENDEKATI CONVEYOR
               ArmMotionReverse(3, 150, 30, 10, 250); // MENUTUP CAPIT
               ArmMotionReverse(2, 120, 60, 10, 250); // MENJAUHI CONVEYOT
               ArmMotionReverse(0, 180, 10, 10, 250); // MENUJU PENAMPUNG MERAH
               ArmMotion(3, 30, 110, 10, 250); //MEMBUKA CAPIT
          } break;
          
          case 1: {
               //ROBOTIC ARM KE PENAMPUNGAN BIRU   
               ArmMotion(0, 90, 180, 10, 250);
               ArmMotion(3, 0, 120, 10, 250);
               ArmMotion(2, 0, 110, 10, 250);  
               ArmMotionReverse(3, 150, 30, 10, 250);
               ArmMotionReverse(2, 120, 60, 10, 250);
               ArmMotionReverse(0, 180, 60, 10, 250); // MENUJU PENAMPUNG BIRU
               ArmMotion(3, 30, 110, 10, 250);
          } break;

          case 2: {
               //ROBOTIC ARM KE PENAMPUNGAN HIJAU
               ArmMotion(0, 90, 180, 10, 250);
               ArmMotion(3, 0, 120, 10, 250);
               ArmMotion(2, 0, 110, 10, 250);  
               ArmMotionReverse(3, 150, 30, 10, 250);
               ArmMotionReverse(2, 120, 60, 10, 250);
               ArmMotionReverse(0, 180, 90, 10, 250); // MENUJU PENAMPUNG HIJAU
               ArmMotion(3, 30, 120, 10, 250);
          } break;
     } 
     delay(1000);

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
