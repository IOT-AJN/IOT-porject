

const int read = A0; //Sensor AO pin to Arduino pin A0
int value = 0;   //Variable to store the incomming data
int pump = 3;

void setup()
{
  //Begin serial communication
  Serial.begin(9600);
   digitalWrite(pump, LOW);
  pinMode(pump, OUTPUT);
  
}

void loop()
{
  value = analogRead(read); //Read data from analog pin and store it to value variable
  Serial.println(value);
  if (value<=340)
  { 
    Serial.println("Water level: EMPTY!");
      digitalWrite(pump, HIGH); //Pump onn
    delay(4000); //Watering Time
    digitalWrite(pump, LOW); //Pump off 
  }
  else if (value>340 && value<=450)
  { 
    Serial.println("Water level:LOW"); 
      digitalWrite(pump, HIGH); //Pump onn
    delay(3000); //Watering Time
    digitalWrite(pump, LOW); //Pump off
  }
  else if (value>450 && value<=600)
  { 
    Serial.println("Water level:MEDIUM"); 
      digitalWrite(pump, HIGH); //Pump onn
    delay(2000); //Watering Time
    digitalWrite(pump, LOW); //Pump off
  }
  else if(value>600)
  {
    Serial.println("Water level:HIGH");
      digitalWrite(pump, HIGH); //Pump onn
    delay(2000); //Watering Time
    digitalWrite(pump, LOW); //Pump off 
  }
  delay(2000);
}
