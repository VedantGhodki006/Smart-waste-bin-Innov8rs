#include <Servo.h>

#include <DFRobot_DHT11.h>
DFRobot_DHT11 DHT;
#define DHT11_PIN A3 //NEED TO CHANGE THIS

Servo myservo; 
Servo myservo1;
 int echo1=13;
 int trig1=12;
 int echo2= 8;
 int trig2= 9;
 int echo3=11;
 int trig3=10;


int LED1=2;
int LED2=3;
int LED3=4;
int LED4=5;
int LED5=6; // change thi s after making connections
int LED6=7; // change this after making connections
 
int dura=0;
int dist=0;
long duration;
int distance;
long duration2;
int dist2;
long duration3;
int distance3;

void setup()
{
  pinMode(trig1,OUTPUT);
  pinMode(echo1,INPUT);
  pinMode(trig2,OUTPUT);
  pinMode(echo2,INPUT);
  pinMode(trig3,OUTPUT);
  pinMode(echo3,INPUT);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(LED4,OUTPUT);
  pinMode(LED5,OUTPUT);
  pinMode(LED6,OUTPUT);

  
  Serial.begin(1200);
  myservo.attach(A0);
  myservo.write(45);
   digitalWrite(8, LOW);
digitalWrite(9, LOW);
 
  myservo1.attach(A1);
  myservo1.write(30);
   digitalWrite(6, LOW);
digitalWrite(7, LOW);
}

void loop()
{

  digitalWrite(trig1, LOW);
  delayMicroseconds(2);
  digitalWrite(trig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);
   duration = pulseIn(echo1, HIGH);
  distance = duration * 0.034 / 2;
  

  digitalWrite(trig3, LOW);
  delayMicroseconds(2);
   digitalWrite(trig3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig3, LOW);
   duration3 = pulseIn(echo3, HIGH);
  distance3 = duration * 0.034 / 2;
 

   digitalWrite(trig2, LOW);
  delayMicroseconds(2);
 
  digitalWrite(trig2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2, LOW);
  duration2 = pulseIn(echo2, HIGH);
  dist2 = duration2 * 0.034 / 2;
  
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  
if (distance<5)digitalWrite(2, HIGH);
  else if (distance>4 && distance<10)digitalWrite(3, HIGH);
  else if (distance>9 )digitalWrite(4, HIGH);

  if (distance3<5)digitalWrite(5, HIGH);
  else if (distance3>4 && distance3<10)digitalWrite(6, HIGH);
  else if (distance3>9 )digitalWrite(7, HIGH);

if(dist2<10){myservo.write(120);
delay(1000);}
  else myservo.write(0);
  Serial.println("distance");
  delay(100);
 Serial.println(distance);delay(100);
 Serial.println("dist");delay(100);
 Serial.println(dist);delay(100);

 DHT.read(DHT11_PIN);
  Serial.print("  humi:");
 int humid= Serial.println(DHT.humidity);
  delay(1000);

  if(humid>10) {
   myservo1.write(45); 
   delay(100);
  }else {
    myservo1.write(0);
    delay(100);
  }
  
}