#include <Servo.h>

//DEKLARASI PIN
int trigPin = 2;
int echoPin = 3;

//DEKLARASI VARIABEL
int jarak;
long waktu;
int sudutAwal_servo1 = 00;

Servo servo1;
Servo servoLengan, servoSiku, servoPergelangan, servoJari;
int sudutLengan, sudutSiku, sudutPergelangan, sudutJari;

//FUNGSI PROTOTYPE
void printJarak ();
void servo1Step (int x);

//MAIN
void setup (){
     servo1.attach(9);
     pinMode(trigPin, OUTPUT);
     pinMode(echoPin, INPUT);
     Serial.begin(9600);
     
}

void loop() {
     //SERVO OBJECT DETECTOR
     sudutAwal = 00;
     for (int a = sudutAwal; a <= 180; a++) {
         printJarak();
         servo1Step(a);
     }
       
     for (int a = 180; a >= sudutAwal; a--){
         printJarak();
         servo1Step(a);
     }   

     //SERVO ARM
     //LENGAN


     //SIKU

     //PERGELANGAN

     //JARI


}


//FUNGSI
void servo1Step (int x) {
     servo1.write(x);
     delay(20);
}

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

