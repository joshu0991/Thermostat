int val = 0;

void setup(){
  Serial.begin(9600);
}

void loop(){
 int sense = analogRead(A1);
 val = map(sense, 0, 1023, 50, 105); 
 Serial.println(val); 
 delay(250);
}
