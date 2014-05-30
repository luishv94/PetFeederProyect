int A=1;
int B=2;
int C=3;
int D=4;
void setup(){
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
}
void loop(){
  digitalWrite(A,HIGH);
  digitalWrite(B,HIGH);
  delay(300);
  digitalWrite(A,LOW);
  digitalWrite(C,HIGH);
  delay(300);
  digitalWrite(B,LOW);
  digitalWrite(D,HIGH);
  delay(300);
  digitalWrite(C,LOW);
  digitalWrite(A,HIGH);
  delay(300);
  digitalWrite(D,LOW);
  digitalWrite(A,LOW);
}
