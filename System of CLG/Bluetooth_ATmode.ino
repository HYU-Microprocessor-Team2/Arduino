#include <SoftwareSerial.h>

SoftwareSerial btSerial(2, 3); // TX, RX

void setup() {
  Serial.begin(9600);
  btSerial.begin(38400); // HC-05 default baud rate is 38400
}

void loop() {
  if (btSerial.available()) {
    char data = btSerial.read();
    Serial.write(data);
  }

  if (Serial.available()) {
    char data = Serial.read();
    btSerial.write(data);
  }
}