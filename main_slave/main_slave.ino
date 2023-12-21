#include <SoftwareSerial.h>

SoftwareSerial btSerial(2,3); // TX, RX

bool direction_flag[2];
int motor_L = 8; // Left motor
int motor_R = 9; // Right motor

void setup() {
  btSerial.begin(38400); // HC-05 typically communicates at 9600 baud rate.
  pinMode(motor_L, OUTPUT); // Set pin 8 as output mode.
  pinMode(motor_R, OUTPUT); // Set pin 9 as output mode.
}

void loop() {
  // Receive the flag values from the master device.
  if(btSerial.available() >= 2) { // If more than 2 pieces of data arrive
    for(int i = 0; i < 2; i++) {
      direction_flag[i] = btSerial.read(); // Use the read() function to get the data
    }

    int speed = 255 * 70; // maxmimum * 0.70

    // Power the pin according to the received data.
    // Connect 8pin to Left motor. connect 9pin to Right motor.
    if(direction_flag[0] == 1 && direction_flag[1] == 0) {
      analogWrite(motor_L, speed); // Power the pin 8.
      analogWrite(motor_R, LOW); // Do not power the pin 9. Go to Left.
      delay(1000);
      analogWrite(motor_L, LOW); // Turn off the pin 8.
      analogWrite(motor_R, LOW); // Turn off the pin 9.
      delay(1000); // Wait for 1 second before the next vibration.
    }
    else if(direction_flag[0] == 0 && direction_flag[1] == 1) {
      analogWrite(motor_L, LOW); // Do not power the pin 8.
      analogWrite(motor_R, speed); // Power the pin 9. Go to Right.
      delay(1000);
      analogWrite(motor_L, LOW); // Turn off the pin 8.
      analogWrite(motor_R, LOW); // Turn off the pin 9.
      delay(1000); // Wait for 1 second before the next vibration.
    }
    else if(direction_flag[0] == 1 && direction_flag[1] == 1) {
      analogWrite(motor_L, speed); // power the pin 8.
      analogWrite(motor_R, speed); // power the pin 9. Go to straight.
      delay(1000);
      analogWrite(motor_L, LOW); // Turn off the pin 8.
      analogWrite(motor_R, LOW); // Turn off the pin 9.
      delay(1000); // Wait for 1 second before the next vibration.
    }
  }
}
