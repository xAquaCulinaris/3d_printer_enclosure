#include "MHZ19.h"
#include <SoftwareSerial.h>

class MhzSensor
{
private:
    MHZ19 *myMHZ19;
    SoftwareSerial *mySerial;

public:
    MhzSensor();
    void setup();
    int measure_ppm();
};