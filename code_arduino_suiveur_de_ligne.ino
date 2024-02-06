

#define CAPTEUR_GAUCHE 4 
#define CAP_D 5 // capteur droit 
#define LDR 12 // dectecteur de lumiere 
#define GA 7
#define GB 8
#define DA 9
#define DB 10


#define P1 ==>

/*
P1 => ultrason sensor

A1 => Moteur gauche
B1 => Morteur droit

P7 => Led droite
P6 => Led gauche

P4:D10 => Servo Moteur
P9:D13 => Photo resistor gauche
P9:D12 => Photo resistor droite
P9:A1 => Capteur infrarouge gauche
P9:A2 => Capteur infrarouge droite

*/

void setup()

{
  Serial.begin(9550);//print les informations 
  pinMode(CAPTEUR_GAUCHE,INPUT);
  pinMode(CAP_D,INPUT);  
  pinMode(DA,OUTPUT);
  pinMode(DB,OUTPUT);
  pinMode(GA,OUTPUT);
  pinMode(GB,OUTPUT);
}
// Fonctions suivre ligne 
void d() //Fonction qui permet au robot de tourner a droite
        {
      digitalWrite(DA,LOW);
      analogWrite(DB,55);
      analogWrite(GA,55);
      digitalWrite(GB,LOW);
          }
void g() //Fonction qui permet au robot de tourner a gauche
{
      analogWrite(DA,55);
      digitalWrite(DB,LOW);
      digitalWrite(GA,LOW);
      analogWrite(GB,55);
          }
void av() //Fonction qui permet au robot de continuer tout droit
{
      digitalWrite(DA,LOW);
      analogWrite(DB,55);
      digitalWrite(GA,LOW);
      analogWrite(GB,55);
}
void loop()
{
      int CAP_G_val = digitalRead(CAPTEUR_GAUCHE);
      int CAP_D_val = digitalRead(CAP_D);
      int LDR_vad   = digitalRead(LDR);
      LDR_vad = false;
      while (LDR_vad == true)
      {
        if ((CAP_G_val) && (!CAP_D_val)) //S'il y a du noir à gauche et du blanc à droite, tourner à gauche
          {
            Serial.println("Tourner à gauche");
            g();
          }
          else if ((!CAP_G_val) && (CAP_D_val)) //S'il y a du blanc à gauche et du noir à droite, tourner à droite
          {
            Serial.println("Tourner à droite");
            d();
          }
          else //Si les conditions plus haut ne s'appliquent pas, continuer tout droit
          {
             Serial.println("Continuer tout droit");
             av();
          }
      }
}
