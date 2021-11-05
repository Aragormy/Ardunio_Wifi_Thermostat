#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

// wifi connection variables
const char* ssid = "MINT-Technikum";
const char* password = "labornetzteil";

const unsigned int localPort = 8888;

WiFiUDP UDP;

void setup() {
    // Initialise Serial connection
    Serial.begin(115200);

    boolean state = true;
    WiFi.begin(ssid, password);

    delay(1000);

    Serial.println("");
    Serial.println("Connecting to WiFi");

    // Wait for connection
    Serial.print("Connecting");
    for(int i = 0; i < 10 && WiFi.status() != WL_CONNECTED; ++i)
    {
        delay(500);
    }

    if(WiFi.status() != WL_CONNECTED)
    {
        Serial.println("");
        Serial.println("Connection failed.");
        return;
    }

    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    Serial.println("");
    Serial.println("Connecting to UDP");

    if(UDP.begin(localPort) == 1)
    {
        Serial.println("Connection successful");
    }
    else
    {
        Serial.println("Connection failed");
    }
}

void loop()
{
    Serial.println("Hello World");
}