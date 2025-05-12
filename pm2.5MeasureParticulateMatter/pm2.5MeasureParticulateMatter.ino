const int measurePin = A0;
const int ledPower = 2;

const int samplingTime = 280;
const int deltaTime = 40;
const int sleepTime = 9680;

float voMeasured = 0;
float calcVoltage = 0;
float dustDensity = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPower, OUTPUT);
}

void loop() {
  digitalWrite(ledPower, LOW); // Power off the LED
  delayMicroseconds(samplingTime);
  
  voMeasured = analogRead(measurePin); // Read analog pin A0
  digitalWrite(ledPower, HIGH); // Power on the LED
  delayMicroseconds(deltaTime);
  
  calcVoltage = voMeasured * (5.0 / 1024.0);  // Convert to voltage (0 - 5v mapped to 0 - 1024 integer values)
  dustDensity = 170 * calcVoltage - 0.1;
  
  // Serial.print("Voltage: ");
  // Serial.println(calcVoltage);
  Serial.print("Dust Density: ");
  Serial.println(dustDensity/10.0);
  
  delay(sleepTime);
}
