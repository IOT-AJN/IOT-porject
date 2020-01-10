
int sensorValue = 0; // variable to store the value coming from the sensor34q we4r
int led = 13;
int led1 = 9;

void setup() 
{ // declare the ledPin as an OUTPUT:

  pinMode(led, OUTPUT);
  pinMode(led1, OUTPUT);
  
  Serial.begin(9600); 
 }

void loop()

{

    sensorValue = analogRead(A0);

    Serial.println(sensorValue);

    if (sensorValue < 300)
    {

        digitalWrite(led,HIGH);
        digitalWrite(led1,HIGH);
       
    }
    else if(sensorValue > 300 && sensorValue < 500)
    {
      digitalWrite(led,HIGH);
    }
    else
    {
        digitalWrite(led,LOW);
        digitalWrite(led1,LOW);
    }
    delay(1000);
}
