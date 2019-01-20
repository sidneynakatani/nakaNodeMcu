#include <ESP8266WiFi.h>
const char * ssid = "ssid";
const char * password = "yourPass";

// Assign output variables to GPIO D1 
const int output5 = 5; 


WiFiServer server(8080);

void setup() {
  Serial.begin(115200);
  delay(10);

  pinMode(output5, OUTPUT);
  digitalWrite(output5, HIGH);


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

  String buf = "";

  buf += "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n";
  buf += "<html lang=\"en\"><head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1, user-scalable=no\"/>\r\n";
  buf += "<title>ESP8266 Web Server</title>";
  buf += "<style>.c{text-align: center;} div,input{padding:5px;font-size:1em;} input{width:80%;} body{text-align: center;font-family:verdana;} button{border:0;border-radius:0.3rem;background-color:#1fa3ec;color:#fff;line-height:2.4rem;font-size:1.2rem;width:100%;} .q{float: right;width: 64px;text-align: right;}</style>";
  buf += "</head>";
  buf += "<h3>ESP8266 Web Server - System Logs</h3>";
  buf += "<p>GPIO5 <a href=\"?function=on\"><button>ON</button></a> <a href=\"?function=off\"><button>OFF</button></a></p>";
  buf += "<h4>Teste WEB - Led</h4>";
  buf += "</html>\n";

  client.print(buf);
  client.flush();

  

  if (req.indexOf("/?function=on") != -1){
    Serial.println("ON");
    digitalWrite(output5, HIGH);
  }
  if (req.indexOf("/?function=off") != -1){
    Serial.println("OFF");
    digitalWrite(output5, LOW);
  }
}
