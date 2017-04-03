
#include <SoftwareSerial.h>
#include <Servo.h>
// --- Déclaration des constantes des broches E/S numériques ---

const int vitesseMotA=3; // Constante pour la broche 3
const int sensMotA=12; // Constante pour la broche 12
const int freinMotA=9; // Constante pour la broche 9
const int intensiteMotA=A0; // intensité du moteur 0

const int vitesseMotB=11; // Constante pour la broche 11
const int sensMotB=13; // Constante pour la broche 13
const int freinMotB=8; // Constante pour la broche 8
const int intensiteMotB=A1; // intensité du moteur 1

const int ledVert = 6;

SoftwareSerial mySerial(4, 5); // RX, TX
Servo myServo;

void setup() {
  // ------- Broches en sorties numériques -------  
 pinMode (vitesseMotA,OUTPUT); // Broche vitesseMotA configurée en sortie
 pinMode (freinMotA,OUTPUT); // Broche freinMotA configurée en sortie
 pinMode (vitesseMotB,OUTPUT); // Broche vitesseMotB configurée en sortie
 pinMode (sensMotA,OUTPUT); // Broche sensMotA configurée en sortie
 pinMode (sensMotB,OUTPUT); // Broche senMotB configurée en sortie
 pinMode(ledVert, OUTPUT);
 myServo.attach(7);
  // ------- Codes d'initialisation utile -------  
 digitalWrite(vitesseMotA,LOW); // a l'arret
 digitalWrite(sensMotA,LOW); 
 digitalWrite(freinMotA,LOW); // frein off 
 digitalWrite(vitesseMotB,LOW); // à l'arret 
 digitalWrite(sensMotB,LOW);
 digitalWrite(freinMotB,LOW); // frein off 
 digitalWrite(ledVert, LOW);
  // Open serial communications and wait for port to open:
 Serial.begin(57600);
 while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("Goodnight moon!");
  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  
}
// Les données envoyées par l'application
String commande = "" ;
String start="";
String vitesse="";
String directio="";
String sens="";
int angle;

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
            //digitalWrite(ledVert,HIGH); // on allume ledVert
            //demarrer(vitesse,direction) // fonction à définir
            //angle = map(directio.toInt(),0,1023,0,179);
            demarrer();
            angle = directio.toInt();
            Serial.print("angle: ");
            Serial.print(angle);
            Serial.print("\n");
            myServo.write(angle);
            //delay(150);
            // 
            }
          else{
          if(start == "0"){
            //digitalWrite(ledVert,LOW); // on éteint ledVert
            arret();
            
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

void demarrer(){
  digitalWrite(ledVert,HIGH); // on allume ledVert
  myServo.write(66);
  //delay(2000); // 2 secondes
  //--- moteur A ---- 
  //- sens 1
  digitalWrite(sensMotA,LOW); // sens 1
  digitalWrite(vitesseMotA, HIGH); // vitesse maximale
  //delay(2000); // 2 secondes
  //digitalWrite(vitesseMotA, LOW); // vitesse maximale
  //----- moteur B ---- 
  //- sens 1
  digitalWrite(sensMotB,LOW); // sens 1
  digitalWrite(vitesseMotB, HIGH); // vitesse maximale
  //delay(10000); // 10 secondes
}

void arret(){
  digitalWrite(ledVert,LOW); // on éteint ledVert
  //---- on éteint les moteurs ----
  digitalWrite(vitesseMotA, LOW); // vitesse maximale
  digitalWrite(vitesseMotB, LOW); // vitesse maximale
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


