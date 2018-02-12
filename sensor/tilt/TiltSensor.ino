const int sigPin = 0;  // set number of the tilt switch pin D3 (0)
boolean sigState = 0;  // set tilt switch status


void setup() {
  // initialize the tilt switch pin as an input:
  pinMode(sigPin, INPUT); 
  //Init Serial
  Serial.begin(9600); 
}

void loop() {
  // read the state of the tilt switch value:
  sigState = digitalRead(sigPin);
  if (sigState == HIGH)
  { 
    Serial.println("Ativado.");
  } 
  else
  {
   Serial.println("Desativado.");
  }
  
}
