int val = 0;

void setup(){
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop(){
  byte r_Data;
  digitalWrite(8, HIGH);//Ac off
  digitalWrite(9, HIGH);//heat off  
 int sense = analogRead(A1);
 val = map(sense, 0, 1023, 50, 105);
 delay(100); 
 Serial.println(val);
 if(Serial.available() > 0){
 r_Data = Serial.read()-'0';
 } 

 if(r_Data == 1){
   digitalWrite(9, LOW);//heat
   delay(2000);
 }
 if(r_Data == 2){
   digitalWrite(8, LOW); //AC
   delay(2000);
 }
}
 
 
 
 
