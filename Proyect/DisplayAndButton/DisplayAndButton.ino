#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int buttonOnePin = 8;
int counter=2;
int buttonOneState;
int lastButtonOneState = LOW;
int ledStateOne = HIGH;
long lastDebounceTimeOne = 0;
long debounceDelay = 50;
void setup() {
  lcd.begin(16, 2);
  
  lcd.print("Cuantas veces?:");
  
  int readingOne = digitalRead(buttonOnePin);
     if (readingOne != lastButtonOneState) {
          lastDebounceTimeOne = millis();}
       if ((millis() - lastDebounceTimeOne) > debounceDelay) {
             if (readingOne != buttonOneState) {
                         buttonOneState = readingOne;
                       if (buttonOneState == HIGH) {
                              ledStateOne = !ledStateOne;}}}
 
    
     if(ledStateOne!=lastButtonOneState){
       lcd.clear(); 
       
     lcd.setCursor(1,2);
       lcd.print("madre pendejo"); 
       delay(8);
     }
     else if(ledStateOne!=1){
       lcd.clear();
    
     lcd.setCursor(1,2);
       lcd.print("madre pendejo");
       delay(8);
       
     }
     lastButtonOneState = readingOne;
  
  pinMode (8,INPUT);
}
void loop() {
int readingOne = digitalRead(buttonOnePin);
     if (readingOne != lastButtonOneState) {
          lastDebounceTimeOne = millis();}
       if ((millis() - lastDebounceTimeOne) > debounceDelay) {
             if (readingOne != buttonOneState) {
                       buttonOneState = readingOne;
                       if (buttonOneState == HIGH) {
                         if(ledStateOne==1&&counter<5){
                           counter++;}
                         if(counter==5){
                           counter=2;}
                         lcd.clear();
                         lcd.print("Cuantas veces?");
                         lcd.setCursor(1,2);
                         lcd.print(counter);
                         delay(100);}}}
     lastButtonOneState = readingOne
     
     
     
     
     
}
