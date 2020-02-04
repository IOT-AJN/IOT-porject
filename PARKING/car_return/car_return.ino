#include <Servo.h>
#define IR_pin 4
#define led 7
Servo myServo;
void setup()
{
  pinMode(IR_pin,INPUT);
   pinMode(led,OUTPUT);
   myServo.attach(5);
   myServo.write(0);
}

void loop()
{
  int value=digitalRead(IR_pin);
  if(value==0)
  {
    digitalWrite(led,HIGH);
    myServo.write(180);
   
  }
  else
  {
    digitalWrite(led,LOW);
    myServo.write(0);
  }
  
}
