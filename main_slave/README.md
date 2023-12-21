#This is Code for main_slave. 
The code begins by including the SoftwareSerial library and defining the pins for the serial communication (TX and RX) and the motors. 
It also sets up a boolean array to keep track of the direction flags received from the master device.
it initializes the serial communication with the HC-05 module and sets the motor pins as output. it checks if there is data available from the master device. If there is, it reads the data and stores it in the direction_flag array. Based on the values received, the code then controls the motors.
