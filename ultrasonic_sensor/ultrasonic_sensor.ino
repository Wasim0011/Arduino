int trig=7;
int echo=6;
long timeInMicro;
long distanceInCm;  //ultrasonic sensor can read distance between 2 to 400 cm;

void setup(){
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop(){
  digitalWrite(trig, LOW);
  delayMicroseconds(5);
  digitalWrite(trig, HIGH);
  delayMicroseconds(100);
  digitalWrite(trig, LOW);
  timeInMicro=pulseIn(echo, HIGH);
  distanceInCm=timeInMicro/29/2;   // speed of light in air (= 0. 03cm/microsecond), distance = time*speed
  Serial.println(distanceInCm);
  delay(1000);

}