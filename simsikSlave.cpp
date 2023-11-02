#include <Wire.h>

//DEKLARASI I2C
int alamatSlave = 10;
int dataSlave = 0;

//DEKLARASI OBSTACLE
const int pinIR = 2;

void setup() {
  Serial.begin(9600);
  Wire.begin(alamatSlave);

  pinMode(pinIR, INPUT);
  Serial.println("Deteksi Sensor IR");
  delay(3000);
}

void loop() {


}

void sensorObstacle () {
    int sensorState = digitalRead(pinIR);
    if (sensorState == LOW) {
        Serial.println("Tedeteksi");
    } else {
        Serial.println("Tidak terdeteksi");
    }
    delay(500);
}

//DIKSUUUUUU