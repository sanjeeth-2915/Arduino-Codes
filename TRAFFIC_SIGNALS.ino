#define RED 4
#define GREEN 12
void setup() {
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
  
  // put your setup code here, to run once:

}

void loop() {
  digitalWrite(RED,HIGH);
  delay(5000);
  digitalWrite(RED,LOW);

   digitalWrite(RED,HIGH);
   digitalWrite(GREEN,HIGH);
  delay(3000);
  digitalWrite(RED,LOW);
  digitalWrite(GREEN,LOW);

  digitalWrite(GREEN,HIGH);
  delay(6000);
  digitalWrite(GREEN,LOW);

   digitalWrite(RED,HIGH);
   digitalWrite(GREEN,HIGH);
  delay(1000);
  digitalWrite(RED,LOW);
  digitalWrite(GREEN,LOW);

  digitalWrite(RED,HIGH);
  delay(5000);
  digitalWrite(RED,LOW);

  // put your main code here, to run repeatedly:

}
