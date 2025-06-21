#define GREENLED 17
#define BLUELED  5
#define REDLED   25


void setup() {
  // put your setup code here, to run once:
  pinMode(GREENLED ,OUTPUT);
  pinMode(BLUELED,OUTPUT);
  pinMode(REDLED,OUTPUT);
  Serial.begin(9600);
  
}
void loop() {
  // put your main code here, to run repeatedly:
  
digitalWrite(GREENLED,HIGH);
Serial.println("WELCOME GL");
delay(5000);
digitalWrite(GREENLED,LOW);
Serial.println(" NOT WELCOME GL");
delay(5000);

digitalWrite(BLUELED,HIGH);
Serial.println("WELCOME BL");
delay(5000);
digitalWrite(BLUELED,LOW);
Serial.println("NOT WELCOME BL");
delay(5000);

digitalWrite(REDLED,HIGH);
Serial.println("WELCOME RL");
delay(5000);
digitalWrite(REDLED,LOW);
Serial.println(" NOT WELCOME RL");
delay(5000);

digitalWrite(GREENLED,HIGH);
digitalWrite(BLUELED,HIGH);
digitalWrite(REDLED,HIGH);
Serial.println("WELCOME");
delay(5000);
digitalWrite(GREENLED,LOW);
digitalWrite(BLUELED,LOW);
digitalWrite(REDLED,LOW);

digitalWrite(GREENLED,HIGH);
digitalWrite(BLUELED,HIGH);
Serial.println("WELCOME");
delay(5000);
digitalWrite(GREENLED,LOW);
digitalWrite(BLUELED,LOW);

digitalWrite(BLUELED,HIGH);
digitalWrite(REDLED,HIGH);
Serial.println("WELCOME");
delay(5000);
digitalWrite(BLUELED,LOW);
digitalWrite(BLUELED,LOW);

digitalWrite(GREENLED,HIGH);
digitalWrite(REDLED,HIGH);
Serial.println("WELCOME");
delay(5000);
digitalWrite(GREENLED,LOW);
digitalWrite(REDLED,LOW); 

}
