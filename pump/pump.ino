int pump = 8;
int sensor_pin = A0;

int output_value ;

void setup() {                
  Serial.begin(9600);
  pinMode(pump, OUTPUT);
  
 Serial.println("Reading From the Sensor ...");

 delay(2000);     
}

void loop() {

  output_value= analogRead(sensor_pin);

  output_value = map(output_value,550,0,0,100);

  Serial.print("Mositure : ");
  Serial.print(output_value);

  Serial.println("%");


  if(output_value>=30 ){
    digitalWrite(pump, HIGH);
    }
    else{

      digitalWrite(pump, LOW);
      
      }
delay(1000);
}
