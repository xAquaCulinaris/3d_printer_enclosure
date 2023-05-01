#include "web_server.h"
#include "configuration.h"

WebServer::WebServer()
{
    webserver = new ESP8266WebServer(80);
}

void WebServer::setup()
{
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

    // Start Web Server
    webserver->on("/", [&]()
                  { rootPage(); });
    webserver->onNotFound([&]()
                          { notfoundPage(); });
    webserver->begin();
}

void WebServer::updatedValues(float temp, float hum, int ppm)
{
    website_content = "Tmp: " + String(temp) + "C\n";
    website_content += "Hum: " + String(hum) + "%\n";
    website_content += "CO2: " + String(ppm) + "ppm\n";
}

void WebServer::handleClient()
{
    webserver->handleClient();
}

// Handle Root
void WebServer::rootPage()
{
    webserver->send(200, "text/plain", website_content);
}

// Handle 404
void WebServer::notfoundPage()
{
    webserver->send(404, "text/plain", "404: Not found");
}
