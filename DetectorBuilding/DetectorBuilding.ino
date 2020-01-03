
int inputPin = A0;
int voltage = 0;
void setup() 
{
  // put your setup code here, to run once:
  //pinMode(A0, OUTPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  voltage = analogRead(inputPin);
  delay(1000);
  Serial.println(voltage);
}
