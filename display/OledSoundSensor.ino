#include "SSD1306.h" 

 

SSD1306  display(0x3c, 5, 4); // Pin D1 = 5 / Pin D2 = 4
int A0_pin = 0; // Pin A0

int value_A0 = 0; // Initial Value

String analog;

void setup() {

  Serial.begin(115200);
  display.init(); 
  display.flipScreenVertically();
  
  pinMode(A0_pin, INPUT);
 
  
  display.clear();
  drawSound(); 
  display.display();
}

void loop() {
   
   drawSound();
   display.display();

}

void drawSound() {
   
    value_A0 = analogRead(A0_pin);  //Read Analogic Pin and buffer

    if (value_A0 > 20 && value_A0 < 300) {
      analog  = "LOW sound.";
    }

    if (value_A0 > 301 && value_A0 < 700){
        analog  = "MEDIUM sound.";
    }

    if (value_A0 > 701){
      analog  = "HIGH sound.";
    }


    display.clear();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_10);
    display.drawString(0, 0, "Level: "+ analog);
    display.drawString(0, 10, "Analogic: "+ String(value_A0));
    
}
