#define uchar unsigned char

uchar flag = 4;

void setup()

{

  Serial.begin(9600);  // start serial port at 9600 bps:

  pinMode(2, OUTPUT);

  pinMode(3, OUTPUT);

  pinMode(4, OUTPUT);

  pinMode(5, OUTPUT);

}

void loop()

{

  int w = analogRead(A0); //read the value from analog pin AO

  int g = analogRead(A1);

  int y = analogRead(A2);

  int r = analogRead(A3);

  Serial.println("w:");

  Serial.println(w);

  Serial.println("g:");

  Serial.println(g);

  Serial.println("y:");

  Serial.println(y);

  Serial.println("r:");

  Serial.println(r);

  if((w< 1000) && (g > 1000) && (y > 1000) && (r > 1000))                      //Stop when the car is picked up

   flag = 0;

    else if ((w< 1000) && (g < 1000) && (y > 1000) && (r > 1000))                            //if read the value of the Tracking module data[0] is more than 100

    flag = 1;       

      else if((w< 1000) && (g < 1000) && (y < 1000) && (r > 1000))                              //if read the value of the Tracking module data[2] is more than 100

      flag = 2;

        else if((w< 1000) && (g < 1000) && (y > 1000) && r< 1000)                           //if read the value of the Tracking module data[4] is more than 100

        flag = 3;

        else

        flag = 4;

  switch(flag)   //According to the relative position of the line and the car, adjust the front wheel steering angle to change the direction of the car to achieve inspection line.

  {

    case 0:

    digitalWrite(2,HIGH);

    digitalWrite(3, LOW);

    digitalWrite(4, LOW);

    digitalWrite(5, LOW);

    break;

    case 1:

    digitalWrite(3,HIGH);

    digitalWrite(2, LOW);

    digitalWrite(4, LOW);

    digitalWrite(5, LOW);

    break;

    case 2:

    digitalWrite(4,HIGH);//turn the LED on

    digitalWrite(2, LOW);

    digitalWrite(3, LOW);

    digitalWrite(5, LOW);

    pinMode(9, OUTPUT); //set the pin 9 as an output

    tone(9, 3000, 100);

    delay(400);

    tone(9, 0, 10);

    delay(400);

    pinMode(9, INPUT); //set the pin 9 as an input

    break;

    case 3:

      digitalWrite(5,HIGH);

      digitalWrite(2, LOW);

      digitalWrite(4, LOW);

      digitalWrite(3, LOW);

      pinMode(9, OUTPUT);

    tone(9, 3000, 100);

    delay(80);

    tone(9, 0, 10);

    delay(80);

    pinMode(9, INPUT);

    break;

    case 4:

    digitalWrite(3, LOW);

    digitalWrite(2, LOW);

    digitalWrite(4, LOW);

    digitalWrite(5, LOW);

    break;

  }

}

 
