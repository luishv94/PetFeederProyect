#include <LiquidCrystal.h> // Display LCD
#include <Wire.h> // Modulo RTC                   
#include <DS1307new.h> // Modulo RTC
// Setup del LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
// Setup de los pines
const int buttonOnePin = 9; // Boton Arriba
const int buttonTwoPin = 8; // Boton Abajo
const int buttonThreePin = 7; // Boton Enter
const int buttonFourPin = 15; // Boton Comida
const int motorA = 6; // Motor a pasos A
const int motorB = 10; // Motor a pasos B
const int motorC = 13; // Motor a pasos C
const int motorD = 14; // Motor a pasos D
// Variables para los botones
int buttonOneState;
int buttonTwoState;
int buttonThreeState;
int buttonFourState;
int lastButtonOneState = LOW;
int lastButtonTwoState = LOW;
int lastButtonThreeState = LOW;
int lastButtonFourState = LOW;
// Variables indicadoras
int ledStateOne = HIGH;
int ledStateTwo = HIGH;
int ledStateThree = HIGH;
int ledStateFour = HIGH;
// Variables para el rebote de botones
long lastDebounceTimeOne = 0;
long lastDebounceTimeTwo = 0;
long lastDebounceTimeThree = 0;
long lastDebounceTimeFour = 0;
long debounceDelay = 100;
// Variables para el Modulo RTC
uint16_t startAddr = 0x0000;
uint16_t lastAddr;
uint16_t TimeIsSet = 0xaa55;
// Variables variadas
int comiditas=0, opcion=0, factor=0, guardados=0, nums=1, horis=0;
int hora[4]={0,0,0,0};
int minuto[4]={0,0,0,0};
int horita=0, minutito=0;
int r1=0, r2=0, r3=0, r4=0;
int h1=0, h2=0, m1=0, m2=0;
int counter=2, opcionc=1, horitas;
int flag1=0, flag2=0, flag3=0, flag4=0, flag5=0, flag6=0, flag7=0, flag8=0, flag9=0, flag10=0;
void setup() {
  
  // Setup del Motor
  pinMode(motorA,OUTPUT);
  pinMode(motorB,OUTPUT);
  pinMode(motorC,OUTPUT);
  pinMode(motorD,OUTPUT);
  digitalWrite(motorA,LOW);
  digitalWrite(motorB,LOW);
  digitalWrite(motorC,LOW);
  digitalWrite(motorD,LOW);
  
  // Setup de Modulo RTC
  pinMode(10, INPUT);
  digitalWrite(2, HIGH);
  Serial.begin(9600);
  
  RTC.setRAM(0, (uint8_t *)&startAddr, sizeof(uint16_t));
  TimeIsSet = 0xffff;
  RTC.setRAM(54, (uint8_t *)&TimeIsSet, sizeof(uint16_t));  
  RTC.getRAM(54, (uint8_t *)&TimeIsSet, sizeof(uint16_t));
  
  // Setup de LCD
  lcd.begin(16, 2);
  
  // Mensaje de inicio
  lcd.print("Feeder Super Wow");
  lcd.setCursor(1,2);
  lcd.print("Chiquiti Boom");
    delay(2000);
  
  // Setup anti-rebote de botones
  int readingOne = digitalRead(buttonOnePin);
  int readingTwo = digitalRead(buttonTwoPin);
  int readingThree = digitalRead(buttonThreePin);
  int readingFour = digitalRead(buttonFourPin);
  
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
  if ((millis() - lastDebounceTimeFour) > debounceDelay) {
    if (readingFour != buttonFourState) {
      buttonFourState = readingFour;
      if (buttonFourState == HIGH) {
        ledStateFour = !ledStateFour;}}}
  lastButtonOneState = readingOne;
  lastButtonTwoState = readingTwo;
  lastButtonThreeState = readingThree;
  lastButtonFourState = readingFour;
  
  // Setup del modo de los pines
  pinMode (7,INPUT);
  pinMode (8,INPUT);
  pinMode (9,INPUT);
  
}
void loop() {
  
// Lectura de los botones
int readingOne = digitalRead(buttonOnePin);
int readingTwo = digitalRead(buttonTwoPin);
int readingThree = digitalRead(buttonThreePin);
int readingFour = digitalRead(buttonFourPin);
    // Boton: Comida
     if (readingFour != lastButtonFourState) {
          lastDebounceTimeFour = millis();}
       if ((millis() - lastDebounceTimeFour) > debounceDelay) {
             if (readingFour != buttonFourState) {
                       buttonFourState = readingFour;
                       if (buttonFourState == HIGH) {
                         if (flag1==1){
                           for (int vueltas=0; vueltas<12; vueltas++){
                             lcd.clear();
                             lcd.print("TOMA COMIDA");
                             digitalWrite(motorA,HIGH);
                             digitalWrite(motorB,HIGH);
                             delay(100);
                             digitalWrite(motorA,LOW);
                             digitalWrite(motorC,HIGH);
                             delay(100);
                             digitalWrite(motorB,LOW);
                             digitalWrite(motorD,HIGH);
                             delay(100);
                             digitalWrite(motorC,LOW);
                             digitalWrite(motorA,HIGH);
                             delay(100);
                             digitalWrite(motorD,LOW);
                             digitalWrite(motorA,LOW);}                  
                           }}}}
     lastButtonFourState = readingFour;
if (flag8==0){
  
      // Boton: Arriba
      if (readingOne != lastButtonOneState) {
          lastDebounceTimeOne = millis();}
       if ((millis() - lastDebounceTimeOne) > debounceDelay) {
             if ((readingOne != buttonOneState) || (flag9==0)) {
                       buttonOneState = readingOne;
                       if (buttonOneState == HIGH) {
                         if (flag9==1){
                             if (horis==1){
                               if(ledStateOne==1&&r1<3){
                                 r1++;}
                               if(r1==3){
                                 r1=0;}}
                             if (horis==2){
                               if (r1!=2){
                                 if(ledStateOne==1&&r2<9){
                                   r2++;}
                                 else if(r2==9){
                                   r2=0;}}
                               if (r1==2){
                                 if(ledStateOne==1&&r2<4){
                                   r2++;}
                                 if(r2==4){
                                   r2=0;}}}
                             if (horis==3){
                               if(ledStateOne==1&&r3<5){
                                 r3++;}
                               else if(r3==5){
                                 r3=0;}}
                             if (horis==4){
                               if(ledStateOne==1&&r4<9){
                                 r4++;}
                               else if(r4==9){
                                 r4=0;}}
                           }
                         if (flag8==0){
                           lcd.clear();
                           lcd.print("HORA ACTUAL:");
                           lcd.setCursor(1,2);
                           if (horis<5){
                              lcd.print(r1);
                              lcd.print(r2);
                              lcd.print(":");
                              lcd.print(r3);
                              lcd.print(r4);}
                           delay(100);
                           if (flag9==0){
                             flag9=1;}}}}}
     lastButtonOneState = readingOne;
   
       // Boton: Abajo
       if (readingTwo != lastButtonTwoState) {
          lastDebounceTimeTwo = millis();}
       if ((millis() - lastDebounceTimeTwo) > debounceDelay) {
             if ((readingTwo != buttonTwoState) || (flag9==0)) {
                       buttonTwoState = readingTwo;
                       if (buttonTwoState == HIGH) {
                         if (flag9==1){
                             if (horis==1){
                               if(ledStateOne==1&&r1>0){
                                 r1--;}
                               else if(r1==0){
                                 r1=2;}}
                             if (horis==2){
                               if (r1!=2){
                                 if(ledStateOne==1&&r2>0){
                                   r2--;}
                                 else if(r2==0){
                                   r2=9;}}
                               if (r1==2){
                                 if(ledStateOne==1&&r2>0){
                                   r2--;}
                                 else if(r2==0){
                                   r2=3;}}}
                             if (horis==3){
                               if(ledStateOne==1&&r3>0){
                                 r3--;}
                               else if(r3==0){
                                 r3=5;}}
                             if (horis==4){
                               if(ledStateOne==1&&r4>0){
                                 r4--;}
                               else if(r4==0){
                                 r4=9;}}}
                         if (flag8==0){
                           lcd.clear();
                           lcd.print("HORA ACTUAL:");
                           lcd.setCursor(1,2);
                           if (horis<5){
                              lcd.print(r1);
                              lcd.print(r2);
                              lcd.print(":");
                              lcd.print(r3);
                              lcd.print(r4);}
                           delay(100);
                           if (flag9==0){
                             flag9=1;}}}}}
     lastButtonTwoState = readingTwo;
      
       // BOTON: ENTER/GUARDAR
       if (readingThree != lastButtonThreeState) {
          lastDebounceTimeThree = millis();}
       if ((millis() - lastDebounceTimeThree) > debounceDelay) {
             if ((readingThree != buttonThreeState) || (flag9==0)) {
                       buttonThreeState = readingThree;
                       if (buttonThreeState == HIGH) {
                         if (flag9==1){
                           if (horis<5){
                               horis++;}
                         if (horis==5){
                           lcd.print(" Exito!");
                               delay(1000);
                               horita=(r1*10)+r2;
                               minutito=(r3*10)+r4;
                               if (TimeIsSet != 0xaa55){
                                 RTC.stopClock();
                                 RTC.fillByYMD(2014,06,06);
                                 RTC.fillByHMS(horita,minutito,00);
                                 RTC.setTime();
                                 TimeIsSet = 0xaa55;
                                 RTC.setRAM(54, (uint8_t *)&TimeIsSet, sizeof(uint16_t));
                                 RTC.startClock();}
                               else{
                                 RTC.getTime();}
                               RTC.ctrl = 0x00;
                               RTC.setCTRL();
                               uint8_t MESZ;
                               flag8=1;}}
                         if (flag8==0){
                           lcd.clear();
                           lcd.print("HORA ACTUAL:");
                           lcd.setCursor(1,2);
                           if (horis<5){
                              lcd.print(r1);
                              lcd.print(r2);
                              lcd.print(":");
                              lcd.print(r3);
                              lcd.print(r4);}
                           delay(100);
                           if (flag9==0){
                             flag9=1;}}}}}
     lastButtonThreeState = readingThree;
     
}
  // Primera etapa: Seleccionar numero de comidas por dia
  if ((flag2==0)&&(flag4==0)&&(flag8==1)){
    
    // Boton: Arriba
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
                             counter=2;}} 
                         if (flag2==0){
                           lcd.clear();
                           lcd.print("COMIDAS POR DIA:");
                           lcd.setCursor(1,2);
                           lcd.print(counter);
                           delay(100);}}}}
     lastButtonOneState = readingOne;
     
     // Boton: Abajo
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
                             counter=4;}}
                         if (flag2==0){
                           lcd.clear();
                           lcd.print("COMIDAS POR DIA:");
                           lcd.setCursor(1,2);
                           lcd.print(counter);
                           delay(100);}}}}
     lastButtonTwoState = readingTwo;
  
     // Boton: Enter/Guardar
     if (readingThree != lastButtonThreeState) {
          lastDebounceTimeThree = millis();}
       if ((millis() - lastDebounceTimeThree) > debounceDelay) {
             if (readingThree != buttonThreeState) {
                       buttonThreeState = readingThree;
                       if (buttonThreeState == HIGH) {
                         if (flag1==1){
                           comiditas = counter;
                           lcd.clear();
                           lcd.print("Seleccionaste");
                           lcd.setCursor(1,2);
                           lcd.print(comiditas);
                           lcd.setCursor(3,2);
                           lcd.print("comidas");
                           delay(1000);
                           lcd.clear();
                           flag2=1;}
                         if (flag2==0){
                           lcd.clear();
                           lcd.print("COMIDAS POR DIA:");
                           lcd.setCursor(1,2);
                           lcd.print(counter);
                           delay(100);
                           if (flag1==0){
                             flag1=1;}}}}}
     lastButtonThreeState = readingThree;}
  // Segunda etapa: Seleccionar modo AUTO/SETUP
  if ((flag2==1)&&(flag4==0)){                 
     
     // Boton: Arriba
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
     
     // Boton: Abajo
     if (readingTwo != lastButtonTwoState) {
          lastDebounceTimeTwo = millis();}
       if ((millis() - lastDebounceTimeTwo) > debounceDelay) {
             if ((readingTwo != buttonTwoState) /*|| (flag3==0)*/) {
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
  
     // Boton: Enter/Guardar
     if (readingThree != lastButtonThreeState) {
          lastDebounceTimeThree = millis();}
       if ((millis() - lastDebounceTimeThree) > debounceDelay) {
             if ((readingThree != buttonThreeState)/* || (flag3==0)*/) {
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
     lastButtonThreeState = readingThree;} 
  
  // Tercera etapa: Guardar horas de alimentacion
  if ((flag4==1)&&(flag6==0)){
    
    // Opcion 1: AUTO
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
      lcd.print(" ");
      if (hora[1]<10){lcd.print("0");}
      lcd.print(hora[1]);
      lcd.print(":"); 
      if (minuto[1]<10){lcd.print("0");}
      lcd.print(minuto[1]);
      if (comiditas>2){
        lcd.setCursor(1,2);
        if (hora[2]<10){lcd.print("0");}
        lcd.print(hora[2]);
        lcd.print(":"); 
        if (minuto[2]<10){lcd.print("0");}
        lcd.print(minuto[2]);
        if (comiditas>3){
            lcd.print(" ");
            if (hora[3]<10){lcd.print("0");}
            lcd.print(hora[3]);
            lcd.print(":"); 
            if (minuto[3]<10){lcd.print("0");}
            lcd.print(minuto[3]);}}
    delay(5000);
    flag6=1;}
    
    // OPCION 2: SETUP
    if (opcion==2){
      
      // Boton: Arriba
      if (readingOne != lastButtonOneState) {
          lastDebounceTimeOne = millis();}
       if ((millis() - lastDebounceTimeOne) > debounceDelay) {
             if ((readingOne != buttonOneState) || (flag5==0)) {
                       buttonOneState = readingOne;
                       if (buttonOneState == HIGH) {
                         if (flag5==1){
                           if (guardados<comiditas){
                             if (nums==1){
                               if(ledStateOne==1&&h1<3){
                                 h1++;}
                               if(h1==3){
                                 h1=0;}}
                             if (nums==2){
                               if (h1!=2){
                                 if(ledStateOne==1&&h2<9){
                                   h2++;}
                                 else if(h2==9){
                                   h2=0;}}
                               if (h1==2){
                                 if(ledStateOne==1&&h2<4){
                                   h2++;}
                                 if(h2==4){
                                   h2=0;}}}
                             if (nums==3){
                               if(ledStateOne==1&&m1<5){
                                 m1++;}
                               else if(m1==5){
                                 m1=0;}}
                             if (nums==4){
                               if(ledStateOne==1&&m2<9){
                                 m2++;}
                               else if(m2==9){
                                 m2=0;}}  
                           }}
                         if (flag6==0){
                           lcd.clear();
                           lcd.print("INGRESA LA H ");
                           lcd.setCursor(13,0);
                           lcd.print(guardados+1);
                           lcd.setCursor(1,2);
                           if (guardados<comiditas){
                              lcd.print(h1);
                              lcd.print(h2);
                              lcd.print(":");
                              lcd.print(m1);
                              lcd.print(m2);}
                           delay(100);
                           if (flag5==0){
                             flag5=1;}}}}}
     lastButtonOneState = readingOne;
       
       // Boton: Abajo
       if (readingTwo != lastButtonTwoState) {
          lastDebounceTimeTwo = millis();}
       if ((millis() - lastDebounceTimeTwo) > debounceDelay) {
             if ((readingTwo != buttonTwoState) || (flag5==0)) {
                       buttonTwoState = readingTwo;
                       if (buttonTwoState == HIGH) {
                         if (flag5==1){
                           if (guardados<comiditas){
                             if (nums==1){
                               if(ledStateOne==1&&h1>0){
                                 h1--;}
                               else if(h1==0){
                                 h1=2;}}
                             if (nums==2){
                               if (h1!=2){
                                 if(ledStateOne==1&&h2>0){
                                   h2--;}
                                 else if(h2==0){
                                   h2=9;}}
                               if (h1==2){
                                 if(ledStateOne==1&&h2>0){
                                   h2--;}
                                 else if(h2==0){
                                   h2=3;}}}
                             if (nums==3){
                               if(ledStateOne==1&&m1>0){
                                 m1--;}
                               else if(m1==0){
                                 m1=5;}}
                             if (nums==4){
                               if(ledStateOne==1&&m2>0){
                                 m2--;}
                               else if(m2==0){
                                 m2=9;}}}}
                         if (flag6==0){
                           lcd.clear();
                           lcd.print("INGRESA LA H ");
                           lcd.setCursor(13,0);
                           lcd.print(guardados+1);
                           lcd.setCursor(1,2);
                           if (guardados<comiditas){
                              lcd.print(h1);
                              lcd.print(h2);
                              lcd.print(":");
                              lcd.print(m1);
                              lcd.print(m2);}
                           delay(100);}
                           if (flag5==0){
                             flag5=1;}}}}
     lastButtonTwoState = readingTwo;
      
       // BOTON: ENTER/GUARDAR
       if (readingThree != lastButtonThreeState) {
          lastDebounceTimeThree = millis();}
       if ((millis() - lastDebounceTimeThree) > debounceDelay) {
             if ((readingThree != buttonThreeState) || (flag5==0)) {
                       buttonThreeState = readingThree;
                       if (buttonThreeState == HIGH) {
                         if (flag5==1){
                           if (guardados<comiditas){
                             if (nums<5){
                               nums++;}
                             if (nums==5){
                               lcd.print(" Exito!");
                               delay(1000);
                               hora[guardados]=(h1*10)+h2;
                               minuto[guardados]=(m1*10)+m2;
                               h1=0;
                               h2=0;
                               m1=0;
                               m2=0;
                               guardados++;
                               nums=1;}}
                         if (guardados==comiditas){
                           lcd.clear();
      lcd.print("H: ");
      if (hora[0]<10){lcd.print("0");}
      lcd.print(hora[0]);
      lcd.print(":"); 
      if (minuto[0]<10){lcd.print("0");}
      lcd.print(minuto[0]); 
      lcd.print(" ");
      if (hora[1]<10){lcd.print("0");}
      lcd.print(hora[1]);
      lcd.print(":"); 
      if (minuto[1]<10){lcd.print("0");}
      lcd.print(minuto[1]);
      if (comiditas>2){
        lcd.setCursor(1,2);
        if (hora[2]<10){lcd.print("0");}
        lcd.print(hora[2]);
        lcd.print(":"); 
        if (minuto[2]<10){lcd.print("0");}
        lcd.print(minuto[2]);
        if (comiditas>3){
            lcd.print(" ");
            if (hora[3]<10){lcd.print("0");}
            lcd.print(hora[3]);
            lcd.print(":"); 
            if (minuto[3]<10){lcd.print("0");}
            lcd.print(minuto[3]);}}
    delay(5000);
                           flag6=1;}}
                         if (flag6==0){
                           lcd.clear();
                           lcd.print("INGRESA LA H ");
                           lcd.setCursor(13,0);
                           lcd.print(guardados+1);
                           lcd.setCursor(1,2);
                           if (guardados<comiditas){
                              lcd.print(h1);
                              lcd.print(h2);
                              lcd.print(":");
                              lcd.print(m1);
                              lcd.print(m2);}
                           delay(100);
                           if (flag5==0){
                             flag5=1;}}}}}
     lastButtonThreeState = readingThree;}}
// Cuarta etapa: Mostrar hora y alimentar
if (flag6==1){
  
  // Imprimir la hora del Modulo RTC en el Display
  lcd.clear();
  lcd.setCursor(4,0);
   RTC.getTime();
   if (RTC.hour < 10){
    lcd.print("0");
    lcd.print(RTC.hour, DEC);} 
   else{
    lcd.print(RTC.hour, DEC);}
   lcd.print(":");
   if (RTC.minute < 10){
     lcd.print("0");
     lcd.print(RTC.minute, DEC);}
   else{
     lcd.print(RTC.minute, DEC);}
   lcd.print(":");
   if (RTC.second < 10){
     lcd.print("0");
     lcd.print(RTC.second, DEC);}
   else{
     lcd.print(RTC.second, DEC);}
   lcd.setCursor(1,2);
   if (RTC.day < 10){
     lcd.print("0");
     lcd.print(RTC.day, DEC);}
   else{
     lcd.print(RTC.day, DEC);}
     lcd.print("-");
   if (RTC.month < 10){
     lcd.print("0");
     lcd.print(RTC.month, DEC);}
   else{
     lcd.print(RTC.month, DEC);}
   lcd.print("-");
   lcd.print(RTC.year, DEC);
   lcd.print(" ");
   switch (RTC.dow){
     case 1:
       lcd.print("MON");
       break;
     case 2:
       lcd.print("TUE");
       break;
     case 3:
       lcd.print("WED");
       break;
     case 4:
       lcd.print("THU");
       break;
     case 5:
       lcd.print("FRI");
       break;
     case 6:
       lcd.print("SAT");
       break;
     case 7:
       lcd.print("SUN");
       break;}
  uint8_t MESZ = RTC.isMEZSummerTime();
  RTC.getRAM(0, (uint8_t *)&lastAddr, sizeof(uint16_t));
  lastAddr = lastAddr + 1;
  RTC.setRAM(0, (uint8_t *)&lastAddr, sizeof(uint16_t));
  RTC.getRAM(54, (uint8_t *)&TimeIsSet, sizeof(uint16_t));
  if (TimeIsSet == 0xaa55){}
  else {}
  // Activar el motor cuando la hora del RTC es identica a una de las guardadas  
  for (int i=0; i<comiditas; i++){
    if(RTC.hour==hora[i]){
      if (RTC.minute==minuto[i]){
        if ((RTC.second==00)){
          lcd.clear();
          lcd.print("TOMA COMIDA");*/  
          for (int vueltas=0; vueltas<12; vueltas++){
            digitalWrite(motorA,HIGH);
            digitalWrite(motorB,HIGH);
            delay(100);
            digitalWrite(motorA,LOW);
            digitalWrite(motorC,HIGH);
            delay(100);
            digitalWrite(motorB,LOW);
            digitalWrite(motorD,HIGH);
            delay(100);
            digitalWrite(motorC,LOW);
            digitalWrite(motorA,HIGH);
            delay(100);
            digitalWrite(motorD,LOW);
            digitalWrite(motorA,LOW);}}}}}
  delay(1000);  
  
}}
