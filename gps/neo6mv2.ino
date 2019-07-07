#include <SoftwareSerial.h>
#include <TimeLib.h>
#include <TinyGPS++.h>


//Pinagem TX para pino D1 e RX para o pino D2
static const int TXPin = 5, RXPin = 4;

//Instancia do TinyGPS++
TinyGPSPlus gps;

//Conexão serial do modulo GPS
SoftwareSerial Serial_GPS(TXPin, RXPin);

void setup()
{
  //Baud rate Arduino
  Serial.begin(115200);
  //Baud rate Modulo GPS
  Serial_GPS.begin(9600);

  Serial.println(F("Data, Hora, Latitude e Longitude"));
  Serial.println(F("Modulo GPS GY-NEO6MV2"));
  Serial.print(F("Biblioteca TinyGPS++ v. ")); 
  Serial.println(TinyGPSPlus::libraryVersion());
  Serial.println();
}

void loop(){

  while (Serial_GPS.available() > 0){
    if (gps.encode(Serial_GPS.read())){
      Serial.print(gps.location.lat(), 6); //latitude
      Serial.print(F(","));
      Serial.println(gps.location.lng(), 6); //longitude
    }
  }
}
