#define BUTTON 4
#define TOUCH 26
#define REDLED 2


void setup() {
  // put your setup code here, to run once:
pinMode(REDLED,OUTPUT);
pinMode(BUTTON,INPUT);
pinMode(TOUCH,INPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
int state1 = digitalRead(BUTTON);
int state2 = digitalRead(TOUCH);
Serial.print("Button Value: ");
Serial.println(state1);
Serial.println(state2);
if(state1==0)
{
digitalWrite(REDLED,HIGH);
}
else if(state2==1)
{
  digitalWrite(REDLED,LOW);
}

}
