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
#include<Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH,SCREEN_HEIGHT,&Wire,-1);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(BUZZER,OUTPUT);
   pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
  pinMode(4,OUTPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(1000L, sendSensor);
   display.begin(SSD1306_SWITCHCAPVCC,0X3c);
  delay(2000);

  display.setTextSize(1);
  display.setTextColor(WHITE);
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
  
  Blynk.virtualWrite(V0,distance);

  display.clearDisplay();
  display.setCursor(0,10);
  display.print("DISTANCE  in cm:");
  display.println(distance);
  
  display.display();
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
