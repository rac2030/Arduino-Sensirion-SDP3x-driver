
#include <inttypes.h>
#include <Wire.h>
#include "Arduino.h"
#include "SDP3x.h"

/******************************************************************************
 * Global Functions
 ******************************************************************************/

/**********************************************************
 * getPressureDiff
 *  Gets the current Pressure Differential from the sensor.
 *
 * @return float - The Pressure in Pascal
 **********************************************************/
float SDP3xClass::getPressureDiff(void)
{
  int16_t dp_ticks;
  // merge chars to one int
  dp_ticks = BIU16(readSensor(), 0);
  // adapt scale factor according to datasheet (here for version SDP31)
  float dp_scale = 60.0;
  return dp_ticks/dp_scale;
}

/**********************************************************
 * getTemperature
 *  Gets the current Temperature from the sensor.
 *
 * @return float - The Temperature
 **********************************************************/
float SDP3xClass::getTemperature(void)
{
  int16_t  temperature_ticks;
  // merge chars to one int
  temperature_ticks = BIU16(readSensor(), 3);
  float t_scale = 200.0;
  return temperature_ticks/t_scale;
}

/******************************************************************************
 * readSensor
 *  Gets RAW sensor data
 *
 * @return uint8_t - RAW sensor data
 ******************************************************************************/
uint8_t SDP3xClass::readSensor(void)
{
  uint8_t readData[6];
  uint8_t rxByteCount=0;
  
  // triggered mode with 50ms conversion time
  const uint8_t SDP_MEASUREMENT_COMMAND_0 = 0x36;
  const uint8_t SDP_MEASUREMENT_COMMAND_1 = 0x2F;
  
  uint8_t txData[2] = {SDP_MEASUREMENT_COMMAND_0, SDP_MEASUREMENT_COMMAND_1};

  Wire.beginTransmission(SDP3x_I2C_ADDRESS);
  Wire.write(txData, sizeof(txData));
  Wire.endTransmission();
  // wait for data conversion in sensor
  delay(50);

  // 2 bytes DP, 1 CRC, 2 bytes T, 1 CRC
  Wire.requestFrom(SDP3x_I2C_ADDRESS, (uint8_t)6);
  rxByteCount = 0;
  while (Wire.available()) { // wait till all arrive
      readData[rxByteCount] = Wire.read();
      rxByteCount++;
  }
  return readData;    
}

SDP3xClass SDP3x;


