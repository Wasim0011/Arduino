#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);  //SDA=A4, SCL=A5

#define buzzer 1

void setup() {
  // put your setup code here, to run once:
  pinMode(A1, INPUT); // for MQ135 sensor
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setBacklight(HIGH);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int a=analogRead(A1);
  Serial.println(a);
  lcd.setCursor(0, 0);
  lcd.print("Air Quality:");
  lcd.setCursor(12, 0);
  lcd.print(a);
  if(a>100)
  {
    digitalWrite(buzzer, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Bad Air");
    delay(1000);
  }
  else
  {
    digitalWrite(buzzer, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Good Air");
    delay(1000);
  }
  lcd.clear();
  delay(2000);

}
