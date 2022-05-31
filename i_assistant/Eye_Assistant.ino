
const int trigPin1 = 6;
const int echoPin1 = 7;


const int trigPin2 = 2;
const int echoPin2 = 3;


const int trigPin3 =5;
const int echoPin3 = 4;

int vib1 = 10;
int vib3 = 8;


long duration1;
long duration2;
long duration3;


int buzzer=11;


int distance1;
int distance2;
int distance3;

int x=0;
void setup() {
pinMode(buzzer, OUTPUT);

pinMode(vib1, OUTPUT); 

pinMode(vib3, OUTPUT); 


pinMode(trigPin1, OUTPUT); 
pinMode(echoPin1, INPUT); 
pinMode(trigPin2, OUTPUT); 
pinMode(echoPin2, INPUT);
pinMode(trigPin3, OUTPUT); 
pinMode(echoPin3, INPUT);

Serial.begin(9600); 
}
void loop() {
digitalWrite(trigPin1, LOW);
delay(20);
digitalWrite(trigPin1, HIGH);
delay(10);
digitalWrite(trigPin1, LOW);
duration1 = pulseIn(echoPin1, HIGH);
distance1= duration1*0.034/2;
Serial.print("Distance1: ");
Serial.println(distance1);



digitalWrite(trigPin2, LOW);
delay(20);
digitalWrite(trigPin2, HIGH);
delay(10);
digitalWrite(trigPin2, LOW);
duration2 = pulseIn(echoPin2, HIGH);
distance2= duration2*0.034/2;
Serial.print("Distance2: ");
Serial.println(distance2);



digitalWrite(trigPin3, LOW);
delay(20);
digitalWrite(trigPin3, HIGH);
delay(10);
digitalWrite(trigPin3, LOW);
duration3 = pulseIn(echoPin3, HIGH);
distance3= duration3*0.034/2;
Serial.print("Distance3: ");
Serial.println(distance3);





if (distance1<10){
  digitalWrite(buzzer,HIGH);
  delay(500);
    digitalWrite(buzzer,LOW);
  delay(500);
    
  digitalWrite(vib1,HIGH);
}

else if (distance2<15){
    digitalWrite(buzzer,HIGH);
  delay(100);
    digitalWrite(buzzer,LOW);
  delay(100);
  digitalWrite(vib3,HIGH);
  digitalWrite(vib1,HIGH);
}

else if (distance3<10){
  digitalWrite(buzzer,HIGH);
  delay(1000);
    digitalWrite(buzzer,LOW);
  delay(1000);
  digitalWrite(vib3,HIGH);

}

else{
    digitalWrite(buzzer,LOW);
  digitalWrite(vib3,LOW);
  digitalWrite(vib1,LOW);
  
}



}