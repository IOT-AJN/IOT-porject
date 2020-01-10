#define threshold 600 // Defining Thresholds

#define wateringTime 5000 //5 seconds
#define wateringTime1 2000 //2 seconds

int value1 = 0;  //initializing sensor value & variables 
int pump = 3; // water pump control pin

void watering1();
void watering2();
void setup()
{
  pinMode(pump, OUTPUT);
  Serial.begin(9600);
  digitalWrite(pump, LOW); //pump off at initial
}

void loop()
{
  value1= analogRead(A0); //Reading values from sensot

   Serial.print("Mositure : ");

   Serial.println(value1);

   delay(1000);

  
     if(value1 >= threshold)
     {
       watering1();  //control watering operations
     }
     else if(value1 >=420)
     {
        watering2();
     }


}
void watering1()
{
    digitalWrite(pump, HIGH); //Pump onn
    delay(wateringTime); //Watering Time
    digitalWrite(pump, LOW); //Pump off
    delay(5000); //Wait till extra water flows out
    
    delay(15000); //wait for 15 seconds before reading again, this will let water sets in soil
    
}
void watering2()
{
    digitalWrite(pump, HIGH); //Pump onn
    delay(wateringTime1); //Watering Time
    digitalWrite(pump, LOW); //Pump off
    delay(5000); //Wait till extra water flows out
    
    delay(15000); //wait for 15 seconds before reading again, this will let water sets in soil
    
}
  
