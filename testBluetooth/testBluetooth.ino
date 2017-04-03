
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
String commande = "" ;
String start="";
String vitesse="";
String directio="";
String sens="";

void loop() { // run over and over   
      if (mySerial.available()) {
      char valeur = mySerial.read();
      if(valeur != '&'){
          commande.concat(valeur);
          }
        else{
          start = getValue(commande, ',',0);
          vitesse = getValue(commande, ',',1);
          directio = getValue(commande, ',',2);
          sens = getValue(commande, ',',3);
          Serial.print(start.toInt());
          Serial.print("\n");
          Serial.print(vitesse.toInt());
          Serial.print("\n");
          Serial.print(directio.toInt());
          Serial.print("\n");
          Serial.print(sens.toInt());
          Serial.print("\n");
          // Si la voiture est démarrée
          if(start == "1"){
            digitalWrite(ledVert,HIGH); // on allume ledVert
            digitalWrite(ledRouge,LOW); // on éteint ledRouge
            //demarrer(vitesse,direction) // fonction à définir
            }
          else{
          if(start == "0"){
            digitalWrite(ledVert,LOW); // on éteint ledVert
            digitalWrite(ledRouge, HIGH); //on allume ledRouge
            //stopper() //
            } 
        }
        commande = "";
          start = "";
          vitesse = "";
          directio = "";
          sens = "";          
      }     
    }
    Serial.flush(); 
}   

String getValue(String data, char separator, int index)
{
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;

    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}


