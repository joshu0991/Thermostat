#include <DallasTemperature.h>
#include <OneWire.h>
#include <stdlib.h>;

OneWire oneWire(12);
DallasTemperature sensors(&oneWire);

int val = 0;

void setup(){
  sensors.begin();
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(8, HIGH);//Ac off
  digitalWrite(9, HIGH);//heat off
}

void loop(){
 sensors.requestTemperatures();
 float current_temp1; 
 float farenheit;
 
 current_temp1= sensors.getTempCByIndex(0);
 farenheit =((current_temp1 * 1.8) + 32.0);
 
 delay(100);
 float sense = analogRead(A1);
 val = map(sense, 0, 1023, 50, 105);
 delay(100); 
 
 Serial.println(val);
 Serial.println(current_temp1);
 
  int tempPlusFive = farenheit + 5;
  int tempMinusFive = farenheit - 5;
  
  if(val < tempPlusFive && val > tempMinusFive){
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
  }
  else if(val >= tempPlusFive){
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);//heat
  }
   else if(val <= tempMinusFive){
    digitalWrite(9, HIGH);
    digitalWrite(8, LOW);//AC
  }
 
}
 
 
 
 
