#include "DHT.h"
#include <Servo.h>
Servo myservo1;
Servo myservo2; 
Servo myservo3; 
int dhtpin1=2, dhtpin2=3, checker=6, reader=LOW;
#define DHTTYPE DHT22 
DHT dht1(dhtpin1, DHTTYPE);
DHT dht2(dhtpin2, DHTTYPE);
int pos=0;
void setup() {
  Serial.begin(9600);
  dht1.begin();
  dht2.begin();
  myservo1.attach(4);
  myservo2.attach(5);
  myservo3.attach(6);
}

void loop() 
{
  float h1 = dht1.readHumidity();
  float h2 = dht2.readHumidity();

  Serial.print("Humidity of 1st: ");
  Serial.print(h1);
  Serial.print(" %\t");
  Serial.print("Humidity of 2nd: ");
  Serial.print(h2);
  Serial.println(" %\t");

  if(h2>=46.30)
  {
    myservo2.write(0);
    myservo1.write(0);
  }
  else
  {
   
   myservo2.write(180);
   myservo1.write(180);
  }
  reader=digitalRead(checker);
  if(reader == HIGH)
  {
    myservo3.write(0);
    
  }
  else
  {
    myservo3.write(180);
  }
}
