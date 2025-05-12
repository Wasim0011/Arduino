#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);  //SDA=A4, SCL=A5
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setBacklight(HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(3, 0);  // 3rd column, 1st row
  lcd.print("Tech Titans");
  lcd.setCursor(0, 1);  // 1st column, 2nd row
  lcd.print("RamSoumyaSarthak");
}
