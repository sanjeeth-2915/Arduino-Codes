#define TRIG 18
#define ECHO 19
#define BUZZER 25
long duration;
float distance = 0; 

void setup() {
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
  pinMode(BUZZER,OUTPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  digitalWrite(TRIG,LOW);
  delayMicroseconds(5);
  digitalWrite(TRIG,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG,LOW);
  duration = pulseIn(ECHO,HIGH);
  distance = 0.034 * (duration/2);
  Serial.print("DISTANCE MEASURED(cm): ");
  Serial.println(distance);
  delay(1000);
  digitalWrite(BUZZER,LOW);
  if(distance<20){
    digitalWrite(BUZZER,HIGH);
    delay(300);
    digitalWrite(BUZZER,LOW);
    delay(300);

  }
  else if(distance>20 && distance<60)
  {
    digitalWrite(BUZZER,HIGH);
    delay(1000);
    digitalWrite(BUZZER,LOW);
    delay(1000);
  }
  else if(distance>60 && distance<100)
  {
    digitalWrite(BUZZER,HIGH);
    delay(4000);
    digitalWrite(BUZZER,LOW);
    delay(4000);
  }
  else
  {
    digitalWrite(BUZZER,LOW);
  }

 
  // put your main code here, to run repeatedly:

}
