#define BLYNK_PRINT Serial 
#define BLYNK_TEMPLATE_ID "TMPL3ptacNMOA"
#define BLYNK_TEMPLATE_NAME "TEMPERATURE HUMIDITY MONITORING"
#define BLYNK_AUTH_TOKEN "bKT5cnm0kb0I7J8itlo_DO6ckAQCeSOl"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "DHT.h"
#define DHTPIN 4
#define DHTTYPE DHT11
DHT Dht(DHTPIN,DHTTYPE);
float temp,hum;
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Redmi 9";
char pass[] ="12345678" ;
BlynkTimer timer;

#define BUZZER 13
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(BUZZER,OUTPUT);
  Dht.begin();
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

  temp=Dht.readTemperature();
hum=Dht.readHumidity();
Serial.print("TEMPERATURE:");
Serial.println(temp);
Serial.print("Humidity :");
Serial.println(hum);
  Blynk.virtualWrite(V0,temp);
  Blynk.virtualWrite(V1,hum);
delay(2000);
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
