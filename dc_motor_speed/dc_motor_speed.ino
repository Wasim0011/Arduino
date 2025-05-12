int in1=2;
int in2=3;
int en1=6;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(6, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(en1, 100);
  delay(100);      //0--------255(LOw-----HIgh)

}
