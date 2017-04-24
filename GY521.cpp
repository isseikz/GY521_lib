#include "GY521.h"
#define MPU 0x68

#include <Wire.h>

int get_value(int addr){
  Wire.beginTransmission(0x68);
  Wire.write(addr);
  Wire.endTransmission(false);
  Wire.requestFrom(0x68,14,true);  // request a total of 14 registers
  int accel =Wire.read()<<8|Wire.read();
  return accel;
}

void initialize_gy521(){
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
}

int acceleration_z(){
  return get_value(0x3F);
}

int acceleration_x(){
  return get_value(0x3B);
}


int acceleration_y(){
  return get_value(0x3D);
}

int temperature_z(){
  return get_value(0x42);
}

int gyro_x(){
  return get_value(0x44);
}

int gyro_y(){
  return get_value(0x46);
}

int gyro_z(){
  return get_value(0x48);
}
