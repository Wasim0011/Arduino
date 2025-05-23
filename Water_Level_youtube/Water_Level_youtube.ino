#include <EEPROM.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 16, 2);


long duration, inches;
int set_val,percentage;
bool state,pump;


void setup() {
  
  lcd.init();
  lcd.print("WATER LEVEL:");
  lcd.setCursor(0, 1); 
  lcd.print("PUMP:OFF MANUAL");
  
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  
   set_val=EEPROM.read(0);
   if(set_val>20)set_val=20;
}
void loop() {
  
   digitalWrite(2, HIGH);
   delayMicroseconds(10);
   digitalWrite(2, LOW);
   duration = pulseIn(3, HIGH);
   inches = microsecondsToInches(duration);
   
   percentage=(set_val-inches)*110/set_val;
   
   lcd.setCursor(12, 0); 
   if(percentage<0)percentage=0;
   lcd.print(percentage);
   lcd.print("%   ");
    
   if(percentage<30&digitalRead(11))pump=1;
   if(percentage>85)pump=0;
   digitalWrite(13,!pump);
     
   lcd.setCursor(5, 1);
   if(pump==1)lcd.print("ON ");
   else if(pump==0) lcd.print("OFF");
   
   lcd.setCursor(9, 1);
   if(!digitalRead(11))lcd.print("MANUAL");
   else lcd.print("AUTO   ");
    
    if(!digitalRead(10)&!state&digitalRead(11)){
      state=1;
      set_val=inches;
      EEPROM.write(0, set_val);
      }
      
     if(!digitalRead(10)&!state&!digitalRead(11)){
        state=1;
        pump=!pump;
     
      }
      
    if(digitalRead(10))state=0;
      
    
    delay(500);
}
long microsecondsToInches(long microseconds) {
   return microseconds / 29 / 2;
}
