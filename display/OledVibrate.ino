#include "SSD1306.h" 
const int sigPin = 0;  // set number of the tilt switch pin D3 (0)
boolean sigState = 0; // set sensor status

SSD1306  display(0x3c, 5, 4); // Pin D1 = 5 / Pin D2 = 4

String vibrated;


void setup() {

  Serial.begin(115200);
  pinMode(sigPin, INPUT); 
  display.init(); 
  display.flipScreenVertically();
  
  display.clear();
  drawMovement(); 
  display.display();
}

void loop() {
   
   drawMovement();
   display.display();

}

void drawMovement() {
    delay(100);

    sigState = digitalRead(sigPin);

    vibrated = "It is Ok!";

    if (sigState == LOW) { 
       vibrated = "Vibrated!";
    }

  
    display.clear();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_10);
    display.drawString(0, 0, "Alert: "+vibrated);
    
}
