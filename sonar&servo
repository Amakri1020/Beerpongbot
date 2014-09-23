#define echoPin 12
#define trigPin 8
#define servoPin 9

#include <Servo.h>

Servo myservo;
int pos = 0;
int duration, distance;

void setup(){
  Serial.begin(9600);
  pinMode(echoPin,INPUT);
  pinMode(trigPin,OUTPUT);
  myservo.attach(servoPin);
}

void loop(){
  for (pos = 0; pos<180; pos++){
    myservo.write(pos);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(trigPin,LOW);
    duration = pulseIn(echoPin,HIGH);
    distance = duration /(2*29.1);
    Serial.print(distance);
    Serial.print(" cm\n");
    delay(15);
  }
  delay(100);
}
