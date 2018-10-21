#include "SSD1306.h" 

SSD1306  display(0x3c, 5, 4); // Pin D1 = 5 / Pin D2 = 4

String byteRead;

void setup() {

  Serial.begin(9600);
  display.init(); 
  display.flipScreenVertically();
  
  display.clear();
  draw(); 
  display.display();
}

void loop() {
   
   draw();
   display.display();

}

void draw() {

    if (Serial.available()) {
   
        byteRead = Serial.readString();
        display.clear();
        display.setTextAlignment(TEXT_ALIGN_LEFT);
        display.setFont(ArialMT_Plain_10);
        display.drawString(0, 0, ">: " + byteRead);
    
    }
}
