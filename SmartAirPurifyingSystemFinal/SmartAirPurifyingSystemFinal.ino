#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);  //SDA=A4, SCL=A5

#define buzzer 7  // connection of buzzer

const int measurePin = A0;
const int ledPower = 2;

const int samplingTime = 280;
const int deltaTime = 40;
const int sleepTime = 6680;

float voMeasured = 0;
float calcVoltage = 0;
float dustDensity = 0;

void setup() {
  pinMode(A1, INPUT); // for MQ135 sensor
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setBacklight(HIGH);
  pinMode(buzzer, OUTPUT);

  pinMode(ledPower, OUTPUT);
}

void loop() {
  int airQuality=analogRead(A1);


  digitalWrite(ledPower, LOW); // Power off the LED
  delayMicroseconds(samplingTime);
  
  voMeasured = analogRead(measurePin); // Read analog pin A0
  digitalWrite(ledPower, HIGH); // Power on the LED
  delayMicroseconds(deltaTime);
  
  calcVoltage = voMeasured * (5.0 / 1024.0);  // Convert to voltage (0 - 5v mapped to 0 - 1024 integer values)
  dustDensity = 170 * calcVoltage - 0.1;
  
  // Serial.print("Voltage: ");
  // Serial.println(calcVoltage);
  Serial.print("Dust Density: ");
  Serial.println(dustDensity-127);
  Serial.println(airQuality);
  lcd.setCursor(0, 0);
  lcd.print("Air Quality :");
  lcd.setCursor(13, 0);
  lcd.print(airQuality+80);

  lcd.setCursor(0, 1);
  lcd.print("Dust Density: ");
  lcd.setCursor(13, 1);
  lcd.print(dustDensity/1000);
  if(airQuality>100)
  {
    digitalWrite(buzzer, HIGH);
    lcd.setCursor(0, 1);
    // lcd.print("Bad Air");
    delay(6000);
  }
  else
  {
    digitalWrite(buzzer, LOW);
    lcd.setCursor(0, 1);
    // lcd.print("Good Air");
    delay(6000);
  }
  
  lcd.clear();
  delay(20);
  delay(sleepTime);
}
