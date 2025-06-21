#define BUTTON 4
#define TOUCH 26
#define IR 33
#define REDLED 2
#define GREENLED 5
#define BLUELED 12

void setup() {
  // put your setup code here, to run once:
pinMode(REDLED,OUTPUT);
pinMode(GREENLED,OUTPUT);
pinMode(BLUELED,OUTPUT);
pinMode(BUTTON,INPUT);
pinMode(TOUCH,INPUT);
pinMode(IR,INPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
int state1 = digitalRead(BUTTON);
int state2 = digitalRead(TOUCH);
int state3 = digitalRead(IR);
Serial.print("Button Value: ");
Serial.println(state1);
Serial.println(state2);
Serial.println(state3);
if(state1==0)
{
  digitalWrite(REDLED,HIGH);
}
else
{
  digitalWrite(REDLED,LOW);
}
if(state2==1)
{
  digitalWrite(GREENLED,HIGH);
}
else
{
  digitalWrite(GREENLED,LOW);
}
if(state3==0)
{
  digitalWrite(BLUELED,HIGH);
}
else
{
  digitalWrite(BLUELED,LOW);
}
}
