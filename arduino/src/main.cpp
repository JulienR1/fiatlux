#include "Arduino.h"
#include "WiFi.h"
#include "conf.h"

WiFiClient client;

void connect()
{
  client.connect(serverUrl, port);
}

void setup()
{
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi Connected.");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("MAC address: ");
  Serial.println(WiFi.macAddress());

  delay(3000);
}

void loop()
{
  if (client.connected())
  {
  }
  else
  {
    Serial.println("Client disconnected.");
    connect();
  }

  delay(3000);
}