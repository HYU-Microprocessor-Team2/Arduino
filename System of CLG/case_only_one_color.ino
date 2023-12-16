struct Boolpair {
  bool first;
  bool second;
};


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