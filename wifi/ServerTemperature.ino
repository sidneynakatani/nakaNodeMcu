#include "DHT.h"        // Including the library of DHT11
#define DHTTYPE DHT11  
#define dht_dpin 0 // Define Pin 0 (D3)

#include <ESP8266WiFi.h>
const char * ssid = "sua_rede";
const char * password = "senha";

WiFiServer server(8080);
DHT dht(dht_dpin, DHTTYPE); 

void setup() {
  Serial.begin(115200);
  dht.begin();
  delay(10);

  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");

  // Start the server
  server.begin();
  Serial.println("Server started");
  Serial.println(WiFi.localIP());
}

void loop() {
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  Serial.println("new client");
  if (!client.available()) {
    delay(10);
  }

  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  String buf = "";
  buf += "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n";
  buf += "<html lang=\"en\"><head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1, user-scalable=no\"/>\r\n";
  buf += "<title>ESP8266 Web Server</title>";
  buf += "<style>.c{text-align: center;} div,input{padding:5px;font-size:1em;} input{width:80%;} body{text-align: center;font-family:verdana;} button{border:0;border-radius:0.3rem;background-color:#1fa3ec;color:#fff;line-height:2.4rem;font-size:1.2rem;width:100%;} .q{float: right;width: 64px;text-align: right;}</style>";
  buf += "</head>";
  buf += "<h1>ESP8266 Web Server - External Temperature System Logs</h1>";
  buf += "<h3>Temperature:</h3>";
  buf += t;
  buf += "</html>\n";

  client.print(buf);
  client.flush();

  delay(500);
}
