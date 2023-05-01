#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

class WebServer
{
private:
    ESP8266WebServer *webserver;
    void rootPage();
    void notfoundPage();
    String website_content = "Loading values..";

public:
    WebServer();
    void setup();
    void handleClient();
    void updatedValues(float temp, float hum, int ppm);
};