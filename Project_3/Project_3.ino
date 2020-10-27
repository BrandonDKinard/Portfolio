//www.elegoo.com
//2016.12.9

/* @file CustomKeypad.pde
|| @version 1.0
|| @author Alexander Brevig
|| @contact alexanderbrevig@gmail.com
||
|| @description
|| | Demonstrates changing the keypad size and key values.
|| #
*/
#include <Keypad.h>
#include "pitches.h"
#include <LedControl.h>
int DIN = 13;
int CS =  12;
int CLK = 11;

LedControl lc=LedControl(DIN,CLK,CS,0);

byte blank[8]= {0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0}; 

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
 lc.shutdown(0,false);       
 lc.setIntensity(0,5);      //Adjust the brightness maximum is 5
 lc.clearDisplay(0);    
}
  
void loop(){
  char customKey = customKeypad.getKey();
  if (customKeypad.keyStateChanged()) {
    noTone(10);
    printByte(blank);  
  }
 //Octave 4 
 //sharps Octave 4.1
  if (customKey == '4'){
    tone(10,NOTE_CS4);
    byte CS4[8]= {0x82,0x87,0xC2,0x00,0x81,0x81,0x81,0x7E,};
    printByte(CS4);
    delay(500);
  }
  else if (customKey == '1'){
    tone(10,NOTE_DS4);
    byte DS4[8]= {0x82,0x87,0xC2,0x00,0x7E,0x81,0x81,0xFF,};
    printByte(DS4);
    delay(500);
  }
  //Naturals Octave 4.1
  else if (customKey == '8'){
    tone(10,NOTE_C4);
    byte C4[8]= {0x80,0x80,0xC0,0x00,0x81,0x81,0x81,0x7E,};
    printByte(C4);
    delay(500);
  }
  else if (customKey == '5'){
    tone(10,NOTE_D4);
    byte D4[8]= {0x80,0x80,0xC0,0x00,0x7E,0x81,0x81,0xFF,};
    printByte(D4);
    delay(500);
  }
  else if (customKey == '2'){
    tone(10,NOTE_E4);
    byte E4[8]= {0x80,0x80,0xC0,0x00,0x99,0x99,0x99,0xFF,};
    printByte(E4);
    delay(500);
  }
 //next line
 //sharps Octave 4.2)
  else if (customKey == '9'){
    tone(10,NOTE_FS4);
    byte FS4[8]= {0x82,0x87,0xC2,0x00,0x90,0x90,0x90,0xFF,};
    printByte(FS4);
    delay(500);
  }
  else if (customKey == '6'){
    tone(10,NOTE_GS4);
    byte GS4[8]= {0x82,0x87,0xC2,0x00,0x4F,0x49,0x41,0x7F,};
    printByte(GS4);
    delay(500);
  }
  else if (customKey == '3'){
    tone(10,NOTE_AS4);
    byte AS4[8]= {0x82,0x87,0xC2,0x00,0x7F,0x88,0x88,0x7F,};
    printByte(AS4);
    delay(500);
  }
  //Naturals Octave 4.1
  else if (customKey == 'D'){
    tone(10,NOTE_F4);
    byte F4[8]= {0x80,0x80,0xC0,0x00,0x90,0x90,0x90,0xFF,};
    printByte(F4);
    delay(500);
  }
  else if (customKey == 'C'){
    tone(10,NOTE_G4);
    byte G4[8]= {0x80,0x80,0xC0,0x00,0x4F,0x49,0x41,0x7F,};
    printByte(G4);
    delay(500);
  }
  else if (customKey == 'B'){
    tone(10,NOTE_A4);
    byte A4[8]= {0x80,0x80,0xC0,0x00,0x7F,0x88,0x88,0x7F,};
    printByte(A4);
    delay(500);
  }
  else if (customKey == 'A'){
    tone(10,NOTE_B4);
    byte B4[8]= {0x80,0x80,0xC0,0x00,0x6E,0x91,0x91,0xFF,};
    printByte(B4);
    delay(500);
  } 
}
//used https://www.youtube.com/watch?v=yBIXeHHAhrI&ab_channel=ViralScience-ThehomeofCreativity and associated links
void printByte(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}
//pixeltomatrix https://drive.google.com/file/d/1OyfBdyevPCnSMZCYmoSB7yr5k_8Ozsb5/view
