#include <Wire.h>
#include <Adafruit_TCS34725.h>
#include <SoftwareSerial.h>
// TCA9548A I2C address
#define TCAADDR 0x70

SoftwareSerial btSerial(2, 3);
class RGB {
  public:
    float R,G,B,C;
    // Constructor
    RGB(float r, float g, float b, float c) : R(r), G(g), B(b), C(c) {}

    // If we want to change RGB values, we can only use the method in order to obey the rule of OOP
    void setR(float r) { R = r; }
    void setG(float g) { G = g; }
    void setB(float b) { B = b; }
    void setC(float c) { C = c; }

    // For the Classification, we needs maximum value
    float max_RGB() {
      float max_RGB = R;
      if (G > max_RGB) max_RGB = G;
      if (B > max_RGB) max_RGB = B;
      
      return max_RGB;
    }
    

    char Classification() {
      float color = max_RGB(); // Using the values derived from mar_RGB, Classify RGB Colors
      
      if (color == R) return 'R';
      if (color == G) return 'G';
      if (color == B) return 'B';
    }
    
    bool isWhite() {
      bool red_condition = 85 < R < 120;
      bool green_condition = 85 < G < 115;
      bool blue_condition = 85 < B < 115;
      bool clear_condition = C > 2000;
    
      if (red_condition && green_condition && blue_condition && clear_condition) {return 1;}
      else {return 0;}
    }

};


/////////////////////////////////////
//    Define Array of TCS34725     //
//    Integration time = 101ms     //
//    Gain(Sensitivity) = 60       //
/////////////////////////////////////
Adafruit_TCS34725 tcs[4] = {
  Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS , TCS34725_GAIN_60X),
  Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS , TCS34725_GAIN_60X),
  Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS , TCS34725_GAIN_60X),
  Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS , TCS34725_GAIN_60X)
};

RGB Sensor_RGB[4] = {
    RGB(0.0f, 0.0f, 0.0f, 0.0f),
    RGB(1.0f, 1.0f, 1.0f, 1.0f),
    RGB(2.0f, 2.0f, 2.0f, 2.0f),
    RGB(3.0f, 3.0f, 3.0f, 3.0f)
};

/////////////////////////////
// Add description for TCA9548A
void tcaselect(uint8_t i) {
  if (i > 7) return;

  Wire.beginTransmission(0x70);
  Wire.write((1 << i));
  Wire.endTransmission();
}

uint8_t left_LED_Pins[] = {8, 9, 10};
uint8_t right_LED_Pins[] = {7, 6, 5};

void left_LED_on() {
  for (uint8_t i = 0; i < 3; i++) {
    digitalWrite(left_LED_Pins[i], HIGH); // LED Light on
    delay(200);
    digitalWrite(left_LED_Pins[i], LOW); // LED Light off
  }
}

void left_LED_off() {
  for (uint8_t i = 0; i < 3; i++) {
    digitalWrite(left_LED_Pins[i], LOW); // LED Light off
  }
}

void right_LED_on() {
  for (uint8_t i = 0; i < 3; i++) {
    digitalWrite(right_LED_Pins[i], HIGH); // LED Light on
    delay(200);
    digitalWrite(right_LED_Pins[i], LOW); // LED Light off
  }
}

void right_LED_off() {
  for (uint8_t i = 0; i < 3; i++) {
    digitalWrite(right_LED_Pins[i], LOW); // LED Light off
  }
}

void leftBlinker() {

  bool Sensor_isWhite_list[4] = {0, 0, 0, 0};

  while (1) { // wait that any sensor read the white value
    if ((Sensor_isWhite_list[0]) || (Sensor_isWhite_list[1]) || (Sensor_isWhite_list[2])) {break;}
    left_LED_on();

    for (uint8_t i = 0; i < 4; i++) {
      tcaselect(i);
      
      uint16_t r, g, b, c;
      
      tcs[i].setInterrupt(false);
      tcs[i].getRawData(&r, &g, &b, &c);
      tcs[i].setInterrupt(true);
      
      float red_data = r / float(c) * 255 * 1.463;
      float green_data = g / float(c) * 255;
      float blue_data = b / float(c) * 255 * 1.25;
      float clear_data = c * 1.6;

      Sensor_RGB[i].setR(red_data);
      Sensor_RGB[i].setG(green_data);
      Sensor_RGB[i].setB(blue_data);
      Sensor_RGB[i].setC(clear_data);
      
      Serial.println(red_data);
      Serial.println(green_data);
      Serial.println(blue_data);
      Serial.println(clear_data);
      // Serial.print("R : ");
      // Serial.print(red_data);
      // Serial.print(" G : ");
      // Serial.print(green_data);
      // Serial.print("  B : ");
      // Serial.print(blue_data);
      // Serial.print("  C : ");
      // Serial.print(clear_data);
      

      char is_this_white = Sensor_RGB[i].isWhite();
      char white_char;
      
      if (is_this_white == 1) {white_char = 'W';}
      else {white_char = 'B';}

      Sensor_isWhite_list[i] = is_this_white;
      btSerial.print("   Sensor ");
      btSerial.print(i);
      btSerial.print(" is reading ");
      btSerial.println(white_char);

    }
  }
  
  while(1) {
    if((Sensor_isWhite_list[1]) || (Sensor_isWhite_list[2]) || (Sensor_isWhite_list[3]) ) {break;}
    left_LED_on();
    for (uint8_t i = 0; i < 4; i++) {
      tcaselect(i);
      
      uint16_t r, g, b, c;
      
      tcs[i].setInterrupt(false);
      tcs[i].getRawData(&r, &g, &b, &c);
      tcs[i].setInterrupt(true);
      
      float red_data = r / float(c) * 255 * 1.463;
      float green_data = g / float(c) * 255;
      float blue_data = b / float(c) * 255 * 1.25;
      float clear_data = c * 1.6;
      
      Sensor_RGB[i].setR(red_data);
      Sensor_RGB[i].setG(green_data);
      Sensor_RGB[i].setB(blue_data);
      Sensor_RGB[i].setC(clear_data);

      char is_this_white = Sensor_RGB[i].isWhite();
      Sensor_isWhite_list[i] = is_this_white;
    }
  }

  // while((Sensor_isWhite_list[0]) | (Sensor_isWhite_list[1]) | (Sensor_isWhite_list[2]) | (Sensor_isWhite_list[3])) {
  //   left_LED_on();
  //   for (uint8_t i = 0; i < 4; i++) {
  //     tcaselect(i);
      
  //     uint16_t r, g, b, c;
      
  //     tcs[i].setInterrupt(false);
  //     tcs[i].getRawData(&r, &g, &b, &c);
  //     tcs[i].setInterrupt(true);
      
  //     float red_data = r / float(c) * 255 * 1.463;
  //     float green_data = g / float(c) * 255;
  //     float blue_data = b / float(c) * 255 * 1.25;
  //     float clear_data = c * 1.3734;

  //     Sensor_RGB[i].setR(red_data);
  //     Sensor_RGB[i].setG(green_data);
  //     Sensor_RGB[i].setB(blue_data);
  //     Sensor_RGB[i].setC(clear_data);
      
  //     char is_this_white = Sensor_RGB[i].isWhite();
  //     Sensor_isWhite_list[i] = is_this_white;
  //   }
  // }

  left_LED_off();
}

void rightBlinker() {
  bool Sensor_isWhite_list[4] = {0, 0, 0, 0};

  while (1) { // wait that any sensor read the white value
    if ((Sensor_isWhite_list[1]) || (Sensor_isWhite_list[2]) || (Sensor_isWhite_list[3] )) { break;}
    right_LED_on();

    for (uint8_t i = 0; i < 4; i++) {
      tcaselect(i);
      
      uint16_t r, g, b, c;
      
      tcs[i].setInterrupt(false);
      tcs[i].getRawData(&r, &g, &b, &c);
      tcs[i].setInterrupt(true);
      
      float red_data = r / float(c) * 255 * 1.463;
      float green_data = g / float(c) * 255;
      float blue_data = b / float(c) * 255 * 1.25;
      float clear_data = c * 1.6;

      Sensor_RGB[i].setR(red_data);
      Sensor_RGB[i].setG(green_data);
      Sensor_RGB[i].setB(blue_data);
      Sensor_RGB[i].setC(clear_data);
    
      char is_this_white = Sensor_RGB[i].isWhite();
      char white_char;
      
      if (is_this_white == 1) {white_char = 'W';}
      else {white_char = 'B';}

      Sensor_isWhite_list[i] = is_this_white;
      btSerial.print("Sensor ");
      btSerial.print(i);
      btSerial.print(" is reading ");
      btSerial.println(white_char);

      }
    }
  
  while(1) {
      if((Sensor_isWhite_list[0]) || (Sensor_isWhite_list[1]) || (Sensor_isWhite_list[2])) {break;}
      right_LED_on();
      for (uint8_t i = 0; i < 4; i++) {
      tcaselect(i);
      
      uint16_t r, g, b, c;
      
      tcs[i].setInterrupt(false);
      tcs[i].getRawData(&r, &g, &b, &c);
      tcs[i].setInterrupt(true);
      
      float red_data = r / float(c) * 255 * 1.463;
      float green_data = g / float(c) * 255;
      float blue_data = b / float(c) * 255 * 1.25;
      float clear_data = c * 1.6;

      Sensor_RGB[i].setR(red_data);
      Sensor_RGB[i].setG(green_data);
      Sensor_RGB[i].setB(blue_data);
      Sensor_RGB[i].setC(clear_data);

      char is_this_white = Sensor_RGB[i].isWhite();
      Sensor_isWhite_list[i] = is_this_white;
    }
  }

  // while((Sensor_isWhite_list[0]) && (Sensor_isWhite_list[1]) && (Sensor_isWhite_list[2]) && (Sensor_isWhite_list[3])) {
  //   right_LED_on();
    
  //   for (uint8_t i = 0; i < 4; i++) {
  //     tcaselect(i);
      
  //     uint16_t r, g, b, c;
      
  //     tcs[i].setInterrupt(false);
  //     tcs[i].getRawData(&r, &g, &b, &c);
  //     tcs[i].setInterrupt(true);
      
  //     float red_data = r / float(c) * 255 * 1.463;
  //     float green_data = g / float(c) * 255;
  //     float blue_data = b / float(c) * 255 * 1.25;
  //     float clear_data = c * 1.3734;

  //     Sensor_RGB[i].setR(red_data);
  //     Sensor_RGB[i].setG(green_data);
  //     Sensor_RGB[i].setB(blue_data);
  //     Sensor_RGB[i].setC(clear_data);

  //     char is_this_white = Sensor_RGB[i].isWhite();
  //     Sensor_isWhite_list[i] = is_this_white;
  //   }
  // }
  right_LED_off();
}



void setup() {
  btSerial.begin(115200);
  Serial.begin(115200);
  Wire.begin();
  Wire.setClock(100000);

  // Initialize 4 TCS34725 Sensors by using TCA9548A
  for (uint8_t i = 0; i < 4; i++) {
    tcaselect(i);
    delay(50);
    if (tcs[i].begin()) {
      btSerial.print("Sensor ");
      btSerial.print(i);
      btSerial.println(" is successfully found");
    } else { // If Connection is not complete...
      btSerial.print("Sensor ");
      btSerial.print(i);
      btSerial.println(" is not found.")
      ;
      while (1);
    }
  }
}

void loop() {
  char lane_change_direction;
  while (btSerial.available()) {
    lane_change_direction = btSerial.read();
  }
  
  if (lane_change_direction == 'L') {
    leftBlinker();
    lane_change_direction = 'n';
    }
  else if (lane_change_direction == 'R') {
    rightBlinker();
    lane_change_direction = 'n';
    }
  // for (uint8_t i = 0; i < 4; i++) {
  //   tcaselect(i);
    
  //   uint16_t r, g, b, c;
    
  //   tcs[i].setInterrupt(false);
  //   tcs[i].getRawData(&r, &g, &b, &c);
  //   tcs[i].setInterrupt(true);
    
  //   float red_data = r / float(c) * 255 * 1.463;
  //   float green_data = g / float(c) * 255;
  //   float blue_data = b / float(c) * 255 * 1.25;

  //   Sensor_RGB[i].setR(red_data);
  //   Sensor_RGB[i].setG(green_data);
  //   Sensor_RGB[i].setB(blue_data);
  //   Sensor_RGB[i].setC(c);

  //   bool is_this_white = Sensor_RGB[i].isWhite();
    
  //   char white_char;
    
  //   if(is_this_white == 1) {white_char = 'W';}
  //   else {white_char = 'B';}

  //   Serial.print("Sensor ");
  //   Serial.print(i);
  //   Serial.print(" is reading : ");
  //   Serial.println(white_char);
  //   Serial.print("R : ");
  //   Serial.print(red_data);
  //   Serial.print(" G: ");
  //   Serial.print(green_data);
  //   Serial.print(" B: ");
  //   Serial.print(blue_data);
  //   Serial.print(" C : ");
  //   Serial.println(c);
  // }
}
