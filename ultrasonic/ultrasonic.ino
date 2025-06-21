#define TRIG 12
#define ECHO 13
long int duration;
float distance =0 ;
void setup() {
  // put your setup code here, to run once:
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
  pinMode(4,OUTPUT);
 
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(TRIG,LOW);
  delayMicroseconds(5);
  digitalWrite(TRIG,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG,LOW);
  duration=pulseIn(ECHO,HIGH);
  distance=0.034*(duration/2);
  Serial.print("DISTANCE  in cm:");
  Serial.println(distance);
  if(distance<20)
  {
    digitalWrite(4,HIGH);
    delay(100);
    digitalWrite(4,LOW);
    delay(100);
  }
  else if(distance >20&&distance<60)
  {
    digitalWrite(4,HIGH);
    delay(1000);
    digitalWrite(4,LOW);
    delay(1000);
  }
  else if(distance >60&&distance<100)
  {
    digitalWrite(4,HIGH);
    delay(3000);
    digitalWrite(4,LOW);
    delay(3000);
  }
  else
  {
    digitalWrite(4,LOW);
  }
  delay(10);

}
