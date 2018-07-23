#include "SSD1306.h" 
const int sigPin = 0;  // set number of the tilt switch pin D3 (0)
const int flame_sensor_pin = 0; // set number of the tilt switch pin D3 (0)                            
int flame_pin = HIGH ;  

SSD1306  display(0x3c, 5, 4); // Pin D1 = 5 / Pin D2 = 4

String flame;


void setup() {

  Serial.begin(115200);
  pinMode ( flame_sensor_pin , INPUT ) ; 
  display.init(); 
  display.flipScreenVertically();
  
  display.clear();
  drawFire(); 
  display.display();
}

void loop() {
   
   drawFire();
   display.display();

}

void drawFire() {
    delay(10);

    flame_pin = digitalRead ( flame_sensor_pin ) ; 

    flame = "No Flame.";               

    if (flame_pin == LOW )  {
      flame = "Flame!"; 
    }

  
    display.clear();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_10);
    display.drawString(0, 0, "Alert: "+flame);
    
}
