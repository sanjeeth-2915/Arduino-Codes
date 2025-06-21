#define BUTTONPIN 4
#define TOUCH 25
#define LED 5
void setup() {
  // put your setup code here, to run once:
pinMode(BUTTONPIN,INPUT);
pinMode(TOUCH,INPUT);
pinMode(LED,OUTPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
int state1 =digitalRead(BUTTONPIN);
int state2 =digitalRead(TOUCH);
Serial.print("Button value:");
Serial.println(state1);
Serial.println(state2);
if(state1==0)
{
  digitalWrite(LED,HIGH);
  Serial.println("button on");
}
else if(state2==1)
{
 digitalWrite(LED,LOW);
 Serial.println("button off");
}
}
