#include "Arduino.h"
#include "WiFi.h"
#include "esp_websocket_client.h"
#include "conf.h"

WiFiClient client;

static TimerHandle_t shutdownSignal;

const esp_websocket_client_config_t websocketConfig = {
    .uri = strcat("ws//", serverUrl),
    .port = port,
};

void connect()
{
  client.connect(serverUrl, port);
}

static void handleEvent(void *args, esp_event_base_t base, int32_t eventId, void *eventData)
{
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

  esp_websocket_client_handle_t socketClient = esp_websocket_client_init(&websocketConfig);
  esp_websocket_register_events(socketClient, WEBSOCKET_EVENT_ANY, handleEvent, (void *)socketClient);

  esp_websocket_client_start(socketClient);
  xTimerStart(shutdownSignal, portMAX_DELAY);

  char data[32];
  int i = 0;
  while (i < 10)
  {
    if (esp_websocket_client_is_connected(socketClient))
    {
      int len = sprintf(data, "hello %04d", i++);
      Serial.println("Sending")
    }
  }
}

//https://github.com/espressif/esp-idf/blob/e5f5eb3cbb5d6cf65e25dd8d64f1cced36f2ca49/examples/protocols/websocket/main/websocket_example.c

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