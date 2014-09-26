#define ECHOPIN 4
#define TRIGPIN 3
#define LEDPIN 13
#define SERVOPIN 12

#include <Servo.h>

Servo myservo;
int pos = 0;
long duration, distance;

void setup(){
  Serial.begin(9600);
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(LEDPIN, OUTPUT);
  myservo.attach(SERVOPIN);
}

String Print() {
  Serial.print(distance);
 // Serial.print("cm\n");
  Serial.print(",");
  Serial.print(pos);
  Serial.print(".\n");

}

float Distance(){
  distance = 0;
  for(int i=0; i<1; i++){
    digitalWrite(TRIGPIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIGPIN, HIGH);
    delayMicroseconds(100);
    digitalWrite(TRIGPIN, LOW);
    duration = pulseIn(ECHOPIN, HIGH);
    distance += (duration/(2*29.1));
  }
  //distance = distance/100;
  return distance;
}

void loop(){
  myservo.write(60);
  
  for(pos = 60; pos < 120; pos+=3){
    myservo.write(pos);
    distance = Distance();
    if(distance > 10){
      Print();
    }
    delay(100);
  }
  delay(1000);
  
  for(pos = 120; pos > 60; pos-=3){
    myservo.write(pos);
    distance = Distance();
    if(distance > 10){
      Print();
    }
  delay(100);
  }
  delay(1000);
}
