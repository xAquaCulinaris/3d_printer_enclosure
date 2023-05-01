#include <Arduino.h>
#include "configuration.h"
#include "mhz_sensor.h"

MhzSensor::MhzSensor()
{
    myMHZ19 = new MHZ19();
    mySerial = new SoftwareSerial(RX_PIN, TX_PIN);
}

void MhzSensor::setup()
{
    mySerial->begin(BAUDRATE);
    myMHZ19->begin(*mySerial);
}

int MhzSensor::measure_ppm()
{
    int CO2;                 // Buffer for CO2
    CO2 = myMHZ19->getCO2(); // Request CO2 (as ppm)

    //print error code if something went wrong
    if (myMHZ19->errorCode != RESULT_OK) 
    {
        Serial.println("Failed to recieve CO2 value - Error");
        Serial.print("Response Code: ");
        Serial.println(myMHZ19->errorCode); 
    }
    return CO2;
}
