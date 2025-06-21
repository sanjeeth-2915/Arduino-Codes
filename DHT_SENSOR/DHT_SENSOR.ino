#include<LiquidCrystal_I2C.h>
#include"DHT.h"
#define pin 7
#define type DHT11
LiquidCrystal_I2C lcd(0x27,20,4);
DHT sensor(pin,type);

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  lcd.setCursor(1,0);
  Serial.begin(9600);
  sensor.begin();

}
void disp(char*str,float f){
  Serial.print(str);
  Serial.print(f);
}
void loop() {
  // put your main code here, to run repeatedly:
float hum=sensor.readHumidity();
float cel=sensor.readTemperature();
float far=sensor.readTemperature(true);
if(isnan(hum)||isnan(cel)||isnan(far))
{
  Serial.println("cannot read data");
  return;
}
disp("humidity: ",hum);
disp("clecius: ",cel);
disp("fahrenheit: ",far);
Serial.println();
lcd.setCursor(0,0);
lcd.print("H: ");
lcd.print(hum);
delay(2000);
lcd.print("c: ");
lcd.print(cel);
delay(2000);
lcd.print("F: ");
lcd.print(far);
delay(2000);
}
