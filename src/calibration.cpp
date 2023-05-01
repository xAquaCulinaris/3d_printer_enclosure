// #include <Arduino.h>
// #include "MHZ19.h"

// #define RX_PIN 5
// #define TX_PIN 4
// #define BAUDRATE 9600

// MHZ19 myMHZ19;
// #include <SoftwareSerial.h>              //  Remove if using HardwareSerial or non-uno compatible device
// SoftwareSerial mySerial(RX_PIN, TX_PIN); // (Uno example) create device to MH-Z19 serial

// unsigned long timeElapse = 0;

// void setup()
// {
//     Serial.begin(9600);

//     mySerial.begin(BAUDRATE); // sensor serial
//     myMHZ19.begin(mySerial);  // pass to library

//     myMHZ19.autoCalibration(false); // make sure auto calibration is off
//     Serial.print("ABC Status: ");
//     myMHZ19.getABC() ? Serial.println("ON") : Serial.println("OFF"); // now print it's status

//     Serial.println("Waiting 20 minutes to stabilize...");
//     /* if you don't need to wait (it's already been this amount of time), remove the 2 lines */
//     timeElapse = 12e5; //  20 minutes in milliseconds
//     delay(timeElapse); //  wait this duration

//     Serial.println("Calibrating..");
//     myMHZ19.calibrate(); // Take a reading which be used as the zero point for 400 ppm
// }

// void loop()
// {
//     if (millis() - timeElapse >= 2000) // Check if interval has elapsed (non-blocking delay() equivalent)
//     {
//         int CO2;
//         CO2 = myMHZ19.getCO2();

//         Serial.print("CO2 (ppm): ");
//         Serial.println(CO2);

//         int8_t Temp;                     // Buffer for temperature
//         Temp = myMHZ19.getTemperature(); // Request Temperature (as Celsius)

//         Serial.print("Temperature (C): ");
//         Serial.println(Temp);

//         timeElapse = millis(); // Update interval
//     }
// }