#include <LiquidCrystal.h> 
int Contrast=75;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int inputPin = 0;
int reading = 0;
int RED_PIN = 7;
int BLUE_PIN = 1;
int GREEN_PIN = 0;

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(RED_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  analogWrite(6,Contrast);
  lcd.begin(16, 2);
}

void loop() 
{
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);
  // put your main code here, to run repeatedly:
  reading = analogRead(inputPin);
  float voltage = reading * 5.0;
  voltage /= 1024.0;
  lcd.setCursor(0, 0);
  lcd.print(voltage); lcd.print("V");
  float temperatureC = (voltage - 0.5) * 100 ; 
  lcd.setCursor(0, 1);
  lcd.print(temperatureC); lcd.print(" *C");

  if(temperatureC >= 45)
  {
    digitalWrite(RED_PIN, HIGH);
  }
  else if(temperatureC >= 25 && temperatureC < 45)
  {
    digitalWrite(BLUE_PIN, HIGH);
  }
  else if(temperatureC < 25)
  {
    digitalWrite(GREEN_PIN, HIGH);
  }
 
 // now convert to Fahrenheit
// float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
// Serial.print(temperatureF); Serial.println(" degrees F");
 delay(1000);
}
