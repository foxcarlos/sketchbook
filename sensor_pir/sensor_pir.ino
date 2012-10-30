/*
  Ejemplo de Sensor PIR
  Sensor de proximidad que al momento de detectar movimiento
  Enciende un Bobillo por 2 segundos y luego lo apaga.
  */
 
// Pin 13 conectado en arduino el cual permite encender el Bomillo.
// Pin 2 Conectado al Sensor de Proximidad o movimiento
int led = 13;
int pirpin = 2;


// the setup routine runs once when you press reset:
void setup() {                
  // Inicializa o apertuta el Puerto serial, 
  // Inicializa el pin 13 como salidad 
  // Inicializa el pin 2 como entrada.
  
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(pirpin, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  int pirVal = digitalRead(pirpin);
  
  if(pirVal == 1){
    Serial.println("Movimiento");
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(5000);               // wait for a second
  }
  else {
    Serial.println("Nadie");
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  }
}
