#include <NewPing.h>
#include <LiquidCrystal.h> 
int Contrast=110;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  

NewPing sonar(9, 10, 500); // NewPing setup of pins and maximum distance.
float distance;

void setup()
{
     analogWrite(6,Contrast);
     lcd.begin(16, 2);
     Serial.begin(9600);
     lcd.setCursor(0, 0);
     lcd.print("*Evoneg Tech*");
} 
void loop()
{ 
    delay(250); // Wait 250ms between measures. 
  
    distance = sonar.ping_cm();

    lcd.setCursor(0, 1);
    if (distance >0)
    {
       lcd.print("Distance = ");
       lcd.print(distance,0);
       lcd.print("cm  ");  
    }   
    else
    {
         lcd.print("....Measuring...");
    }
}