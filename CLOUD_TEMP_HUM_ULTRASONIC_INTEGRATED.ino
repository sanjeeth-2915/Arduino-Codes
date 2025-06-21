#define BLYNK_TEMPLATE_ID "TMPL3KuKCcAT9"
#define BLYNK_TEMPLATE_NAME "TEMP AND ULTRASONIC INTEGRATED"
#define BLYNK_AUTH_TOKEN "93F3FYKaBTPeH6GiNYSSt0aXahEQ8eFv"

#define BLYNK_PRINT Serial
#include<WiFi.h>
#include<WifiClient.h>
#include<BlynkSimpleEsp32.h>
#include "DHT.h"
#include <Adafruit_SSD1306.h>

char auth[]=BLYNK_AUTH_TOKEN;
char ssid[]="vivo T1 5G";
char pass[]="00000000";
BlynkTimer timer;

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH,SCREEN_HEIGHT,&Wire,-1);
#define DHTPIN 4
#define DHTTYPE DHT11
DHT Dht(DHTPIN,DHTTYPE);
float temp,hum;

#define BUZZER 13
#define TRIG 18
#define ECHO 19
long duration;
float distance = 0;

void setup() {
  Serial.begin(115200);
  Dht.begin();
  pinMode(BUZZER,OUTPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN,ssid,pass);
    pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
  pinMode(BUZZER,OUTPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN,ssid,pass);
  timer.setInterval(1000L,sendSensor);
  Serial.begin(9600);
display.begin(SSD1306_SWITCHCAPVCC,0x3C);
delay(2000);
display.clearDisplay();
display.setTextSize(1);
display.setTextColor(WHITE);
display.setCursor(0,10);
  temp=Dht.readTemperature();
 hum=Dht.readHumidity();
}

void loop() {
  Blynk.run();
  timer.run();
    display.print(" TEMPERATURE: ");
 display.println(temp);
 display.print(" HUMIDITY   : ");
 display.println(hum);
delay(2000);
display.display();
digitalWrite(TRIG,LOW);
  delayMicroseconds(5);
  digitalWrite(TRIG,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG,LOW);
  duration = pulseIn(ECHO,HIGH);
  distance = 0.034 * (duration/2);
  display.print("DISTANCE MEASURED(cm): ");
  display.println(distance);
  delay(1000);
}
 
void sendSensor()
{
temp=Dht.readTemperature();
 hum=Dht.readHumidity();
 Serial.print(" TEMPERATURE: ");
 Serial.println(temp);
 Serial.print(" HUMIDITY   : ");
 Serial.println(hum);
 delay(2000);
  Blynk.virtualWrite(V0,temp);
  Blynk.virtualWrite(V1,hum);
  
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
  
  Blynk.virtualWrite(V3,distance);
}

BLYNK_WRITE(V2)
{
  int value=param.asInt();
  Blynk.virtualWrite(V2,value);
  if(value==1){
    digitalWrite(BUZZER,HIGH);
  }
  else{
    digitalWrite(BUZZER,LOW);
  }
}


