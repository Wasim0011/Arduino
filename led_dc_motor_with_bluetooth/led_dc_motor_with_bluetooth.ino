int led=13;
int in1=2;
int in2=3;
int en1=6;
int data;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(6, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()>0){
    data=Serial.read();
    Serial.println(data);
  }
  if(data=='A'){
    digitalWrite(13, HIGH);
  }
  else if(data=='B'){
    digitalWrite(13, LOW);
  }
  else if(data=='C'){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    analogWrite(6, 0);
  }
  else if(data=='D'){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    analogWrite(6, 100);        //0-----255 (low-------high)
  }
  else if(data=='E'){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    analogWrite(6, 255);
  }

}
