const int ledVert=8;
const int ledRouge=9;
const int ledJaune=10;

void setup() {
  pinMode(ledVert, OUTPUT);
  pinMode(ledRouge, OUTPUT);
  pinMode(ledJaune, OUTPUT);
  digitalWrite(ledVert, LOW);
  digitalWrite(ledRouge, LOW);
  digitalWrite(ledJaune, LOW);
  
 // initialize serial communication:
 Serial.begin(9600);
}

long dist1=0;
long dist2;
long vites = 0;
 
void loop()
{
 long duration, cm;
 //TODO : génération de l’impulsion de 5us (bien mettre à LOW pendant 2us avant de lancer l’impulsion HIGH)
  pinMode(3, OUTPUT);
  digitalWrite(3, LOW);
  delayMicroseconds(2);
  digitalWrite(3, HIGH);
  delayMicroseconds(2);
  pinMode(3, INPUT);
 //TODO : lecture de la durée
 duration = pulseIn(3, HIGH); 
 // convert the time into a distance
 cm = microsecondsToCentimeters(duration);
  dist2 = cm;
vites =((dist2-dist1)/0.1);
 
 if(cm <= 50){
     digitalWrite(ledRouge, HIGH);
     digitalWrite(ledVert, LOW);
     digitalWrite(ledJaune, LOW);
 }
 if(cm >50 && cm < 100){
      digitalWrite(ledRouge, LOW);
     digitalWrite(ledVert, LOW);
     digitalWrite(ledJaune, HIGH);
 }
  if(cm >100){
     digitalWrite(ledRouge, LOW);
     digitalWrite(ledVert, HIGH);
     digitalWrite(ledJaune, LOW);
 }
 
 Serial.print(vites);
 Serial.print("cm/micoSnde");
 Serial.println();

  dist1 = dist2;
 delay(100);
}

long vitesse(long deltaD,long deltaT){
  return deltaD/deltaT;
  }
long microsecondsToCentimeters(long microseconds)
{
 // The speed of sound is 340 m/s or 29 microseconds per centimeter.
 // The ping travels out and back, so to find the distance of the
 // object we take half of the distance travelled.
 return microseconds / 29 / 2;
}
