#include "SSD1306.h" 
SSD1306  display(0x3c, 5, 4); // Pin D1 = 5 / Pin D2 = 4


void setup() {

  Serial.begin(115200);
  display.init(); 
  display.flipScreenVertically();
  
  display.clear();
  drawHelloWorld(); 
  display.display();
}

void loop() {}

void drawHelloWorld() {

    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_10);
    display.drawString(0, 0, "Hello world");
    display.setFont(ArialMT_Plain_16);
    display.drawString(0, 10, "Hello world");
    display.setFont(ArialMT_Plain_24);
    display.drawString(0, 26, "Hello world");
}
