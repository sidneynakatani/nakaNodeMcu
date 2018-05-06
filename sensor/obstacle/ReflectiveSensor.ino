const int isObstaclePin = 0;   // set number of the tilt switch pin D3 (0)
int isObstacle = HIGH;  


void setup() {
  pinMode(isObstaclePin, INPUT);
  Serial.begin(9600);
}

void loop() {

  isObstacle = digitalRead(isObstaclePin);

  if (isObstacle == LOW){
    Serial.println("OBSTACLE!!");
  }

  delay(200);
}
