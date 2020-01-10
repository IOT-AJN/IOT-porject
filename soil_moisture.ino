#include <Servo.h>
Servo s_name;
int s=0;
void setup() 
{
   s_name.attach(6);

}

void loop() 
{

  for(s=0;s<=360;s++)
  {
    s_name.write(s);
    delay(1000);
  }
  for(s=360;s>=0;s--)
  {
    s_name.write(s);
    delay(1000);
  }
}
