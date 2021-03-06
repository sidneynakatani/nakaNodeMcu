#include <TFT_ILI9163C.h>    //utilizada para se comunicar com o módulo LCD
const int flame_sensor_pin = 0; // set number of the tilt switch pin D3 (0)                            
int flame_pin = HIGH ;  


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

String flame;

void setup(void) {
   
    Serial.begin(115200);
    pinMode(flame_sensor_pin, INPUT); 
    display.begin(); // inicialização para se comunicar com o módulo LCD
    display.clearScreen(); // limpa a tela, removendo todos os desenhos
    display.fillScreen(BLACK); // pinta a tela toda de preto
    display.setTextSize(2); // configura o tamanho do texto com o tamanho 2
    display.setTextColor(GREEN); // configura a cor do texto como verde
    display.setCursor(5,10); // posiciona o cursor para começar a escrita a partir do (x,y)
  
}

void loop(){

    delay(100);

    flame_pin = digitalRead ( flame_sensor_pin ) ; 

    flame = "No Flame.";               

    if (flame_pin == LOW )  {
      display.setTextColor(RED); // configura a cor do texto como vermelho
      flame = "Flame!"; 
    }else{
      display.setTextColor(GREEN); // configura a cor do texto como verde
    }

  
    display.clearScreen(); // limpa a tela, removendo todos os desenhos
    display.fillScreen(BLACK); // pinta a tela toda de preto
    display.setTextSize(2); // configura o tamanho do texto com o tamanho 2
    display.setCursor(5,10); // posiciona o cursor para começar a escrita a partir do (x,y)
    display.print(flame); // escreve em tela
    
}
