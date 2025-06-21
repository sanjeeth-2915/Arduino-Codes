#include"BluetoothSerial.h"
BluetoothSerial SerialBT;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SerialBT.begin("vicraman");
  Serial.println(" the device started now you can pair it with other devices");
  

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    SerialBT.write(Serial.read());
  }
  if(SerialBT.available()){
    Serial.write(SerialBT.read());
  }
delay(20);
}
