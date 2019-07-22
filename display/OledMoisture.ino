#include "SSD1306.h" 

 

SSD1306  display(0x3c, 5, 4); // Pin D1 = 5 / Pin D2 = 4
int val;

void setup() {

  Serial.begin(115200);
  display.init(); 
  display.flipScreenVertically();
  
  display.clear();
  drawMoisture(); 
  display.display();
}

void loop() {
   
   drawMoisture();
   display.display();

}

void drawMoisture() {
   
    val = analogRead(A0); //connect sensor to Analog 0
    display.clear();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_10);
    display.drawString(0, 0, "Analogic: "+ String(val));
    
}
