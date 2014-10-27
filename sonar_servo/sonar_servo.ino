#define ECHOPIN 4
#define TRIGPIN 3
#define LEDPIN 13
#define EYESPIN 12
#define VERPIN 11
#define HORPIN 10

#include <Servo.h>

Servo eyes;
Servo vertical;
Servo horizontal;
int pos = 0;
int posVer, posHor;
long duration, distance;

void setup(){
  Serial.begin(9600);
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(LEDPIN, OUTPUT);
  eyes.attach(EYESPIN);
  vertical.attach(VERPIN);
  horizontal.attach(HORPIN);
}

String Print() {
  Serial.print(distance);
 // Serial.print("cm\n");
  Serial.print(",");
  Serial.print(pos);
  Serial.print(".\n");
  delay(100);

}

float Distance(){
  distance = 0;
  for(int i=0; i<1; i++){
    digitalWrite(TRIGPIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIGPIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGPIN, LOW);
    duration = pulseIn(ECHOPIN, HIGH);
    distance += (duration/(2*29.1));
  }
  //distance = distance/1;
  return distance;
}

void loop(){ 
  Scan();
  Serial.println(Aim());
  Serial.println(Wait());
  Serial.println(Fire());
}

String Aim(){
 return ("Aiming...");
}

String Fire(){
 return "Fire!";
}

String Wait(){
  char FIRE;
  Serial.println("Waiting for command...");
  while (FIRE != 'F'){
    FIRE = Serial.read();
    //horizontal.write(posHor);
    //vertical.write(posVer);
  }
  return "Firing!";
}


void Scan(){
  Serial.println("Scanning.....");
  eyes.write(75);
  
  for(int cycle = 0; cycle<3; cycle++){
    for(pos = 75; pos < 105; pos+=3){
      eyes.write(pos);
      distance = Distance();
      if(distance > 10){
        Print();
      }
      delay(10);
    }
    delay(1000);
    
    for(pos = 105; pos > 75; pos-=3){
      eyes.write(pos);
      distance = Distance();
      if(distance > 10){
        Print();
      }
    delay(10);
    }
  }
  delay(5000);
}
