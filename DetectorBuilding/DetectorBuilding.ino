int inputPin = 0;
int reading = 0;
void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  reading = analogRead(inputPin);
  float voltage = reading * 5.0;
  voltage /= 1024.0;
  Serial.println(voltage);
  float temperatureC = (voltage - 0.5) * 100 ; 
  Serial.print(temperatureC); Serial.println(" degrees C");
 
 // now convert to Fahrenheit
 float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
 Serial.print(temperatureF); Serial.println(" degrees F");
 delay(1000);
}
