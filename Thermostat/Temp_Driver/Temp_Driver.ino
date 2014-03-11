#include <DallasTemperature.h>
#include <OneWire.h>

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
 byte r_Data;
 sensors.requestTemperatures();
 float current_temp1; 
 current_temp1= sensors.getTempCByIndex(0);
 float farenheit =((current_temp1 * 1.8) + 32.0);
 delay(100);
 //Serial.print("Temperature "); Serial.println(farenheit);
 float sense = analogRead(A1);
 val = map(sense, 0, 1023, 50, 105);
 delay(100); 
 Serial.println(val);
 //String broadcast = (val + ", "+ farenheit + ", "+ current_temp1); 
 //Serial.println(broadcast);
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
 
 
 
 
