const int RED = 5;
const int GREEN = 4;
const int BLUE = 0;

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop() { 
  analogWrite(RED, 0);
  analogWrite(GREEN, 0);
  analogWrite(BLUE,0);  
  delay (1000 );
  analogWrite(RED, 255);
  analogWrite(GREEN, 0);
  analogWrite(BLUE, 255); 
  delay (1000);
analogWrite(RED, 255);
  analogWrite(GREEN, 255);
  analogWrite(BLUE,0);  
  delay (1000);
  analogWrite(RED, 0);
  analogWrite(GREEN,255 );
  analogWrite(BLUE, 255); 
  delay (1000);









}
