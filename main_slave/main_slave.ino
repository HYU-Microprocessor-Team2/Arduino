#include <SoftwareSerial.h>

SoftwareSerial btSerial(2,3); // RX, TX

bool direction_flag[2];

void setup() {
  btSerial.begin(9600); // HC-05 typically communicates at 9600 baud rate.
  DDRD = 0x03; // Set pin 8 and 9 as output mode.
}

void loop() {
  // Receive the flag values from the master device.
  if(btSerial.available() >= 2) { // If more than 2 pieces of data arrive
    for(int i = 0; i < 2; i++) {
      direction_flag[i] = btSerial.read(); // Use the read() function to get the data
    }

    // Power the pin according to the received data.
    // Connect 8pin to Left vibration. connect 9pin to Right vibration.
    if(direction_flag[0] == 1 && direction_flag[1] == 0) {
      digitalWrite(8, HIGH); // Power the pin 8.
      digitalWrite(9, LOW); // Do not power the pin 9. Go to Left
    }
    else if(direction_flag[0] == 0 && direction_flag[1] == 1) {
      digitalWrite(8, LOW); // Do not power the pin 8.
      digitalWrite(9, HIGH); // Power the pin 9. Go to Right
    }
    else if(direction_flag[0] == 1 && direction_flag[1] == 1) {
      digitalWrite(8, HIGH); // power the pin 8.
      digitalWrite(9, HIGH); // power the pin 9. Go to striaght
    }
  }
}