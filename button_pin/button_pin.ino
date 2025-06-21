
#define BUTTONPIN 4
void setup() {
  // put your setup code here, to run once:
  pinMode(BUTTONPIN,INPUT);
  Serial.begin(9600);
  

}

void loop() {
  // put your main code here, to run repeatedly:
int state =digitalRead(BUTTONPIN);
Serial.print("Button value");
Serial.println(state);
delay(500);
}
