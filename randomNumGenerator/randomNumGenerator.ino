int num;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  randomSeed(analogRead(0));  //use that analog pin which is not connected to anything

}

void loop() {
  // put your main code here, to run repeatedly:
  num=random(1, 10);  //generates number between 1 to 10;
  Serial.println(num);
  delay(500);
}
