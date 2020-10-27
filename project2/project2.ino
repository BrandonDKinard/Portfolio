#include <SimpleDHT.h>
#include <LiquidCrystal.h>
// for DHT11, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 7
char pinDHT11 = 7;
//                RS, E, D4, D5, D6, D7
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
SimpleDHT11 dht11(pinDHT11);
int li          = 16;
int lii         = 0; 
void setup() {
  Serial.begin(115200);
  lcd.begin (16,2);
}

void loop() {
  // start working...
  Serial.println("=================================");
  Serial.println("Sample DHT11 with RAW bits...");
  
  // read with raw sample data.
  byte celsius = 0;
  byte humidity = 0;
  char data[40] = {0};
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&celsius, &humidity, data)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
  }
  
  Serial.print("Sample RAW Bits: ");
  /*for (int i = 0; i < 40; i++) {
    Serial.print((int)data[i]);
    if (i > 0 && ((i + 1) % 4) == 0) {
      Serial.print(' ');
    }
  }*/
  Serial.println("");
  
  Serial.print("Sample OK: ");
  Serial.print((int)celsius); Serial.print(" *C, ");
  Serial.print((int)humidity); Serial.println(" H");
  byte fahrenheit = celsius *1.8 +32;
  //indent
  lcd.setCursor(0,0);
  //prints temperature in fahrenheit
  lcd.print(fahrenheit);lcd.print(" ");lcd.print((char)223);lcd.print("F");
  //indent
  lcd.setCursor(6,0);
  //prints temperature in celcius
  lcd.print(celsius);lcd.print(" ");lcd.print((char)223);lcd.print("C");
  //indent
  lcd.setCursor(12,0);
  //prints humidity percentage
  lcd.print(humidity);lcd.print(" ");lcd.print("%");
  //new line
  lcd.setCursor(0,1);
  //Print raw bits
  String bitsoutput = "";
    for (int ctr=li;ctr<li+16;ctr++){
    bitsoutput = bitsoutput = bitsoutput + (int)data[ctr];
    }
  lcd.print(bitsoutput);
  li++;
  if (li > 40-lii) li = 0;
  
  /*for (int i = 0; i < 40; i++) {
    lcd.print(Scroll_LCD_Left((String)data[i]));
    if (i > 0 && ((i + 1) % 4) == 0) {
      Serial.print(' ');
    }  
  // DHT11 sampling rate is 1HZ.
  delay(100);
 } */
}
/*
String Scroll_LCD_Left(String StrDisplay){
  String result;
  String StrProcess = "                " + StrDisplay + "                ";
  result = StrProcess.substring(Li,Lii);
  Li++;
  Lii++;
  if (Li>StrProcess.length()){
    Li=16;
    Lii=0;
  }
  return result;
}
void Clear_Scroll_LCD_Left(){
  Li=16;
  Lii=0;
} */
