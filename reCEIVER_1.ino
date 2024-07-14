//Tech Trends Shameer
//RF Transmitter and Receiver

//Below is the Receiver Program

// Include RadioHead Amplitude Shift Keying Library
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#include <RH_ASK.h>
// Include dependant SPI Library 
#include <SPI.h> 

// Create Amplitude Shift Keying Object
RH_ASK rf_driver;
int red=7;
int buzzer=8;
int green =6;

void setup()
{
  pinMode(red,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(green,OUTPUT);
    // Initialize ASK Object
    rf_driver.init();
    // Setup Serial Monitor
    Serial.begin(9600);
     lcd.clear();
 lcd.init();
 lcd.backlight();
 lcd.setCursor(2,0);
 lcd.print("ABC Market");
}

void loop()
{
    // Set buffer to size of expected message
    uint8_t buf[24];
    uint8_t buflen = sizeof(buf);
    // Check if received packet is correct size
    if (rf_driver.recv(buf, &buflen))
    {
      
      // Message received with valid checksum
      Serial.println("Message Received: ");
      Serial.println((char*)buf);         
     digitalWrite(red,LOW);
     digitalWrite(green,HIGH);
      lcd.setCursor(0,1);
      lcd.print("SHATI1");
      lcd.setCursor(7,1);
      lcd.print("SURWAAL");
//       noTone(buzzer);
 digitalWrite(buzzer,LOW);
      delay(700);    
    }
    else{
    lcd.setCursor(0,1);
    lcd.print("                   ");
   digitalWrite(red,HIGH);
   digitalWrite(green,LOW);
//  digitalWrite(buzzer,HIGH);
//     tone(buzzer,2222);
//     delay(50);
//     tone(buzzer,1111);
//     delay(50);
//     tone(buzzer,3333);
//     delay(50);

    }
}
