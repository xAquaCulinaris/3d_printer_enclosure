#include "dht_sensor.h"
#include "configuration.h"

DhtSensor::DhtSensor()
{
    dhtSensor = new DHT(DHTPIN, DHTTYPE);
}

void DhtSensor::setup()
{
    dhtSensor->begin();
}

float DhtSensor::measure_temp()
{
    float t = dhtSensor->readTemperature();
    return t;
}

float DhtSensor::measure_hum()
{
    float h = dhtSensor->readHumidity();
    return h;
}