#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
 
#define SS_PIN 10
#define RST_PIN 9
#define LED_G 7 //define green LED pin
//#define LED_R 8  //define red LED
#define BUZZER 2 //buzzer pin
#define IR_pin 4
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
Servo myServo; //define servo name
void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  myServo.attach(5); //servo pin
  myServo.write(0); //servo start position
  pinMode(LED_G, OUTPUT);
 // pinMode(LED_R, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(IR_pin, INPUT);
  //pinMode(3, INPUT);
  noTone(BUZZER);
  Serial.println("Put your card to the reader...");
  Serial.println();

}
void loop() 
{
  int value=digitalRead(IR_pin);
    if(value==0)
    {
      digitalWrite(LED_G,LOW);
      myServo.write(0);
     
    }
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "D6 2D 8E 1E" || content.substring(1) == "86 33 3D 7D") //change here the UID of the card/cards that you want to give access
  {
    
    Serial.println("Authorized access");
    Serial.println();
    delay(500);
    digitalWrite(LED_G, HIGH);
    tone(BUZZER, 500);
    delay(300);
    digitalWrite(LED_G, LOW);
    noTone(BUZZER); 
    myServo.write(180); 
    
  }
 else   
 {
    Serial.println(" Access denied");
    //digitalWrite(LED_R, HIGH);
    tone(BUZZER, 300);
    delay(1000);
    //digitalWrite(LED_R, LOW);
    noTone(BUZZER);
  }
   
 
}
