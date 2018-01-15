#include "DHT.h"        // Including the library of DHT11
#define DHTTYPE DHT11  
#define dht_dpin 0     // Define Pin 0 (D3)

DHT dht(dht_dpin, DHTTYPE); 

void setup(void) { 

  dht.begin();
  Serial.begin(9600);
  Serial.println("Humidity and temperature\n\n");
  delay(700);

}

void loop() {

    float h = dht.readHumidity();
    float t = dht.readTemperature();         
    Serial.print("Current humidity = ");
    Serial.print(h);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(t); 
    Serial.println("C  ");
    delay(800);
}
