
#include <Adafruit_Sensor.h>
#include "DHT.h"

class DhtSensor
{
private:
    DHT *dhtSensor;

public:
    DhtSensor();
    void setup();
    float measure_temp();
    float measure_hum();
};