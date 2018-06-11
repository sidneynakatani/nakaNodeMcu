#include "SSD1306.h" 
#include "DHT.h"        // Including the library of DHT11


#define DHTTYPE DHT11  
#define dht_dpin 0     // Define Pin 0 (D3)

DHT dht(dht_dpin, DHTTYPE); 
SSD1306  display(0x3c, 5, 4); // Pin D1 = 5 / Pin D2 = 4

String temp;

void setup() {

  Serial.begin(115200);
  dht.begin();
  display.init(); 
  display.flipScreenVertically();
  
  display.clear();
  drawTemperature(); 
  display.display();
}

void loop() {
   
   drawTemperature();
   display.display();

}

void drawTemperature() {
    delay(2000);

    float t = dht.readTemperature(); 
    temp = t;

    display.clear();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_10);
    display.drawString(0, 0, "Temperature: "+temp);
    
}
