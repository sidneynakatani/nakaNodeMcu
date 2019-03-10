#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

// Replace with your network credentials
const char* ssid = "your-Wifi";
const char* password = "your-password";
ESP8266WebServer server(8080);  
 
const int isObstaclePin = 0; // Define o pino de entrada pin D3 (0)

String page = "";
String text = "";
String data = "";
int isObstacle = HIGH; 

void setup(void){

 Serial.begin(115200);
 pinMode(isObstaclePin, INPUT);
 WiFi.begin(ssid, password); //begin WiFi connection
 Serial.println("");

 // Wait for connection
 while (WiFi.status() != WL_CONNECTED) {
 delay(500);
 Serial.print(".");
}

 Serial.println("");
 Serial.print("Connected to ");
 Serial.println(ssid);
 Serial.print("IP address: ");
 Serial.println(WiFi.localIP());
 server.on("/data.txt", [](){
   text = (String)data;
   server.send(200, "text/html", text);
 });
 server.on("/", [](){
   page = "<h1>Sensor to Node MCU Web Server</h1><h1>Obstacle:</h1> <h1 id=\"data\">""</h1>\r\n";
   page += "<script>\r\n";
   page += "var x = setInterval(function() {loadData(\"data.txt\",updateData)}, 1000);\r\n";
   page += "function loadData(url, callback){\r\n";
   page += "var xhttp = new XMLHttpRequest();\r\n";
   page += "xhttp.onreadystatechange = function(){\r\n";
   page += " if(this.readyState == 4 && this.status == 200){\r\n";
   page += " callback.apply(xhttp);\r\n";
   page += " }\r\n";
   page += "};\r\n";
   page += "xhttp.open(\"GET\", url, true);\r\n";
   page += "xhttp.send();\r\n";
   page += "}\r\n";
   page += "function updateData(){\r\n";
   page += " document.getElementById(\"data\").innerHTML = this.responseText;\r\n";
   page += "}\r\n";
   page += "</script>\r\n";
   server.send(200, "text/html", page);
});

 server.begin();
 Serial.println("Web server started!");
}

void loop(void){

    isObstacle = digitalRead(isObstaclePin);
    data = "It is Ok!";

    if (isObstacle == LOW){
       data = "OBSTACLE!";
    }
 
   delay(1000);
   server.handleClient();
}

