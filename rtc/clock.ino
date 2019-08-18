#include <MyRealTimeClock.h>

MyRealTimeClock myRTC(5,4,0); // Assign Digital Pins 

void setup() {
Serial.begin(9600);


/* To set the current time and date in specific format 
| Second 00 | Minute 11 | Hour 21 | Week Day 06 | Day 17 |  Month 8 | Year 2019 |
*/

myRTC.setDS1302Time(00, 11, 21, 06, 17, 8, 2019);
}

void loop() {

// Allow the update of variables for time / accessing the individual element. 
myRTC.updateTime();

Serial.print("Current Date / Time: "); 
Serial.print(myRTC.dayofmonth); // Element 1
Serial.print("/"); 
Serial.print(myRTC.month); // Element 2
Serial.print("/");
Serial.print(myRTC.year); // Element 3
Serial.print(" ");
Serial.print(myRTC.hours); // Element 4
Serial.print(":");
Serial.print(myRTC.minutes); // Element 5
Serial.print(":");
Serial.println(myRTC.seconds); // Element 6
delay( 5000);
}
