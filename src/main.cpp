
#include <Arduino.h>
#include "configuration.h"
#include "mhz_sensor.h"
#include "dht_sensor.h"

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

MhzSensor *mhzSensor;
DhtSensor *dhtSensor;
unsigned long getDataTimer = 0;

// Create a new web server
ESP8266WebServer webserver(80);

// Handle Root
void rootPage()
{
  webserver.send(200, "text/plain", "Home Page!");
}

// Handle 404
void notfoundPage()
{
  webserver.send(404, "text/plain", "404: Not found");
}

void setup()
{
  Serial.begin(BAUDRATE);

  // Begin WiFi
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(100);
    Serial.print(".");
  }

  // WiFi Connected
  Serial.println("");
  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());

  mhzSensor = new MhzSensor();
  dhtSensor = new DhtSensor();

  mhzSensor->setup();
  dhtSensor->setup();

  // Start Web Server
  webserver.on("/", rootPage);
  webserver.onNotFound(notfoundPage);
  webserver.begin();
}

void loop()
{
  webserver.handleClient(); 

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

    // Reset 5 sec timer
    getDataTimer = millis();
  }
}
