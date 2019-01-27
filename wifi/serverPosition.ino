const int sigPin = 0;  // set number of the tilt switch pin D3 (0)
boolean sigState = 0; // set sensor status
String move;

#include <ESP8266WiFi.h>
const char * ssid = "ssid";
const char * password = "password";
WiFiServer server(8080);

void setup() {

  Serial.begin(115200);
  pinMode(sigPin, INPUT); 
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

  sigState = digitalRead(sigPin);

  if (sigState == HIGH) { 
  move = "Down";
  }else{
  move = "Up";
  }

  String buf = "";
  buf += "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n";
  buf += "<html lang=\"en\"><head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1, user-scalable=no\"/>\r\n";
  buf += "<meta http-equiv=\"refresh\" content=\"5\">";
  buf += "<title>ESP8266 Web Server</title>";
  buf += "<style>.c{text-align: center;} div,input{padding:5px;font-size:1em;} input{width:80%;} body{text-align: center;font-family:verdana;} button{border:0;border-radius:0.3rem;background-color:#1fa3ec;color:#fff;line-height:2.4rem;font-size:1.2rem;width:100%;} .q{float: right;width: 64px;text-align: right;}</style>";
  buf += "</head>";
  buf += "<h1>ESP8266 Web Server - External Position System Logs</h1>";
  buf += "<h3>Sensor Position:</h3>";
  buf += move;
  buf += "</html>\n";

  client.print(buf);
  client.flush();

  delay(500);
}

