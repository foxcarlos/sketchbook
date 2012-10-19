/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
int pirpin = 2;


// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(pirpin, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  int pirVal = digitalRead(pirpin);
  
  if(pirVal == 1){
    Serial.println(pirVal);
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    //delay(100);               // wait for a second
  }
  else {
    Serial.println(pirVal);
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  }
}