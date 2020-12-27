#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#include "DHT.h"      
DHT dht(11, DHT11);
int h;

void setup() {
  lcd.begin();
  dht.begin();
  pinMode(12, OUTPUT);
}

void loop() {
  h = dht.readHumidity();
  lcd.setCursor(0, 0);
  lcd.print("Kelembaban : ");
  lcd.print(h);
  lcd.print("%");
  
  if(h > 75){
    lcd.setCursor(1, 1);
    lcd.print("  Kipas Mati ");
    digitalWrite(12, LOW);
    delay(1000);
    }
  else if(h < 65){
    lcd.setCursor(1, 1);
    lcd.print("Kipas Menyala");
    digitalWrite(12, HIGH);
    delay(1000);
    }
}
