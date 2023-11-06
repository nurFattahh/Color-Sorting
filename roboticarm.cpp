#include <Servo.h>

//bacot lu adit s anjay mabar

Servo servo1;  // Buat objek Servo untuk servo pertama
Servo servo2;  // Buat objek Servo untuk servo kedua
Servo servo3;  // Buat objek Servo untuk servo ketiga

int pos1 = 0;    // Posisi awal servo base
int pos2 = 0;    // Posisi awal servo lengan
int pos3 = 150;    // Posisi awal servo siku
//int pos4 = 0;    // Posisi awal servo jari
int increment = 1; // Besaran perubahan sudut pada setiap iterasi
int delayTime = 15; // Waktu penundaan (kecepatan) dalam milidetik
int jeda = 3000; // Waktu jeda 3 detik (dalam milidetik)

void setup() {
  servo1.attach(9);  // Attach servo base ke pin 9
  servo2.attach(10); // Attach servo lengan ke pin 10
  servo3.attach(11); // Attach servo sikuk ke pin 11
  //servo4.attach(12);// Attach servo jari ke pin 12
}

void loop() {
  // Bergerak dari sudut 0 hingga 180 dengan increment 1 pada servo 1
  for (pos1 = 0; pos1 <= 180; pos1 += increment) {
    servo1.write(pos1);  // Set posisi servo 1
    delay(delayTime);    // Tunggu sebentar
  }

  // Tunggu selama 3 detik
    delay(jeda);

    // Bergerak dari sudut 0 hingga 180 dengan increment 1 pada servo 2
  for (pos2 = 0; pos2 <= 90; pos2 += increment) {
    servo2.write(pos2);  // Set posisi servo 2
    delay(delayTime);    // Tunggu sebentar
  }

  // Tunggu selama 3 detik
  delay(jeda);

    // Bergerak dari sudut 90 hingga 0 dengan increment -1 pada servo 3
  for (pos3 = 90; pos3 >= 0; pos3 -= increment) {
    servo3.write(pos3); //Set posisi servo 3
    delay(delayTime); // Tunggu sebentar
  }
  
  // Tunggu selama 3 detik
  delay(jeda);
  
    // Bergerak dari sudut 0 hingga 90 dengan increment 1 pada servo 3
  for (pos3 = 0; pos3 <= 90; pos3 += increment) {
    servo3.write(pos3); //Set posisi servo 3
    delay(delayTime); // Tunggu sebentar
  }
  
  // Tunggu selama 3 detik
  delay(jeda);

  // Bergerak dari sudut 180 hingga 0 dengan increment -1 pada servo 2
  for (pos2 = 90; pos2 >= 0; pos2 -= increment) {
    servo2.write(pos2);  // Set posisi servo 2
    delay(delayTime);    // Tunggu sebentar
  }
  
  // Tunggu selama 3 detik
  delay(jeda);

  // Bergerak dari sudut 180 hingga 0 dengan increment -1 pada servo 1
  for (pos1 = 180; pos1 >= 0; pos1 -= increment) {
    servo1.write(pos1);  // Set posisi servo 1
    delay(delayTime);    // Tunggu sebentar
  }

  // Tunggu selama 3 detik
  delay(jeda);

  // Bergerak dari sudut 0 hingga 180 dengan increment 1 pada servo 2
  for (pos2 = 0; pos2 <= 90; pos2 += increment) {
    servo2.write(pos2);  // Set posisi servo 2
    delay(delayTime);    // Tunggu sebentar
  }

  // Tunggu selama 3 detik
  delay(jeda);

      // Bergerak dari sudut 0 hingga 45 dengan increment 1 pada servo 3
  for (pos3 = 90; pos3 >= 0; pos3 -= increment) {
    servo3.write(pos3); //Set posisi servo 3
    delay(delayTime); // Tunggu sebentar
  }
  
  // Tunggu selama 3 detik
  delay(jeda);
  
    // Bergerak dari sudut 45 hingga 0 dengan increment -1 pada servo 3
  for (pos3 = 0; pos3 <= 90; pos3 += increment) {
    servo3.write(pos3); //Set posisi servo 3
    delay(delayTime); // Tunggu sebentar
  }
  
  // Tunggu selama 3 detik
  delay(jeda);

  // Bergerak dari sudut 180 hingga 0 dengan increment -1 pada servo 2
  for (pos2 = 90; pos2 >= 0; pos2 -= increment) {
    servo2.write(pos2);  // Set posisi servo 2
    delay(delayTime);    // Tunggu sebentar
  }
  delay(jeda);
}

