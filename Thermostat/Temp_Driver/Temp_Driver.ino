#include <DallasTemperature.h>
#include <OneWire.h>
#include <stdlib.h>;

///manditory third party libs for temp sensing
OneWire oneWire(12);
DallasTemperature sensors(&oneWire);

int val = 0;

void setup(){
  sensors.begin();//beigin sensing temp
  Serial.begin(9600);//start baud rate
  pinMode(8, OUTPUT);//uoutput pins
  pinMode(9, OUTPUT);
  digitalWrite(8, HIGH);//Ac off
  digitalWrite(9, HIGH);//heat off
}

void loop(){
 sensors.requestTemperatures();//request temp from sensor
 float current_temp1; 
 float farenheit;
 
 current_temp1= sensors.getTempCByIndex(0);///get the temp from an index
 farenheit =((current_temp1 * 1.8) + 32.0);//convert to farenheit
 
 delay(100);
 float sense = analogRead(A1);//read potentiometer
 val = map(sense, 0, 1023, 50, 105);//map values
 delay(100); 
 
 Serial.println(val);//print values over serial port
 Serial.println(current_temp1);
 
  int tempPlusFive = farenheit + 5;//calculate temps above and below by fiive degree offset
  int tempMinusFive = farenheit - 5;
  //if in +- 5 degrees turn heat and ac off
  if(val < tempPlusFive && val > tempMinusFive){
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
  }
  //outside of range above turn on heat
  else if(val >= tempPlusFive){
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);//heat
  }
  //below tange turn on ac
   else if(val <= tempMinusFive){
    digitalWrite(9, HIGH);
    digitalWrite(8, LOW);//AC
  }
 
}
 
 
 
 
