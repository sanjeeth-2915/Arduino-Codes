#define BUTTONPIN 4
#define LED 2

void setup() {
  // put your setup code here, to run once:
pinMode(LED,OUTPUT);
pinMode(BUTTONPIN,INPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
int state = digitalRead(BUTTONPIN);
Serial.print("Button Value: ");
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
