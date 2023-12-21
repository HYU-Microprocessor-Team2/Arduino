#include <Wire.h>
#include <Adafruit_TCS34725.h>
#include <SoftwareSerial.h>

// TCA9548A I2C address
#define TCAADDR 0x70

class RGB {
  public:
    float R,G,B;
    // Constructor
    RGB(float r, float g, float b) : R(r), G(g), B(b) {}

    // If we want to change RGB values, we can only use the method in order to obey the rule of OOP
    void setR(float r) { R = r; }
    void setG(float g) { G = g; }
    void setB(float b) { B = b; }

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
};

uint8_t one_lane_how_many_colors(RGB RGB_L, RGB RGB_R) {
  char LEFT_COLOR = RGB_L.Classification();
  char RIGHT_COLOR = RGB_R.Classification();
  
  if (LEFT_COLOR == RIGHT_COLOR) return 1;
  else return 2;
}

struct Boolpair {
  bool first;
  bool second;
};

char two_sensor_classification(RGB RGB_0, RGB RGB_1) {
  float new_R = RGB_0.R + RGB_1.R;
  float new_G = RGB_0.G + RGB_1.G;
  float new_B = RGB_0.B + RGB_1.B;

  RGB new_RGB(new_R, new_G, new_B);
  
  return new_RGB.Classification();
}

struct Boolpair case_only_one_color(char input_RGB, char input_direction, char Sensor_RGB) {
  Boolpair Flag = {0, 0};

  if (input_RGB == Sensor_RGB) {
    Flag.first = 1;
    Flag.second = 1;
    }
  else {
    // The case that input direction is Left and vehicle is located in the right lane
    if (input_direction == 'L') {
      Flag.first = 1;
      Flag.second = 0;
    }
    else { // The case that input direction is Right and vehicle is located in the Left lane
      Flag.first = 0;
      Flag.second = 1;
    }
  }
  return Flag;
}

struct Boolpair case_two_colors(char input_RGB, char input_direction, char Left_Sensor_RGB, char Right_Sensor_RGB) {
  Boolpair Flag = {0, 0};

  if ((input_RGB == Left_Sensor_RGB) & (input_RGB != Right_Sensor_RGB)) {
    //In this case, there are two cases if the vehicle is driving in a country that uses right-hand traffic
    if (input_direction == 'L' | input_direction == 'S' ) {
      Flag.first = 1;
      Flag.second = 0;
    }
    else { // This means that there are something wrong in terms of input direction.
      Serial.println("Error! This is not possible path.");
    }
  }

  else if ((input_RGB == Right_Sensor_RGB) & (input_RGB != Left_Sensor_RGB)) {
    if (input_direction == 'R' | input_direction == 'S') {
      Flag.first = 0;
      Flag.second = 1;
    }
    else { // This means that there are something wrong in terms of input direction.
      Serial.println("Error! This is not possible path.");
    }
  }
  else { // This means that there are something wrong in terms of input color.
    Serial.println("Error! This is not possible path.");
  }
  
  return Flag;
}


/////////////////////////////////////
//    Define Array of TCS34725     //
//    Integration time = 154ms     //
//    Gain(Sensitivity) = 60       //
/////////////////////////////////////
Adafruit_TCS34725 tcs[4] = {
  Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS , TCS34725_GAIN_60X),
  Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS , TCS34725_GAIN_60X),
  Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS , TCS34725_GAIN_60X),
  Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS , TCS34725_GAIN_60X)
};

RGB Sensor_RGB[4] = {
    RGB(0.0f, 0.0f, 0.0f),
    RGB(1.0f, 1.0f, 1.0f),
    RGB(2.0f, 2.0f, 2.0f),
    RGB(3.0f, 3.0f, 3.0f)
};

/////////////////////////////
// Add description for TCA9548A
void tcaselect(uint8_t i) {
  if (i > 7) return;

  Wire.beginTransmission(0x70);
  Wire.write((1 << i));
  Wire.endTransmission();
}

char input_direction;
char input_color;
SoftwareSerial btSerial_HM10(2, 3); // RX, TX
SoftwareSerial btSerial_HC05(11, 12);

void setup(void) {
  Serial.begin(115200);
  btSerial_HM10.begin(115200);
  
  Wire.begin();
  Wire.setClock(100000);

  // Receive the direction of input
  Serial.println("input_direction : ");
  while (btSerial_HM10.available() == 0) {
    ; // Wait for input
  }
  
  input_direction = btSerial_HM10.read();
  delay(100); // Wait until processing is complete

  while (btSerial_HM10.available() > 0) {
    btSerial_HM10.read(); // Remove the character from buffers
  }

  delay(200);
  // Receive the color of input
  Serial.println("input_color : ");
  while (btSerial_HM10.available() == 0) {
    ; // Wait for input
  }
  
  input_color = btSerial_HM10.read();

  btSerial_HC05.begin(38400);
  // Initialize 4 TCS34725 Sensors by using TCA9548A
  for (uint8_t i = 0; i < 4; i++) {
    tcaselect(i);
    delay(50);
    if (tcs[i].begin()) {
      Serial.print("Sensor ");
      Serial.print(i);
      Serial.println(" is successfully found");
    } else { // If Connection is not complete...
      Serial.print("Sensor ");
      Serial.print(i);
      Serial.println(" is not found.")
      ;
      // while (1);
    }
  }

    for (uint8_t i = 3; i < 4; i++) {
    tcaselect(i);
    
    uint16_t r, g, b, c;
    
    tcs[i].setInterrupt(false);
    tcs[i].getRawData(&r, &g, &b, &c);
    tcs[i].setInterrupt(true);
    
    float red_data = r / float(c) * 255 * 1.463;
    float green_data = g / float(c) * 255;
    float blue_data = b / float(c) * 255 * 1.25;

    Sensor_RGB[i].setR(red_data);
    Sensor_RGB[i].setG(green_data);
    Sensor_RGB[i].setB(blue_data);
    }
} 
 
void loop() {
  //////////////////////////////////
  for (uint8_t i = 0; i < 4; i++) {
    tcaselect(i);
    
    uint16_t r, g, b, c;
    
    tcs[i].setInterrupt(false);
    tcs[i].getRawData(&r, &g, &b, &c);
    tcs[i].setInterrupt(true);
    
    float red_data = r / float(c) * 255 * 1.463;
    float green_data = g / float(c) * 255;
    float blue_data = b / float(c) * 255 * 1.25;

    Sensor_RGB[i].setR(red_data);
    Sensor_RGB[i].setG(green_data);
    Sensor_RGB[i].setB(blue_data);
  }

  bool flag[2]; // Index zero : Left,  Index one : Right
  uint8_t number_lane_color = one_lane_how_many_colors(Sensor_RGB[1], Sensor_RGB[2]);
  btSerial_HM10.println(number_lane_color);
  if (number_lane_color == 1) {
    char middle_Sensor_RGB = two_sensor_classification(Sensor_RGB[1], Sensor_RGB[2]);
    Boolpair result = case_only_one_color(input_color, input_direction, middle_Sensor_RGB);
    flag[0] = result.first;
    flag[1] = result.second;
  }
  else {
    char left_Sensor_RGB = two_sensor_classification(Sensor_RGB[0], Sensor_RGB[1]);
    char right_Sensor_RGB = two_sensor_classification(Sensor_RGB[2], Sensor_RGB[3]);
    Boolpair result = case_two_colors(input_color, input_direction, left_Sensor_RGB, right_Sensor_RGB);
    flag[0] = result.first;
    flag[1] = result.second;
  }
  btSerial_HM10.print("L_Flag = ");
  btSerial_HM10.println(flag[0]);
  btSerial_HM10.print("R_Flag = ");
  btSerial_HM10.println(flag[1]);
  for(int i = 0; i < 2; i++) {
    btSerial_HC05.write(flag[i]);
    delay(30);
  }
  
}