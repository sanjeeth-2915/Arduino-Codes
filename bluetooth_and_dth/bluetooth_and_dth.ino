#include "DHT.h"
#include "BluetoothSerial.h"
#define DHTPIN 4
#define DHTTYPE DHT11
DHT Dht(DHTPIN,DHTTYPE);
float temp,hum;
BluetoothSerial SerialBT;
void setup() {
  // put your setup code here, to run once:
Dht.begin();
SerialBT.begin("vicraman");
Serial.println("the device sterte now you can pair it with other devices");
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  temp=Dht.readTemperature();
hum=Dht.readHumidity();
SerialBT.print("TEMPERATURE:");
SerialBT.println(temp);
SerialBT.print("Humidity :");
SerialBT.println(hum);
delay(2000);

}
