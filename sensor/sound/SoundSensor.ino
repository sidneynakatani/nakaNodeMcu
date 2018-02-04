//This code use Arduino sketch Plotter Serial to read signal.
// Tools > Plotter Serial


//Pin A0 
int analogic_pin = 0;


// Initial Value
int value_A0 = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(analogic_pin, INPUT);
}

void loop() {

  value_A0 = analogRead(analogic_pin);

  Serial.println(value_A0);
  
  delay(10);
 
}
