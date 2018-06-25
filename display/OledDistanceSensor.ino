#include "SSD1306.h" 
const int isObstaclePin = 0;   // set number of the tilt switch pin D3 (0)


SSD1306  display(0x3c, 5, 4); // Pin D1 = 5 / Pin D2 = 4

String obstacle;
int isObstacle = HIGH; 

void setup() {

  Serial.begin(115200);
  pinMode(isObstaclePin, INPUT);
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
    delay(2000);

    isObstacle = digitalRead(isObstaclePin);

    obstacle = "It is Ok!";

    if (isObstacle == LOW){
       obstacle = "OBSTACLE!";
    }

  
    display.clear();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_10);
    display.drawString(0, 0, "Alert: "+obstacle);
    
}
