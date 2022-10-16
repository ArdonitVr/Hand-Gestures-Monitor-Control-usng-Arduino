/*
 *KONTROLLIMI I MONITORIT ME ANE TE GJESTEVE TE DUAREVE

 */

const int trigger1 = 2; //Trigger per sensorin e pare
const int echo1 = 3; //Echo pin per sensorin e dyte
const int trigger2 = 4; //Trigger pin per sensorin e dyte
const int echo2 = 5;//Echo pin per sensorin e dyte

long koha_nevojshme;
int dist,dist_M,dist_D;

 

void setup() {
Serial.begin(9600); 
  
pinMode(trigger1, OUTPUT); 
pinMode(echo1, INPUT); 
pinMode(trigger2, OUTPUT); 
pinMode(echo2, INPUT); 
}

/*###Funksioni i cili kalkulon distancen###*/
void kalkulo_distancen(int trigger, int echo)
{
digitalWrite(trigger, LOW);
delayMicroseconds(2);
digitalWrite(trigger, HIGH);
delayMicroseconds(10);
digitalWrite(trigger, LOW);

koha_nevojshme = pulseIn(echo, HIGH);
dist= koha_nevojshme*0.034/2;
if (dist>50)
dist = 50;
}

void loop() { 
kalkulo_distancen(trigger1,echo1);
dist_M =dist; // merr distancen e sensorit te majte.

kalkulo_distancen(trigger2,echo2);
dist_D =dist; //merr distancen e sensorit te djathte.




if ((dist_M >40 && dist_D>40) && (dist_M <50 && dist_D<50)) //Detekton te dy duarte.
{Serial.println("Play/Pause"); delay (500);}

kalkulo_distancen(trigger1,echo1);
dist_M =dist;

kalkulo_distancen(trigger2,echo2);
dist_D =dist;

 

//Pjesa Kontrolluese e sensorit te majte.
if (dist_M>=13 && dist_M<=17)
{
  delay(100); //Koha e mbajtjes se dores.
  kalkulo_distancen(trigger1,echo1);
  dist_M =dist;
  if (dist_M>=13 && dist_M<=17)
  {
    Serial.println("Left Locked");
    while(dist_M<=40)
    {
      kalkulo_distancen(trigger1,echo1);
      dist_M =dist;
      if (dist_M<10) //Dora shtyhet para
      {Serial.println ("Vup"); delay (300);}
      if (dist_M>20) //Dora terhiqet prapa
      {Serial.println ("Vdown"); delay (300);}
    }
  }
}

//Pjesa kontrolluese e sensorit te djathte.
if (dist_D>=13 && dist_D<=17)
{
  delay(100); //Koha e mbajtjes se dores.
  kalkulo_distancen(trigger2,echo2);
  dist_D =dist;
  if (dist_D>=13 && dist_D<=17)
  {
    Serial.println("Right Locked");
    while(dist_D<=40)
    {
      kalkulo_distancen(trigger2,echo2);
      dist_D =dist;
      if (dist_D<10) //Dora e djathte shtyhet para.
      {Serial.println ("Rewind"); delay (300);}
      if (dist_D>20) //Dora e djathte terhiqet prapa.
      {Serial.println ("Forward"); delay (300);}
  }
}
}

delay(200);
}

 
