const int flame_sensor_pin = 0; // set number of the tilt switch pin D3 (0)                            
int flame_pin = HIGH ;                                  


void setup ( )  {
                   
  pinMode ( flame_sensor_pin , INPUT ) ;             
  Serial.begin ( 9600 ) ;                          

}

void loop ( ) {

   flame_pin = digitalRead ( flame_sensor_pin ) ;                

  if (flame_pin == LOW )  {
    Serial.println ( " FLAME , FLAME , FLAME " ) ;
  }

}
