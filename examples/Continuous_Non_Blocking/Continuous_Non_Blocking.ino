/* This example shows how to use continuous mode in a non blocking way to take
range measurements with the VL53L0X. It is based on
vl53l0x_ContinuousRanging_Example.c from the VL53L0X API.

The range readings are in units of mm. */

#include <Wire.h>
#include <VL53L0X_mod.h>

VL53L0X sensor;

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  sensor.setTimeout(500);
  if (!sensor.init())
  {
    Serial.println("Failed to detect and initialize sensor!");
    while (1) {}
  }


  sensor.startContinuous(200);
}

void loop()
{
  uint16_t NewMeasurement;
  Serial.print(".");
  if(sensor.readRangeNoBlocking(NewMeasurement)){
      Serial.println(".");
        Serial.println(NewMeasurement);


  }

//  Serial.println();
}
