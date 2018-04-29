const int sigPin = 0;  // set number of the tilt switch pin D3 (0)
boolean sigState = 0;  // set sensor status


void setup() {
  // initialize the tilt switch pin as an input:
  pinMode(sigPin, INPUT); 
  //Init Serial
  Serial.begin(9600); 
}

void loop() {
  // read the state of sensor:
  sigState = digitalRead(sigPin);
  
  if (sigState == HIGH) { 
    Serial.println("vibrated.");
  } 
  
}
