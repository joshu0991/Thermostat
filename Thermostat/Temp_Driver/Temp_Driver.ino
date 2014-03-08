int val = 0;

void setup(){
  Serial.begin(9600);
}

void loop(){
 int sense = analogRead(A1);
 val = map(sense, 0, 1023, 50, 105);
 delay(100); 
 Serial.println(val);
 
}
 
 
 
 
