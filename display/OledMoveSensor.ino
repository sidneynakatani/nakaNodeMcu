#include "SSD1306.h" 

 
SSD1306  display(0x3c, 5, 4); // Pin D1 = 5 / Pin D2 = 4
const int sigPin = 0;  // set number of the tilt switch pin D3 (0)
boolean sigState = 0; // set sensor status


String move;

void setup() {

  Serial.begin(115200);
  display.init(); 
  display.flipScreenVertically();
  pinMode(sigPin, INPUT); 
  
  display.clear();
  drawMoviment(); 
  display.display();
}

void loop() {
   
   drawMoviment();
   display.display();

}

void drawMoviment() {
   
    sigState = digitalRead(sigPin);

    if (sigState == HIGH) { 
	move = "Down";
    }else{
	move = "Up";
    }
    


    display.clear();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_10);
    display.drawString(0, 0, "Status: "+ move);
    
}
