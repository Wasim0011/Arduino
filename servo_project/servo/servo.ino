#include<Servo.h>
#include<SoftwareSerial.h>
Servo s1;
int bttx=10;
int btrx=11;
SoftwareSerial bluetooth(bttx, btrx);


void setup() {
  // put your setup code here, to run once:
  s1.attach(3);
  Serial.begin(9600);
  bluetooth.begin(9600);
  s1.write(0);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  if (bluetooth.available()>=2){
    unsigned int servopos=bluetooth.read();
    unsigned int servopos1=bluetooth.read();
    unsigned int realservo= (servopos1 *256)+ servopos;
    Serial.println(realservo);
    if(realservo>=1000 && realservo<1180){
      int servo1=realservo;
      servo1=map(servo1, 1000, 1180, 0, 180);
      s1.write(servo1);
      Serial.println("Servo 1 ON");
      delay(10);
    }
  }
  
  

  

}
