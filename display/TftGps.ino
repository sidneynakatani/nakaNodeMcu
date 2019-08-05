#include <TFT_ILI9163C.h>    //utilizada para se comunicar com o módulo LCD
#include <SoftwareSerial.h>


#include <TimeLib.h>
#include <TinyGPS++.h>

//Pinagem TX para pino D3 e RX para o pino D2
static const int TXPin = 0, RXPin = 4;

//Instancia do TinyGPS++
TinyGPSPlus gps;

//Conexão serial do modulo GPS
SoftwareSerial Serial_GPS(TXPin, RXPin);

String lat = "0";
String lon = "0";
 
//Define as cores
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
 
#define __CS D1 // pino que conectaremos o CS do módulo LCD
#define __DC D4 // pino que conectaremos o RS do módulo LCD
 
TFT_ILI9163C display = TFT_ILI9163C(__CS, __DC); // construtor do objeto que utilizaremos para se comunicar com o módulo LCD
 
void setup(void) {
   
    Serial.begin(115200);
    Serial_GPS.begin(9600);
    display.begin(); // inicialização para se comunicar com o módulo LCD
    display.clearScreen(); // limpa a tela, removendo todos os desenhos
    display.fillScreen(BLACK); // pinta a tela toda de preto
    display.setTextSize(1.5); // configura o tamanho do texto com o tamanho 1.5
    display.setTextColor(GREEN); // configura a cor do texto como verde
    display.setCursor(5,10); // posiciona o cursor para começar a escrita a partir do (x,y)
 
}
 
void loop(){
    delay(1000);
    if (Serial_GPS.available() > 0){
      if (gps.encode(Serial_GPS.read())){
        
        lat = gps.location.lat(); //latitude
        lon = gps.location.lng(); //longitude
      }
    }
 
 
    display.clearScreen(); // limpa a tela, removendo todos os desenhos
    display.fillScreen(BLACK); // pinta a tela toda de preto
    display.setTextSize(1.5); // configura o tamanho do texto com o tamanho 1.5
    display.setCursor(5,10); // posiciona o cursor para começar a escrita a partir do (x,y)
    display.print("Lat: "+lat + " Lon: " + lon); // escreve em tela
   
}
