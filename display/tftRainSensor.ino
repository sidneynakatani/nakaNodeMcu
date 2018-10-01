#include <TFT_ILI9163C.h>    //utilizada para se comunicar com o módulo LCD
const int pin_d = 0; // Pin D3 = 0  
const int pin_a = 0; // Pin A0 = 0

String digital;
String analog;

int val_d = 0; //Buffer Digital Value
int val_a = 0; //Buffer Analogic Value

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
    pinMode(pin_d, INPUT);
    pinMode(pin_a, INPUT);
    display.begin(); // inicialização para se comunicar com o módulo LCD
    display.clearScreen(); // limpa a tela, removendo todos os desenhos
    display.fillScreen(BLACK); // pinta a tela toda de preto
    display.setTextSize(1.5); // configura o tamanho do texto com o tamanho 1.5
    display.setTextColor(GREEN); // configura a cor do texto como verde
    display.setCursor(5,10); // posiciona o cursor para começar a escrita a partir do (x,y)
  
}

void loop(){

    delay(500);

    val_d = digitalRead(pin_d); //Read Digital Pin and buffer
    val_a = analogRead(pin_a);  //Read Analogic Pin and buffer

    digital = String(val_d);
    analog  = String(val_a);

  
    display.clearScreen(); // limpa a tela, removendo todos os desenhos
    display.fillScreen(BLACK); // pinta a tela toda de preto
    display.setTextSize(1.5); // configura o tamanho do texto com o tamanho 1.5
    display.setCursor(5,10); // posiciona o cursor para começar a escrita a partir do (x,y)
    display.print("Analog: "+analog); // escreve em tela
    display.setCursor(5,30); // posiciona o cursor para começar a escrita a partir do (x,y)
    display.print("Digit: "+digital); // escreve em tela
    
}
