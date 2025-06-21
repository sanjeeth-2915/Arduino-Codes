#define BLYNK_PRINT Serial 
#define BLYNK_TEMPLATE_ID "TMPL3GIsTCbVL"
#define BLYNK_TEMPLATE_NAME "ultrasonic sensor"
#define BLYNK_AUTH_TOKEN "gcsa7hxQ3CTP2pNj_WHt3pF1RhZYJ0aX"
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#define TRIG 12
#define ECHO 13
long int duration;
float distance =0 ;

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Redmi 9";
char pass[] = "12345678";
BlynkTimer timer;

#define BUZZER 14
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(BUZZER,OUTPUT);
   pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
  pinMode(4,OUTPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(1000L, sendSensor);
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
  timer.run();
}

void sendSensor()
{
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
    digitalWrite(14,HIGH);
    delay(100);
    digitalWrite(14,LOW);
    delay(100);
  }
  else if(distance >20&&distance<60)
  {
    digitalWrite(14,HIGH);
    delay(1000);
    digitalWrite(14,LOW);
    delay(1000);
  }
  else if(distance >60&&distance<100)
  {
    digitalWrite(14,HIGH);
    delay(3000);
    digitalWrite(14,LOW);
    delay(3000);
  }
  else
  {
    digitalWrite(14,LOW);
  }
  delay(10);
  Blynk.virtualWrite(V0,TRIG);
  Blynk.virtualWrite(V1,ECHO);
}

BLYNK_WRITE(V2)
{
  int value = param.asInt();
  Blynk.virtualWrite(V2,value);
  if(value==1){
    digitalWrite(BUZZER,HIGH);
  }
  else
  {
    digitalWrite(BUZZER,LOW);
  }
}
