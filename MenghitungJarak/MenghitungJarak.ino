#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int trigPin = 10;
const int echoPin = 9;

long duration;
int distance;

void setup()
{
	lcd.begin();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.setCursor(0,0);
  lcd.print("SISTEM TERTANAM");
}

void loop()
{
	digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  //
  duration = pulseIn(echoPin, HIGH);

  //
  distance = duration*0.0034/2;

  //
  lcd.setCursor(0,1);
  lcd.print("Jarak : ");
  lcd.print(distance);
  lcd.print(" Cm");
}
