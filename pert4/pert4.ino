#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int trigPin = 10;
const int echoPin = 9;

int Led1=3;
int Led2=4;
int Led3=5;

long duration;
int distance;

void setup()
{
  pinMode(Led1, OUTPUT);pinMode(Led2, OUTPUT);pinMode(Led3, OUTPUT);
  pinMode(trigPin, OUTPUT); //sets the trigPin an Output
  pinMode(echoPin, INPUT);
  lcd.begin();  
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

  //LED
  if(distance < 20)
  {
  digitalWrite (Led1, HIGH);
  digitalWrite (Led2, HIGH);
  digitalWrite (Led3, HIGH);
  delay(300);
  digitalWrite (Led1, LOW);
  digitalWrite (Led2, LOW);
  digitalWrite (Led3, LOW);
  delay(300);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Jarak : ");
  lcd.print(distance);
  lcd.print(" cm");
  lcd.setCursor(0,1);
  lcd.print("Flip-Flop");
  lcd.backlight();
  delay(1000);
  lcd.noBacklight();
  delay(1000);
  delay(1000);
  }
  else if(distance >= 20 && distance <=40)
  {
  lcd.clear();
  digitalWrite (Led1, HIGH);
  delay(200);
  digitalWrite (Led2, HIGH);
  delay(200);
  digitalWrite (Led3, HIGH);
  delay(200);
  digitalWrite (Led1, LOW);
  digitalWrite (Led2, LOW);
  digitalWrite (Led3, LOW);
  delay(200);
  lcd.setCursor(0,0);
  lcd.print("Jarak : ");
  lcd.print(distance);
  lcd.print(" cm");
  lcd.setCursor(0,1);
  lcd.print("LED Berjalan");
  delay(1000);
  }
  else
  {
  lcd.clear();
  digitalWrite (Led2, HIGH);
  lcd.setCursor(0,0);
  lcd.print("Jarak : ");
  lcd.print(distance);
  lcd.print(" cm");
  delay(1000);
  }
}
