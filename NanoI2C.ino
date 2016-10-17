#include <Wire.h>
#include <RPLidar.h>
RPLidar lidar;          // define lidar as RPLIDAR Object
#define RPLIDAR_MOTOR 3 // motor pin for lidar speed control

void setup() {
  pinMode(RPLIDAR_MOTOR, OUTPUT); // set lidar speed control pin as output
  lidar.begin(Serial);            // begin communication with lidar
  Wire.begin(8);                  // join i2c bus with address 8 as SLAVE
  Wire.onRequest(requestEvent);   // call "requestEvent" function when receives a request
  Wire.onReceive(receiveEvent);   // call "receiveEvent" function when receives a byte
}
int left = 0;                     // variable for detected points on left hand side
int right = 0;                    // variable for detected points on right hand side
unsigned long time = millis();    // time variable for reseting variables

int c1;                           // variable for received integer

void receiveEvent(int bytes){
       // read the received byte as integer.
}

void requestEvent() {
   // receive byte as a character
   // if master requests a char ("1"), send right data
   // if master requests a char ("2"), send left data
  
}

void loop() {
  
  if (IS_OK(lidar.waitPoint())) {                         // if lidar is working properly (wait point less than timeout)
    // read angle and distance
    // filter data (keep data of desired range and angle)
    // reset obstacle variables every 1 second
  } else {                                                  // if lidar is not responding 
    analogWrite(RPLIDAR_MOTOR, 0);                          //stop the rplidar motor
    rplidar_response_device_info_t info;                    // try to detect RPLIDAR...
    if (IS_OK(lidar.getDeviceInfo(info, 100))) {            // if detected,                         // Dont change this......
      lidar.startScan();                                    // start scan
      analogWrite(RPLIDAR_MOTOR, 255);                      // start motor rotating at max allowed speed (duty cycle =100%)
      delay(1000);                                      
    }
  }
}


