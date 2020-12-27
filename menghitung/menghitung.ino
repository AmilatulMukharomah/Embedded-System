#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
int adc = 0;
int count = 0;

void setup()
{
	// initialize the LCD
	lcd.begin();

}

void loop()
{
	adc = analogRead(A0);
  lcd.setCursor(0,1);
  lcd.print("Pin ADC A0 = ");
  lcd.print(adc);
  lcd.setCursor(0,0);
  lcd.print("Conter = ");
  lcd.print(count++);
  delay(500);
}
