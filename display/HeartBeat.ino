#include "SSD1306.h" 
bool BPMTiming=false;
bool BeatComplete=false;

SSD1306  display(0x3c, 5, 4); // Pin D1 = 5 / Pin D2 = 4
int LastTime=0;
int BPM=0;

#define UpperThreshold 550
#define LowerThreshold 500

void setup() {
  Serial.begin(9600);
  display.init(); 
  display.flipScreenVertically();
  
  display.clear();
  drawHeartBeat(); 
  display.display();
}


void loop() {

  drawHeartBeat();
  display.display();
}

void drawHeartBeat() {

   int value=analogRead(0);
  
  if(value>UpperThreshold){
  
    if(BeatComplete){
      BPM=millis()-LastTime;
      BPM=int(60/(float(BPM)/1000));
      BPMTiming=false;
      BeatComplete=false;
    }
    
    if(BPMTiming==false){
      LastTime=millis();
      BPMTiming=true;
    }
  }
  if((value<LowerThreshold)&(BPMTiming))
    BeatComplete=true;

  display.clear();
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_10);
  display.drawString(0, 0, "BPM: "+ String(BPM));
  
}

