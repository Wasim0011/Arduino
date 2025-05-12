//for buzzer1
int trig1 = 2;
int echo1 = 3;
// long timeInMicro1;
long distanceInCm1;  //ultrasonic sensor can read distance between 2 to 400 cm;
#define buzzer1 8

//for buzzer2
int trig2 = 4;
int echo2 = 5;
// long timeInMicro2;
long distanceInCm2;
 //ultrasonic sensor can read distance between 2 to 400 cm;
#define buzzer2 9

//for buzzer3
int trig3 = 6;
int echo3 = 7;
// long timeInMicro3;
long distanceInCm3;  //ultrasonic sensor can read distance between 2 to 400 cm;
#define buzzer3 10


void setup() {
  Serial.begin(9600);
  // Define pins for each sensor
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);
  pinMode(trig3, OUTPUT);
  pinMode(echo3, INPUT);
  pinMode(buzzer1, OUTPUT);
  pinMode(buzzer2, OUTPUT);
  pinMode(buzzer3, OUTPUT);
}

void loop() {
  // Trigger sensor 1
  digitalWrite(trig1, LOW);
  delayMicroseconds(2);
  digitalWrite(trig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);

  // Read echo time for sensor 1
  long duration1 = pulseIn(echo1, HIGH);
  // Calculate distance for sensor 1
  distanceInCm1 = duration1 * 0.034 / 2;  // Speed of sound is 0.034 cm/µs
  delay(10);
  // Trigger sensor 2
  digitalWrite(trig2, LOW);
  delayMicroseconds(2);
  digitalWrite(trig2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2, LOW);

  // Read echo time for sensor 2
  long duration2 = pulseIn(echo2, HIGH);
  // Calculate distance for sensor 2
  distanceInCm2 = duration2 * 0.034 / 2;  // Speed of sound is 0.034 cm/µs
 


  // Trigger sensor 3
  digitalWrite(trig3, LOW);
  delayMicroseconds(2);
  digitalWrite(trig3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig3, LOW);

  // Read echo time for sensor 3
  long duration3 = pulseIn(echo3, HIGH);
  // Calculate distance for sensor 3
  distanceInCm3 = duration3 * 0.034 / 2;  // Speed of sound is 0.034 cm/µs
 

  // Print distances
  Serial.print("Sensor 1: ");
  Serial.print(distanceInCm1);
  Serial.println(" cm");
  Serial.print("Sensor 2: ");
  Serial.print(distanceInCm2);
  Serial.println(" cm");
  Serial.print("Sensor 3: ");
  Serial.print(distanceInCm3);
  Serial.println(" cm");
 
 if(distanceInCm1<50){
  digitalWrite(buzzer1,HIGH);
  // delay(50);
 }
else if(distanceInCm1>50){
  digitalWrite(buzzer1,LOW);
  // delay(50);
 }

//-------------------------------------------
    if(distanceInCm2<200 && distanceInCm2>100 ){
      digitalWrite(buzzer2, HIGH);
      delay(200);
      digitalWrite(buzzer2, LOW);
      delay(2000);
    }
    else if(distanceInCm2<100&& distanceInCm2>50 ){
      digitalWrite(buzzer2, HIGH);
      delay(200);
      digitalWrite(buzzer2, LOW);
      delay(1000);

    }
  else if(distanceInCm2<50 ){
      digitalWrite(buzzer2, HIGH);
      delay(200);
      digitalWrite(buzzer2, LOW);
      delay(100);

    }
    else{
      digitalWrite(buzzer2, LOW);
      delay(10);
    }
  delay(20);

//   if(distanceInCm2<50){
//   digitalWrite(buzzer2,HIGH);
//   // delay(50);
//  }
//  else if(distanceInCm2>50){
//   digitalWrite(buzzer2,LOW);
//   // delay(50);
//  }


 if(distanceInCm3<50){
  digitalWrite(buzzer3,HIGH);
  // delay(50);
 }
else if(distanceInCm3>50){
  digitalWrite(buzzer3,LOW);
  // delay(50);
 }
 else{
  digitalWrite(buzzer1,LOW);
  digitalWrite(buzzer2,LOW);
  digitalWrite(buzzer3,LOW);
 }
 

  delay(200);
}