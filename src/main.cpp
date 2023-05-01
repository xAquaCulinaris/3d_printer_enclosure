
#include <Arduino.h>
#include "configuration.h"
#include "mhz_sensor.h"
#include "dht_sensor.h"

MhzSensor *mhzSensor;
DhtSensor *dhtSensor;
unsigned long getDataTimer = 0;

void setup()
{
  Serial.begin(BAUDRATE);

  mhzSensor = new MhzSensor();
  dhtSensor = new DhtSensor();

  mhzSensor->setup();
  dhtSensor->setup();
}

void loop()
{
  if (millis() - getDataTimer >= 5000)
  {
    // measure values
    int ppm = mhzSensor->measure_ppm();
    float temp = dhtSensor->measure_temp();
    float hum = dhtSensor->measure_hum();

    Serial.print("CO2: ");
    Serial.print(ppm);
    Serial.println("ppm");

    Serial.print("Tmp: ");
    Serial.print(temp);
    Serial.println("C");

    Serial.print("Hum: ");
    Serial.print(hum);
    Serial.println("%");

    Serial.println("");

    // Start 5 sec timer
    getDataTimer = millis();
  }
}
