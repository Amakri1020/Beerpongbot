import processing.serial.*;
Serial port;
Serial port2;
String data = "";
String Radius = "";
String Theta = "";
int index = 0;
float distance = 0;
float angle = 0;
float pi = 22.0/7;

void setup() 
{
 
 size(500,500);
 background(255,255,255);
 ellipse(250,250,500,500);
 line(250,0,250,500);
 line(0,250,500,250);
 line(250,250,500,0);
 line(250,250,0,0);
 line(250,250,120,0);
 line(250,250,400,0);

port = new Serial(this, "COM4", 9600);
port.bufferUntil('.');
}

void draw()

{


}

void serialEvent(Serial port)
{

  data = port.readStringUntil('.');
  data = data.substring(0, data.length() - 1);  
  index = data.indexOf(",");
  Radius = data.substring(0, index);
  Theta = data.substring (index+1 , data.length());
  
   translate(250,250);
   point (0,0);
   
      distance = float(Radius); 
      angle = float(Theta) /180 * pi; 
      fill(30,200,30);
      ellipse(distance * cos(angle) ,  -1 * distance * sin(angle) , 5,5);


}
