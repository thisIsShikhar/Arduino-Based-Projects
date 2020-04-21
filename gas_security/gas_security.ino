#include <SoftwareSerial.h>
SoftwareSerial SIM900(7, 8); 
String textForSMS;
String textForSMS2;
int redLed = 13;
int smokeA0 = A0;
int sensorThres = 600;
int data = 0;

#include "DHT.h"
#define DHTPIN 2 
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);


void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
   SIM900.begin(9600); 

   Serial.begin(9600); 
  Serial.println("DHTxx test!");
  dht.begin();
}

void loop() {


  delay(2000);


  float h = dht.readHumidity();
  
  float t = dht.readTemperature();
 
  float f = dht.readTemperature(true);
  
  
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  
  
  float hi = dht.computeHeatIndex(f, h);

  Serial.print("Humidity: "); 
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: "); 
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(hi);
  Serial.println(" *F");



  
  int analogSensor = analogRead(smokeA0);
  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  if (analogSensor > sensorThres)
  {
    digitalWrite(redLed, HIGH);
    textForSMS =  "\nGas Detected";  
  sendSMS(textForSMS);
  Serial.println(textForSMS);
  Serial.println("message sent."); 
  delay(1000);
  
  
delay(5000);
while(1)
{
  
}
  }

  if(t>28){
    textForSMS2 =  "\nFire detected";
    sendSMS2(textForSMS2);
  Serial.println(textForSMS2);
  Serial.println("message sent2."); 

  delay(30000);


    textForSMS =  "\nExtreme Fire Detected";  
  sendSMS(textForSMS);
  Serial.println(textForSMS);
  Serial.println("message sent."); 
  delay(100000);
    }
}
 
 
void sendSMS(String message)
{
  SIM900.print("AT+CMGF=1\r");                     
  delay(1000);
 SIM900.println("AT + CMGS = \"+8801677922994\"");
 delay(1000);
  SIM900.println(message);                        
  delay(1000);
  SIM900.println((char)26);                     
  delay(1000); 
  SIM900.println();
  delay(100);                                  
      

}

void sendSMS2(String message)
{
  SIM900.print("AT+CMGF=1\r");                     
  delay(1000);
 SIM900.println("AT + CMGS = \"+8801824001298\"");
 delay(1000);
  SIM900.println(message);                        
  delay(1000);
  SIM900.println((char)26);                     
  delay(1000); 
  SIM900.println();
  delay(100);                                  
   

}
