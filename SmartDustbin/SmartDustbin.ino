#include<Servo.h> //using Servo library
#include<NewPing.h> //Ultrasonic library to make response simple, fast and powerful

#define trigPin A1  //Analog Pin
#define echoPin A2  //Analog Pin

#define maximum_distance 220  //Maximum distance(in cm) we want to measure(optional)(Ultrasonic sensor can measure 2 to 400 cm distance)
int distance = 100;

NewPing sonar(trigPin, echoPin, maximum_distance); //performs distance measurement using sonar
Servo servoMotor;  //My servo name

void setup() {
  // put your setup code here, to run once:
  servoMotor.attach(10); //attach signal pin of servo to pin 10 of arduino

  servoMotor.write(0);   // 65 //initial position of servo  //set by absorbing positions of servo
  delay(2000);
  distance=readPing();
  delay(100);
  distance=readPing();
  delay(100);
  distance=readPing();
  delay(100);
  distance=readPing();
  delay(100);

  Serial.begin(9600); //start serial communication

}

void loop() {
  // put your main code here, to run repeatedly:
  distance = readPing();
  delay(500); 

  Serial.print("distance = ");  
  Serial.println(distance); //prints data on Serial monitor
  if(distance<20){
    servoMotor.write(180);
    delay(500);
  }
  else{
    servoMotor.write(0);
  }

}

int readPing()
{
  delay(70);
  int cm=sonar.ping_cm(); // if no ping is recevied within the specified maximum distance limit, it will return 0 otherwise return distance
  if(cm == 0)
  {
    cm = 250; 
  }
  return cm;
}
