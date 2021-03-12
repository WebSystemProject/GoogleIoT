/*
   @ Reference - https://protosupplies.com/product/gy-bme280-pressure-humidity-temperature-sensor-module/
   
   @ BME280 Sensor based temperature, pressure, humidity application
   
   Connect BME280 Vcc to 3.3V and GND to ground
   Need to install library Adafruit_BME280
   Need to manually install library Adafruit_Sensor
*/
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <Wire.h>

float temperature;
float humidity;
float pressure;

float const ALTITUDE = 81.0;              // Altitude at my location in meters

Adafruit_BME280 bme; // I2C

unsigned long delayTime;

//===============================================================================
//  Initialization
//===============================================================================
void setup(void) {

  bool status;

  Serial.begin(9600);
  Serial.println(F("BME280 test"));

  // default settings
  status = bme.begin(0x76);  // The I2C address of the sensor is 0x76
  if (!status) {             // Loop if sensor not found
    Serial.println("Can't find BME280 sensor, check connection");
    while (1);
  }
  Serial.println("BME280 sensor found and begin");
  delayTime = 1000;
  Serial.println();
  
}
//===============================================================================
//  Main
//===============================================================================
void loop() {
  // Get sensor data
  getPressure();   
  getHumidity();
  getTemperature();
  
  delay(delayTime);     // Update readings every 1 seconds
}
//===============================================================================
//  getTemperature - Subroutine to get and print temperature
//===============================================================================
void getTemperature()
{
  Serial.print("Temperature = ");
  temperature = bme.readTemperature();
  temperature = temperature * 9 / 5 + 32; // Convert C to F
  Serial.print(temperature);
  Serial.println(" *F");

}
//===============================================================================
//  getHumidity - Subroutine to get and print humidity
//===============================================================================
void getHumidity()
{
  Serial.print("Humidity = ");
  humidity = bme.readHumidity();
  Serial.print(humidity);
  Serial.println(" %");
}
//===============================================================================
//  getPressure - Subroutine to get and print pressure
//===============================================================================
void getPressure()
{
  Serial.print("Pressure = ");
  pressure = bme.readPressure();
  pressure = bme.seaLevelForAltitude(ALTITUDE, pressure);
  pressure = pressure / 3386.39;    // Convert hPa to in/Hg
  Serial.print(pressure);
  Serial.println(" Hg");
}

