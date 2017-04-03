const int Pin13 = 13;
const int switchPin = 8;
int switchState = 0;
 void setup() {
 pinMode(switchPin, INPUT); 
 pinMode(Pin13, OUTPUT); 
 }
 void loop(){
switchState = digitalRead(switchPin);
  if(switchState == HIGH){
    digitalWrite(Pin13, HIGH); // turn LED ON
    //delay(2);
  }
  else
    digitalWrite(Pin13, LOW);
 } 
