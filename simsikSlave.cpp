#include <Wire.h>

//DEKLARASI I2C
int slaveAddress = 4;  // Alamat slave I2C

//DEKLARASI PIN
int obstaclePin = 2;     // Pin sensor inframerah terhubung ke pin 2
int relayPin = 7;        // Pin relay terhubung ke pin 7
bool obstacleDetected = false;
int temperatureValue = 0;

void setup() {
  Wire.begin(SLAVE_ADDRESS);
  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);
  pinMode(obstaclePin, INPUT);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);  // Relay mati saat awalnya
}

void loop() {
  // Membaca data dari sensor suhu (analog) dan sensor inframerah (digital)
  temperatureValue = analogRead(temperaturePin);
  obstacleDetected = digitalRead(obstaclePin);
  delay(100);
}

void receiveData(int byteCount) {
  while (Wire.available()) {
    // Menerima data dari master, jika diperlukan
  }
}

void sendData() {
  // Mengirim data dari kedua sensor dan status relay ke master
  Wire.write(obstacleDetected);
  Wire.write(digitalRead(relayPin));
}
