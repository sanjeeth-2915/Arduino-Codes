#define BUTTONPIN1 4
#define BUTTONPIN2 26
#define BUTTONPIN3 33
#define REDLED 2
#define GREENLED 5
#define BLUELED 12

void setup() {
  // put your setup code here, to run once:
pinMode(REDLED,OUTPUT);
pinMode(GREENLED,OUTPUT);
pinMode(BLUELED,OUTPUT);
pinMode(BUTTONPIN1,INPUT);
pinMode(BUTTONPIN2,INPUT);
pinMode(BUTTONPIN3,INPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
int state1 = digitalRead(BUTTONPIN1);
int state2 = digitalRead(BUTTONPIN2);
int state3 = digitalRead(BUTTONPIN3);
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
if(state2==0)
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
