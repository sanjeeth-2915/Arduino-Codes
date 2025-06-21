#define BLYNK_PRINT Serial 

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Redmi 9";
char pass[] = "12345678";
BlynkTimer timer;

#define BUZZER 13
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(BUZZER,OUTPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(1000L, sendSensor);
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
  timer.run();
}

void sendSensor();
{
  Blynk.virtualWrite(V0,Variable1);
  Blynk.virtualWrite(V1,Variable2);
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
