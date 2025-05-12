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
long distanceInCm2b;  //ultrasonic sensor can read distance between 2 to 400 cm;
#define buzzer2 9

//for buzzer3
int trig3 = 6;
int echo3 = 7;
// long timeInMicro3;
long distanceInCm3;  //ultrasonic sensor can read distance between 2 to 400 cm;
long distanceInCm3b;
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
  delay(20);
  long duration2b = pulseIn(echo2, HIGH);
  distanceInCm2b = duration2b * 0.034 / 2;
  delay(20);


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
  delay(20);
  long duration3b = pulseIn(echo3, HIGH);
  distanceInCm3b = duration3b * 0.034 / 2;
  delay(20);

  // Print distances
  Serial.print("Sensor 1: ");
  Serial.print(distanceInCm1);
  Serial.println(" cm");
  Serial.print("Sensor 2a: ");
  Serial.print(distanceInCm2);
  Serial.println(" cm");
  Serial.print("Sensor 2b: ");
  Serial.print(distanceInCm2b);
  Serial.println(" cm");
  Serial.print("Sensor 3a: ");
  Serial.print(distanceInCm3);
  Serial.println(" cm");
  Serial.print("Sensor 3b: ");
  Serial.print(distanceInCm3b);
  Serial.println(" cm");

  // Add a delay between readings
  //for buzzer 1
  if (distanceInCm1 < 100) {
    digitalWrite(buzzer1, HIGH);
    delay(200);
  } else {
    digitalWrite(buzzer1, LOW);
    delay(200);
  }
  //     if(distanceInCm1<100 && distanceInCm1>60 ){
  //     digitalWrite(buzzer1, HIGH);
  //     delay(2000);
  //     digitalWrite(buzzer1, LOW);
  //     delay(1000);
  //   }
  //   else if(distanceInCm1<60&& distanceInCm1>40 ){
  //     digitalWrite(buzzer1, HIGH);
  //     delay(2000);
  //     digitalWrite(buzzer1, LOW);
  //     delay(500);

  //   }
  // else if(distanceInCm1<40 ){
  //     digitalWrite(buzzer1, HIGH);
  //     delay(2000);
  //     digitalWrite(buzzer1, LOW);
  //     delay(100);

  //   }
  //   else{
  //     digitalWrite(buzzer1, LOW);
  //     delay(100);
  //   }
  // delay(20);
  //   //for buzzer2
  //   int diff2=distanceInCm2b-distanceInCm2;
  //   if(distanceInCm2<100 || distanceInCm2b<100 ){
  //     if(diff2<-10){
  //        digitalWrite(buzzer2, HIGH);
  //        delay(10);
  //     }
  //     else{
  //       digitalWrite(buzzer2, LOW);
  //     }
  //   }


  //for buzzer3
  int diff3 = distanceInCm3b - distanceInCm3;
  if (distanceInCm3 < 100 || distanceInCm3b < 100) {
    if (diff3 < -10) {
      digitalWrite(buzzer3, HIGH);
      delay(10);
    } else {
      digitalWrite(buzzer3, LOW);
    }
  }

  delay(100);
}