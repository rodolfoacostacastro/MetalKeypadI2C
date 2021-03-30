
#include <Keypad_I2C.h>
#include <Keypad.h>
#include <Wire.h>
#define I2CADDR 0x20

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
// Digitran keypad, bit numbers of PCF8574 i/o port
byte colPins[COLS] = {4, 6, 2}; //connect to the column pinouts of the keypad
byte rowPins[ROWS] = {5, 1, 0, 3}; //connect to the row pinouts of the keypad

TwoWire *jwire = &Wire;   //test passing pointer to keypad lib
Keypad_I2C kpd( makeKeymap(keys), rowPins, colPins, ROWS, COLS, I2CADDR, PCF8574, jwire );
//Keypad_I2C kpd( makeKeymap(keys), rowPins, colPins, ROWS, COLS, I2CADDR );

void setup(){
  Serial.begin(9600);
  while( !Serial ){ /*wait*/ }
//  Wire.begin( );
  jwire->begin( );
//  kpd.begin( makeKeymap(keys) );
  kpd.begin( );
  Serial.print( "start with pinState = " );
  Serial.println( kpd.pinState_set( ), HEX );
}
void loop(){
  
  char key = kpd.getKey();
  
  if (key){
    Serial.println(key);
  }
}
