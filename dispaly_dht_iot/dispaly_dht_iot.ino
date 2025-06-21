#include "DHT.h"
#include<Adafruit_SSD1306.h>
#define DHTPIN 4
#define DHTTYPE DHT11
DHT Dht(DHTPIN,DHTTYPE);
float temp,hum;
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH,SCREEN_HEIGHT,&Wire,-1);
void setup(){
  Dht.begin();
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC,0X3c);
  delay(2000);

  display.setTextSize(1);
  display.setTextColor(WHITE);
}
void loop(){
temp=Dht.readTemperature();
hum=Dht.readHumidity();
Serial.print("TEMPERATURE:");
Serial.println(temp);
Serial.print("Humidity :");
Serial.println(hum);
delay(2000);
   display.clearDisplay();
  display.setCursor(0,10);
  display.print("TEMPERATURE:");
  display.println(temp);
  display.print("HUMIDITY:");
  display.println(hum);
  display.display();


}
