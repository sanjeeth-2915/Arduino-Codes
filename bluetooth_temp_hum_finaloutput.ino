#include "BluetoothSerial.h"
BluetoothSerial SerialBT;
#include "DHT.h"
#define DHTPIN 4
#define DHTTYPE DHT11
DHT Dht(DHTPIN,DHTTYPE);
float temp,hum;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
SerialBT.begin("ENA PAKURA MUDITU PODA");
Serial.println("The device started,now you can pair it with");
 Dht.begin();
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 temp=Dht.readTemperature();
 hum=Dht.readHumidity();
 SerialBT.print(" TEMPERATURE: ");
 SerialBT.println(temp);
 SerialBT.print(" HUMIDITY   : ");
 SerialBT.println(hum);
 delay(2000);
if(Serial.available()){
  SerialBT.write(Dht.readTemperature());
}
if(SerialBT.available()){
  SerialBT.write(Dht.readHumidity());
}
delay(20);
}
