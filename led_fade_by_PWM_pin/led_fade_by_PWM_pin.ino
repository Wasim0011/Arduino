int led1=10;

void setup() {
  // put your setup code here, to run once:
  pinMode(10, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
// analogWrite(led, duty_cycle);       0-----255
                                    // low---high
for(int i=0; i<=255; i++){
  analogWrite(led1, i);
  delay(10);
}
for(int i=255; i>=0; i--){
  analogWrite(led1, i);
  delay(10);
}

}
