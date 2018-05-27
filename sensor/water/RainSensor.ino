const int pin_d = 0; //Set Pin D3 (0)  
const int pin_a = 0; //Set Pin A0 (0) 


int val_d = 0; //Buffer Digital Value
int val_a = 0; //Buffer Analogic Value


void setup() {

  //Setup Pins
  pinMode(pin_d, INPUT);
  pinMode(pin_a, INPUT);

  //Setup Serial
  Serial.begin(9600);
}

void loop() {

  val_d = digitalRead(pin_d); //Read Digital Pin and buffer
  val_a = analogRead(pin_a);  //Read Analogic Pin and buffer

  Serial.print("Digital : ");
  Serial.print(val_d);
  Serial.print(" - Analogic : ");
  Serial.println(val_a);
 
}
