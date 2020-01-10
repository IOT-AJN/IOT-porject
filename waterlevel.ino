/* Arduino Tutorial - Watel Level Sensor 40mm
   More info: */

const int read = A0; //Sensor AO pin to Arduino pin A0
int value;          //Variable to store the incomming data

void setup()
{
  //Begin serial communication
  Serial.begin(9600);
  
}

void loop()
{
  value = analogRead(read); //Read data from analog pin and store it to value variable
  Serial.println(value);
  if (value<=340)
  { 
    Serial.println("Water level: EMPTY!"); 
  }
  else if (value>340 && value<=450)
  { 
    Serial.println("Water level:LOW"); 
  }
  else if (value>450 && value<=600)
  { 
    Serial.println("Water level:MEDIUM"); 
  }
  else if(value>600)
  {
    Serial.println("Water level:HIGH"); 
  }
  delay(2000);
}
