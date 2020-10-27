/*
 * CIS331 Project #1
 * 
 * Morse code translator
 * 
 * Description:
 * 
 * Author: Brandon Kinard
 * 
 * Date: 15 Septemer 2020 
 */
String text = "";
int flashPin = LED_BUILTIN;
int groundPin = 12;
char letters[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
'0','1','2','3','4','5','6','7','8','9',' '}; 
String morse[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--",
"--..",/*0*/"-----",".----","..---","...--","....-",".....","-....","--...","---..","----.","/"};

String text2morse(String in) {
  String rtn = "";
  for (int i=0;i<in.length();i++) {
    int pos = -1;
    char c = in.charAt(i);
    if (c >= 97 && c <= 122) pos = c - 97;
    else if (c >= 65 && c <= 90) pos = c - 65;
    else {
      for (int j=26;j<37;j++) {
        if (letters[j]==c) {pos = j; break;}
      }
    }
    rtn += morse[pos] + "/";
  }//for each chatcer in 'in'
  Serial.println(rtn);
  return rtn;
} //text2morse()
void flashLEDs(String morse) {
  int wait = 250;
  int newwait = wait;
  for (int i=0;i<morse.length();i++) {
    newwait=wait;
    char what = morse.charAt(i);
    Serial.print(what);
    if (what=='.') newwait *= 1;
    else if (what=='-') newwait *=3;
    else if (what=='/') newwait *=.1;
    if (newwait > 0) {
      digitalWrite(flashPin,HIGH);
      delay(newwait);
      digitalWrite(flashPin,LOW);
    }
    delay(wait);
  }// for each morse charcter

} // flashLEDs()
void setup(){
  // put your setup code here, to run once:
  pinMode(flashPin,OUTPUT);
  pinMode(groundPin,OUTPUT);
  digitalWrite(flashPin,LOW);
  digitalWrite(groundPin,LOW);
  delay(2000);
  Serial.begin(9600);
  String translated = text2morse(text);
  flashLEDs(translated);
}

void loop() {
  // put your main code here, to run repeatedly:
  // String text;
  if (Serial.available()) {
    text = Serial.readStringUntil('/n');
    String translated = text2morse(text);
    flashLEDs(translated);
  }
}
