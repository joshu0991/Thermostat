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
 char tmpC[6];
 char oTmp[6];
 
 current_temp1= sensors.getTempCByIndex(0);
 farenheit =((current_temp1 * 1.8) + 32.0);
 dtostrf(current_temp1, 6, 2, tmpC);
 
 delay(100);
 //Serial.print("Temperature "); Serial.println(farenheit);
 float sense = analogRead(A1);
 val = map(sense, 0, 1023, 50, 105);
 delay(100); 
 dtostrf(val, 6, 2, oTmp);
 
  Serial.println(tmpC);
 
  int controller = farenheit - val;
  
  if(controller >= 10){
    digitalWrite(8, LOW);//heat
    delay(5000);
    digitalWrite(8, HIGH);
  }
  if(controller <= -10){
  digitalWrite(9, LOW);//AC
  delay(5000);
  digitalWrite(9, HIGH);
  }
 
}
 
 
 
 
