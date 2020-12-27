#include <Keypad.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

const byte ROWS = 4; //4 baris
const byte COLS = 3; //3 kolom
char keys[ROWS][COLS] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
    {'*','0','#'}
  };

byte rowPins[ROWS] = {4, 3, 2, 1}; //pinout baris yang terhubung pada keypad
byte colPins[COLS] = {7, 6, 5}; //pinout kolom yang terhubung pada keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup(){
  // initialize the LCD
  lcd.begin();

}

void loop(){
  char key = keypad.getKey();

  if(key){
      switch (key){
          case '0':
          case '1':
          case '2':
          case '3':
          case '4':
          case '5':
          case '6':
          case '7':
          case '8':
          case '9':
            lcd.print(key);
            break;
          case '#':
            lcd.setCursor(0,1);
            break;
          case '*':
            lcd.clear();
            lcd.setCursor(0,0);
            break;
        }
    }

}
