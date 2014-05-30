#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int buttonOnePin = 9;
const int buttonTwoPin = 8;
const int buttonThreePin = 7;
int buttonOneState;
int buttonTwoState;
int buttonThreeState;
int lastButtonOneState = LOW;
int lastButtonTwoState = LOW;
int lastButtonThreeState = LOW;
int ledStateOne = HIGH;
int ledStateTwo = HIGH;
int ledStateThree = HIGH;
long lastDebounceTimeOne = 0;
long lastDebounceTimeTwo = 0;
long lastDebounceTimeThree = 0;
int comiditas=0, opcion=0, factor=0;
int hora[4]={0,0,0,0};
int minuto[4]={0,0,0,0};
int counter=2, opcionc=1;
int flag1=0, flag2=0, flag3=0, flag4=0;
long debounceDelay = 50;
void setup() {
  lcd.begin(16, 2);
  
  lcd.print("Feeder Super Wow");
  lcd.setCursor(1,2);
  lcd.print("Chiquiti Boom");
    delay(2000);
  
  int readingOne = digitalRead(buttonOnePin);
  int readingTwo = digitalRead(buttonTwoPin);
  int readingThree = digitalRead(buttonThreePin);
  if (readingOne != lastButtonOneState) {
    lastDebounceTimeOne = millis();}
           
  if (readingTwo != lastButtonTwoState) {
    lastDebounceTimeTwo = millis();}
    
  if (readingThree != lastButtonThreeState) {
    lastDebounceTimeThree = millis();}    
  if ((millis() - lastDebounceTimeOne) > debounceDelay) {
    if (readingOne != buttonOneState) {
      buttonOneState = readingOne;
      if (buttonOneState == HIGH) {
        ledStateOne = !ledStateOne;}}}
   
  if ((millis() - lastDebounceTimeTwo) > debounceDelay) {
    if (readingTwo != buttonTwoState) {
      buttonTwoState = readingTwo;
      if (buttonTwoState == HIGH) {
        ledStateTwo = !ledStateTwo;}}}
            
  if ((millis() - lastDebounceTimeThree) > debounceDelay) {
    if (readingThree != buttonThreeState) {
      buttonThreeState = readingThree;
      if (buttonThreeState == HIGH) {
        ledStateThree = !ledStateThree;}}}
  lastButtonOneState = readingOne;
  lastButtonTwoState = readingTwo;
  lastButtonThreeState = readingThree;
  
  pinMode (7,INPUT);
  pinMode (8,INPUT);
  pinMode (9,INPUT);
  
}
void loop() {
  
int readingOne = digitalRead(buttonOnePin);
int readingTwo = digitalRead(buttonTwoPin);
int readingThree = digitalRead(buttonThreePin);
  if (flag2==0){
     if (readingOne != lastButtonOneState) {
          lastDebounceTimeOne = millis();}
       if ((millis() - lastDebounceTimeOne) > debounceDelay) {
             if (readingOne != buttonOneState) {
                       buttonOneState = readingOne;
                       if (buttonOneState == HIGH) {
                         if (flag1==1){
                           if(ledStateOne==1&&counter<5){
                             counter++;}
                           if(counter==5){
                             counter=2;}
                         } 
                         if (flag2==0){
                           lcd.clear();
                           lcd.print("Cuantas veces?");
                           lcd.setCursor(1,2);
                           lcd.print(counter);
                           delay(100);}}}}
     lastButtonOneState = readingOne;
     
     
     if (readingTwo != lastButtonTwoState) {
          lastDebounceTimeTwo = millis();}
       if ((millis() - lastDebounceTimeTwo) > debounceDelay) {
             if (readingTwo != buttonTwoState) {
                       buttonTwoState = readingTwo;
                       if (buttonTwoState == HIGH) {
                         if (flag1==1){
                           if(ledStateTwo==1&&counter>1){
                             counter--;}
                           if(counter==1){
                             counter=4;}
                         }
                         if (flag2==0){
                           lcd.clear();
                           lcd.print("Cuantas veces?");
                           lcd.setCursor(1,2);
                           lcd.print(counter);
                           delay(100);}}}}
     lastButtonTwoState = readingTwo;
  
  
     if (readingThree != lastButtonThreeState) {
          lastDebounceTimeThree = millis();}
       if ((millis() - lastDebounceTimeThree) > debounceDelay) {
             if (readingThree != buttonThreeState) {
                       buttonThreeState = readingThree;
                       if (buttonThreeState == HIGH) {
                         if (flag1==1){
                           comiditas = counter;
                           lcd.clear();
                           lcd.print("Eligiste darles");
                           lcd.setCursor(1,2);
                           lcd.print(comiditas);
                           lcd.setCursor(3,2);
                           lcd.print("veces");
                           delay(1000);
                           lcd.clear();
                           flag2=1;                        
                           
                         }
                         if (flag2==0){
                           lcd.clear();
                           lcd.print("Cuantas veces?");
                           lcd.setCursor(1,2);
                           lcd.print(counter);
                           delay(100);
                           if (flag1==0){
                             flag1=1;}}}}}
     lastButtonThreeState = readingThree;  
     
     
  }
  
  
  
  
  
  
  
  
  if (flag2==1){                 
    
     if (readingOne != lastButtonOneState) {
          lastDebounceTimeOne = millis();}
       if ((millis() - lastDebounceTimeOne) > debounceDelay) {
             if ((readingOne != buttonOneState) || (flag3==0)) {
                       buttonOneState = readingOne;
                       if (buttonOneState == HIGH) {
                         if (flag3==1){
                           if(ledStateOne==1&&opcionc<3){
                             opcionc++;}
                           if(opcionc==3){
                             opcionc=1;}}
                         if (flag4==0){
                           lcd.clear();
                           lcd.print("AUTO 1, SETUP 2");
                           lcd.setCursor(1,2);
                           lcd.print(opcionc);
                           delay(100);
                           if (flag3==0){
                             flag3=1;}}}}}
     lastButtonOneState = readingOne;
     
     
     if (readingTwo != lastButtonTwoState) {
          lastDebounceTimeTwo = millis();}
       if ((millis() - lastDebounceTimeTwo) > debounceDelay) {
             if ((readingTwo != buttonTwoState) || (flag3==0)) {
                       buttonTwoState = readingTwo;
                       if (buttonTwoState == HIGH) {
                         if (flag3==1){
                           if(ledStateTwo==1&&opcionc>0){
                             opcionc--;}
                           if(opcionc==0){
                             opcionc=2;}}
                         if (flag4==0){
                           lcd.clear();
                           lcd.print("AUTO 1, SETUP 2");
                           lcd.setCursor(1,2);
                           lcd.print(opcionc);
                           delay(100);
                                                    if (flag3==0){
                             flag3=1;}}}}}
     lastButtonTwoState = readingTwo;
  
  
     if (readingThree != lastButtonThreeState) {
          lastDebounceTimeThree = millis();}
       if ((millis() - lastDebounceTimeThree) > debounceDelay) {
             if ((readingThree != buttonThreeState) || (flag3==0)) {
                       buttonThreeState = readingThree;
                       if (buttonThreeState == HIGH) {
                         if (flag3==1){
                           opcion = opcionc;
                           lcd.clear();
                           lcd.print("Eligiste la opcion");
                           lcd.setCursor(1,2);
                           lcd.print(opcion);
                           lcd.setCursor(3,2);
                           if (opcion==1){lcd.print(" AUTO");}
                           if (opcion==2){lcd.print(" SETUP");}
                           delay(1000);
                           lcd.clear();
                           flag4=1;}
                         if (flag4==0){
                           lcd.clear();
                           lcd.print("AUTO 1, SETUP 2");
                           lcd.setCursor(1,2);
                           lcd.print(opcionc);
                           delay(2000);
                           if (flag3==0){
                             flag3=1;}}}}}
     lastButtonThreeState = readingThree;  
  } 
  
  
  
  
  
  
  
  if (flag4==1){
    lcd.clear();
    
    if (opcion==1){
      factor = (15/(comiditas-1));
      hora[0]=7;
      if (comiditas>1){
        if (factor>6&&factor<8){
          hora[1]=7+factor;
          minuto[1]=30;}
        else{
          hora[1]=7+factor;}
        if (comiditas>2){
          if (factor>6&&factor<8){
            hora[2]=8+(factor*2);}
          else {
            hora[2]=7+(factor*2);}
          if (comiditas>3){
            hora[3]=7+(factor*3);}}}
      
      lcd.clear();
      lcd.print("H: ");
      if (hora[0]<10){lcd.print("0");}
      lcd.print(hora[0]);
      lcd.print(":"); 
      if (minuto[0]<10){lcd.print("0");}
      lcd.print(minuto[0]);
      if (hora[1]!=0){   
        lcd.print(" ");
        if (hora[1]<10){lcd.print("0");}
        lcd.print(hora[1]);
        lcd.print(":"); 
        if (minuto[1]<10){lcd.print("0");}
        lcd.print(minuto[1]);
        if (hora[2]!=0){
          lcd.setCursor(1,2);
          if (hora[2]<10){lcd.print("0");}
          lcd.print(hora[2]);
          lcd.print(":"); 
          if (minuto[2]<10){lcd.print("0");}
          lcd.print(minuto[2]);
          if (hora[3]!=0){
            lcd.print(" ");
            if (hora[3]<10){lcd.print("0");}
            lcd.print(hora[3]);
            lcd.print(":"); 
            if (minuto[3]<10){lcd.print("0");}
            lcd.print(minuto[3]);
    
    }}}
  
}
    
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
    }
    
    delay(2000);
  }
    
    
    
    
    
    
  
  
  
  
  
  
}
