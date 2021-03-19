/*
   @ Reference - https://protosupplies.com/product/gy-bme280-pressure-humidity-temperature-sensor-module/
   
   @ BME280 Sensor based temperature, pressure, humidity application
   
   Connect BME280 Vcc to 3.3V and GND to ground
   Need to install library Adafruit_BME280
   Need to manually install library Adafruit_Sensor
   
   @ MQTT client running on ESP8266 to collect data from BME280 and sending to Google cloud IoT
   using Google Cloud IoT Core JWT and Arduino MQTT libraries
*/
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <Wire.h>
#include <CloudIoTCore.h>
#include "esp8266_mqtt.h"
//#include "universal-mqtt.h"

float temperature;
float humidity;
float pressure;
float altitude;

float const ALTITUDE = 81.0;              // Altitude at my location in meters
float const SEA_LEVEL_PRESSURE = 1013.25;  // Pressure at sea level

Adafruit_BME280 bme; // I2C
#define PUBLISH_DELAY 1000 //1 sec

unsigned long delayTime;
unsigned long lastMillis = 0;

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
  
  /* call setupCloudIoT to setup the Wi-Fi, the device time, and to start an MQTT client */
  setupCloudIoT();
  
}
//===============================================================================
//  Main
//===============================================================================
void loop() {
  /*MQTT client loop*/
  mqttClient->loop();
  
  delay(10);//fixes some issues with WiFi stability
  
  if (!mqttClient->connected()) {//mqttClient client connection status
    connect();
  }
  
    // publish sensor data every 1sec.
  if (millis() - lastMillis > PUBLISH_DELAY) {
    lastMillis = millis();
    // Get sensor data
    getPressure();   
    getHumidity();
    getTemperature();
    getAltitude();
    
    //check sensor data is a valid number
    if (isnan(humidity) || isnan(temperature) || isnan(pressure) || isnan(altitude)) {
      Serial.println("BME280 sensor data reading issues");
      return;
    }
    
    /* create payload with current sendor data and payload */
    String payload = String("{\"timestamp\":") + time(nullptr) +
                     String(",\"temperature\":") + temperature +
                     String(",\"pressure\":") + pressure +
                     String(",\"humidity\":") + humidity +
                     String(",\"altitude\":") + altitude +
                     String("}");
    /* Publish data to Cloud IoT Core via MQTT Bridge */
    publishTelemetry(payload);
  }
  //delay(delayTime);     // Update readings every 1 seconds
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

//===============================================================================
//  getAltitude - Subroutine to get and print altitude
//===============================================================================
void getAltitude()
{
  Serial.print("Altitude = ");
  altitude = bme.readAltitude(SEA_LEVEL_PRESSURE); //in meters
  Serial.print(altitude);
  Serial.println(" meters");
}
