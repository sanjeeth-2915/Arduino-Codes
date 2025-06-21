const int tempPin = A0;     // TMP36 connected to analog pin A0
const int ledPin = 7;       // LED connected to digital pin D9
float temperature;          // Variable to store temperature
int thresholdTemp = 30;     // Threshold temperature in °

void setup()
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);  
}

void loop()
{
  int reading = analogRead(tempPin);
  
  // Convert analog reading to voltage
  float voltage = reading * 5.0 / 1023.0;
  
  // Convert voltage to temperature in Celsius
  temperature = (voltage - 0.5) * 100;

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  // Turn on LED if temperature exceeds threshold
  if (temperature > thresholdTemp) {
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    delay(1000);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(1000); // Wait 1 second
}
