/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
char recibido = '1';

// the setup routine runs once when you press rese
void setup() {                
  // initialize the digital pin as an output.
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  //digitalWrite(led, HIGH);
}

// the loop routine runs over and over again forever:
void loop() { 
  if (Serial.available()) {
    recibido = Serial.read();
    Serial.println(recibido);
    if (recibido=='1') {
      digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
      Serial.println('Led Encendido');  //Envia al puerto 
      delay(1000);              // wait for a second
      digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
      recibido = '0';
    }
    else {
      digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
      Serial.println('Led Apagado');  //Envia al puerto
      //delay(200);               // wait for a second
    }
  }
}
