 /* 
  * ---------------------    
  * | HC-SC04 | NodeMCU |   
  * ---------------------   
  * |   Vcc   |   5V    |     
  * |   Trig  |   D7    | 
  * |   Echo  |   D8    |   
  * |   Gnd   |   GND   |  
  * |-------------------| */ 

#include <Ultrasonic.h> // Include Ultrasonic library
 
Ultrasonic ultrasonic(D7, D8); // D7 = Trigger / D8 = Echo
 
void setup() { 
  Serial.begin(9600); 
}
 
void loop() {
  Serial.print("Distance: "); 
  Serial.print(ultrasonic.distanceRead());
  Serial.println("cm"); 
  delay(1000); 
}
