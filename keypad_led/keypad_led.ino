#include <Keypad.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

const byte ROWS = 4; //4 baris
const byte COLS = 3; //3 kolom
char keys[ROWS][COLS] = { //design keypad
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
    {'*','0','#'}
  };

byte rowPins[ROWS] = {4, 3, 2, 1}; //pinout baris yang terhubung pada keypad
byte colPins[COLS] = {7, 6, 5}; //pinout kolom yang terhubung pada keypad

int led = 9; //pinout led

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);
String inputnya="";

void setup(){
  // initialize the LCD
  pinMode(led, OUTPUT);
  lcd.begin();
  lcd.setCursor(0,0);
}

void loop(){
  char key = keypad.getKey();

  if(key){
      if (key=='#'){
          lcd.clear();
          lcd.setCursor(0,1);
          if(inputnya=="1"){
              digitalWrite(led, HIGH);
              lcd.print("LED ON");
            }
          else if(inputnya=="11"){
              digitalWrite(led, LOW);
              lcd.print("LED OFF");
            }
          lcd.home();
          inputnya="";
        }
      else {
          inputnya+=key;
          lcd.print(key);
        }
    }
}
