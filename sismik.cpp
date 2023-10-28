#include <Servo.h>

//DEKLARASI PIN

//SENSOR ULTRASONIC
int trigPin = 2;
int echoPin = 3;

//SERVO
int servoRadar_attach = 9;
int servoLengan_attach = 10;
int servoSiku_attach = 11;
int servoPergelangan_attach = 12;
int servoJari_attach = 13;

//TCS3200
int tcs_s0 = 4;
int tcs_s1 = 5;
int tcs_s2 = 6;
int tcs_s3 = 7;
int tcs_out = 8;

//DEKLARASI VARIABEL
int jarak;
long waktu;
int sudutAwal = 00;

Servo servoRadar;
Servo servoLengan, servoSiku, servoPergelangan, servoJari;
int sudutLengan, sudutSiku, sudutPergelangan, sudutJari;

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
void setup (){

     Serial.begin(9600);
     //SERVO
     servoRadar.attach(servoRadar_attach);
     servoLengan.attach(servoLengan_attach);
     servoSiku.attach(servoSiku_attach);
     servoPergelangan.attach(servoPergelangan_attach);
     servoJari.attach(servoJari_attach);

     //ULTRASONIC
     pinMode(trigPin, OUTPUT);
     pinMode(echoPin, INPUT);

     //TCS3200
     pinMode(tcs_s0,OUTPUT);
     pinMode(tcs_s1,OUTPUT);
     pinMode(tcs_s2,OUTPUT);
     pinMode(tcs_s3,OUTPUT);
     pinMode(tcs_out,INPUT);

     digitalWrite(tcs_s0,HIGH);
     digitalWrite(tcs_s1,HIGH);
     
}

void loop() {
     //SERVO OBJECT DETECTOR
     sudutAwal = 00;
     for (int a = sudutAwal; a <= 180; a++) {
         printJarak();
         stepServoRadar(a);
     }
       
     for (int a = 180; a >= sudutAwal; a--){
         printJarak();
         stepServoRadar(a);
     }   

     stepServoJari(0);
     stepServoLengan(0);
     stepServoPergelangan(0);
     stepServoSiku(0);
     
     //SERVO ARM
     //LENGAN
     stepServoLengan(90); //0-180

     //SIKU
     stepServoSiku(0);

     //PERGELANGAN
     stepServoPergelangan(0);

     //JARI
     stepServoJari(0);
      
 

     //TCS3200
     TCS3200 sensor(tcs_s0, tcs_s1, tcs_s2, tcs_s3, tcs_out);

     int red = sensor.readColor(LOW, LOW);
     Serial.print("Red value: ");
     sensor.printWarna(red);

     int blue = sensor.readColor(LOW, HIGH);
     Serial.print("Blue value: ");
     sensor.printWarna(blue);

     int green = sensor.readColor(HIGH, HIGH);
     Serial.print("Green value: ");
     sensor.printWarna(green);

     Serial.print('\n');

     delay(1000);
}

//FUNGSI
void printJarak () {
     digitalWrite(trigPin, LOW);
     delayMicroseconds(2);
     digitalWrite(trigPin, HIGH);
     delayMicroseconds(10);
     digitalWrite(trigPin, LOW);
     waktu = pulseIn(echoPin, HIGH);
     jarak= waktu*0.034/2;
     Serial.println("Jarak: ");
     Serial.println(jarak);
}

void stepServoRadar (int x) {
     for (int a = 0; a <= x; a++) {
          servoRadar.write(x);
          delay(20);
     }
     
}

void stepServoLengan (int x) {
     for (int a = 0; a <= x; a++) {
          servoLengan.write(x);
          delay(1000);
     }
}

void stepServoSiku (int x) {
     for (int a = 0; a <= x; a++) {
          servoSiku.write(x);
          delay(1000);
     }
}

void stepServoPergelangan (int x) {
     for (int a = 0; a <= x; a++) {
          servoPergelangan.write(x);
          delay(1000);
     }
}

void stepServoJari (int x) {
     for (int a = 0; a <= x; a++) {
          servoJari.write(x);
          delay(1000);
     }
}









