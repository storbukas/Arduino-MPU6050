/*
 *  MPU6050 Triple Axis Gyroscope & Accelerometer. Temperature Example.
 *
 *  created 03 Feb 2021
 *  by Lars Erik Storbukås <https://github.com/storbukas>
 *
 *  Source: https://github.com/storbukas/MPU6050
 *  Original source: https://github.com/jarzebski/Arduino-MPU6050>
 *
 *  Licensed under the GPL-3.0 License
 *  https://www.gnu.org/licenses/gpl-3.0.en.html
 *
 */

// ---------------------------------------------------------------------
// INCLUDES
//
#include <Wire.h>
#include <MPU6050.h>

// ---------------------------------------------------------------------
// VARIABLES
//
MPU6050 mpu;

// ---------------------------------------------------------------------
// SETUP
//
void setup() 
{
  Serial.begin(115200);

  Serial.println("Initialize MPU6050");

  while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
  {
    Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
    delay(500);
  }
}

// ---------------------------------------------------------------------
// LOOP
//
void loop()
{
  float temp = mpu.readTemperature();

  Serial.print(" Temp = ");
  Serial.print(temp);
  Serial.println(" *C");
  
  delay(500);
}
