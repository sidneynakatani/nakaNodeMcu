
#include "SSD1306.h" 
#include <Ultrasonic.h> // Include Ultrasonic library
 

SSD1306  display(0x3c, 5, 4); // Pin D1 = 5 / Pin D2 = 4
Ultrasonic ultrasonic(D7, D8); // D7 = Trigger / D8 = Echo

String distance;

void setup() {

  Serial.begin(115200);
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
   
    distance = String(ultrasonic.distanceRead());


    display.clear();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_10);
    display.drawString(0, 0, "Distance: "+ distance + " cm");
    
}
