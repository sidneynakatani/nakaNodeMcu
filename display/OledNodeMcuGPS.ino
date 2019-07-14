#include "SSD1306.h" 
#include <SoftwareSerial.h>
#include <TimeLib.h>
#include <TinyGPS++.h>


SSD1306  display(0x3c, 5, 4); // Pin D1 = 5 / Pin D2 = 4

//Pinagem TX para pino D3 e RX para o pino D4
static const int TXPin = 0, RXPin = 2;

//Instancia do TinyGPS++
TinyGPSPlus gps;

//Conexão serial do modulo GPS
SoftwareSerial Serial_GPS(TXPin, RXPin);

String lat = "0";
String lon = "0";

void setup() {

  Serial.begin(115200);
  Serial_GPS.begin(9600);
  display.init(); 
  display.flipScreenVertically();
  
  display.clear();
  drawDistance(); 
  display.display();
}

void loop() {
   
   drawDistance();
   display.display();

}

void drawDistance() {
   
    if (Serial_GPS.available() > 0){
      if (gps.encode(Serial_GPS.read())){
        
        lat = gps.location.lat(); //latitude
        lon = gps.location.lng(); //longitude
      }
    }

  
    display.clear();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_10);
    display.drawString(0, 0, "Lat: "+lat);
    display.drawString(0, 9, "Lon: "+lon);
    
}
