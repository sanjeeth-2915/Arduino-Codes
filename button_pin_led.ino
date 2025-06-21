#define BUTTONPIN 4
#define LED 5
void setup() {
  // put your setup code here, to run once:
pinMode(BUTTONPIN,INPUT);
pinMode(LED,OUTPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
int state =digitalRead(BUTTONPIN);
Serial.print("Button value:");
Serial.println(state);
if(state==0)
{
  digitalWrite(LED,HIGH);
}
else
{
 digitalWrite(LED,LOW);
}
}
