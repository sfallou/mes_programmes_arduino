
#include <SoftwareSerial.h>
const int ledVert = 6;
const int ledJaune = 5;
const int ledRouge = 4;
SoftwareSerial mySerial(10, 11); // RX, TX

int val1 = 0; 
int val2 = 0; 
int val3 = 0; 

void setup() {
  pinMode(ledVert, OUTPUT);
  pinMode(ledJaune, OUTPUT);
  pinMode(ledRouge, OUTPUT);
  // Open serial communications and wait for port to open:
  Serial.begin(57600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("Goodnight moon!");
  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  //mySerial.println("Hello, world?");
  digitalWrite(ledVert, LOW);
  digitalWrite(ledJaune, LOW);
  digitalWrite(ledRouge, LOW);
  //
 
}
String p = "" ;
String x="";
String y="";
void loop() { // run over and over   
      if (mySerial.available()) {
      char valeur = mySerial.read();
      if(valeur != '&'){
          p.concat(valeur);
          }
        else{
          y= p.substring(p.indexOf(',')+1);
          x= p.substring(0,p.indexOf(','));
          //x= x.toInt();
          //y= y.toInt();
          Serial.print(x.toInt());
          Serial.print("\n");
          Serial.print(y.toInt());
          Serial.print("\n");
          // Si la voiture est démarrée
          if(x == "1"){
            digitalWrite(ledVert,HIGH); // on allume ledVert
            digitalWrite(ledRouge,LOW); // on éteint ledRouge
            //demarrer(vitesse,direction) // fonction à définir
            }
          if(x == "0"){
            digitalWrite(ledVert,LOW); // on éteint ledVert
            digitalWrite(ledRouge, HIGH); //on allume ledRouge
            //stopper() //
            }  
          p = "";
          x = "";
          y = "";
          }     
    }
    //delay(1000);
    
}



