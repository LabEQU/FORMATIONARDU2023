#ifndef _CONFIG_H_

#define _CONFIG_H_
/***
  PRESSURE
  ***/
#define BMP180
/***
  TEMPERATURE
  ***/
//#define BMP180_TEMPERATURE
//#define DUMMY_TEMPERATURE
#define DS18B20_TEMPERATURE
/***
  HUMIDITY
  ***/
#define HUMIDITY_SENSOR
/***
  SD
  ***/
#define SD_WRITE
/***
 OUTPUT
 ***/
//#define ST7735

//check config for multiple sensor type defined
#include "config_adv.h"
#endif
