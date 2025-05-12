int led=13;
int data;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()> 0){
    data=Serial.read();
    Serial.println(data);
  }
  if(data=='A'){
    digitalWrite(13, HIGH);
  }
  else if(data=='B'){
    digitalWrite(13, LOW);
  }

}
