const int controlPin1 = 2;
const int controlPin2 = 3;
const int enablelPin = 9;
const int directionSwitchPin = 4;
const int onOffSwitchStateSwitchPin = 5;
const int potPin = A0;
int onOffSwitchState = 0;
int previousOnOffSwitchState = 0;
int directionSwitchState = 0;
int previousDirectionSwitchState = 0;
int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 1;

void setup() {
  // put your setup code here, to run once:
   pinMode(directionSwitchPin, INPUT);
   pinMode(onOffSwitchStateSwitchPin, INPUT);
   pinMode(controlPin1, OUTPUT);
   pinMode(controlPin2, OUTPUT);
   pinMode(enablePin, OUTPUT);
   digitalWrite(enablePin, LOW);
   
}

void loop() {
  // put your main code here, to run repeatedly:
   onOffSwitchState = digitalRead(onOffSwitchStateSwitchPin);
   delay(1);
 

}
