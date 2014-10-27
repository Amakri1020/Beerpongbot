#define VERPIN 12
#define HORPIN 11

#include <Servo.h>

Servo vertical;
Servo horizontal;
int posVer, posHor;

void setup(){
  Serial.begin(9600);
  vertical.attach(VERPIN);
  horizontal.attach(HORPIN);
}

String Print() {
  Serial.print(distance);
  Serial.print("cm\n");
  Serial.print(",");
  Serial.print(pos);
  Serial.print(".\n");
  delay(100);

}


void loop(){
    Serial.print(Aim());
    Serial.print(Fire());
}

String Aim(){
  Serial.println("Aiming...");
  vertical.write(posVer);
  horizontal.write(posHor);
  String launchCode = Wait();
  if (launchCode == "154"){
    posVer = 120;
    posHor = 105;
    System.out.println("Set switches to: ");
  } else if (launchCode == "155"){
    posVer = 130;
    posHor = 105;
    System.out.println("Set switches to: ");
  } else if (launchCode == "156"){
    posVer = 137;
    posHor = 105;
    System.out.println("Set switches to: ");
  } else if (launchCode == "157"){
    posVer = 145;
    posHor = 105;
    System.out.println("Set switches to: ");
  } else {
    posVer = 140;
    posHor = 110;
  }
  return (" ");
  Serial.println("Aiming...");
}

String Fire(){
 return " ";
}

String Wait(){
  int FIRE = -3;
  Serial.println("Waiting for command...");
  while (FIRE == -3){
    int byte1 = Serial.read();
    int byte2 = Serial.read();
    int byte3 = Serial.read();
    FIRE = byte1 + byte2 + byte3;
    horizontal.write(posHor);
    vertical.write(posVer);
  }
  return FIRE;
}

