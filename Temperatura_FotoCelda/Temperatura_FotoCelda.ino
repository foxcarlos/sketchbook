int led = 12;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

int temperatura( int valorTemp){
  float kelvin = 0;
  float celcius = 0;
  float celcius2 = 0;
  
  kelvin = valorTemp * (5/1024.0*1000/10);
  celcius2 = kelvin - 2.5 - 273.15;
  celcius = kelvin - 273.15;
  Serial.print(celcius);Serial.println(" Centigrados Crudo");
  Serial.print(celcius2);Serial.println(" Centigrados con - 2.5");
  Serial.println("=======================");
}

int fotoCelda(int valorFotoCelda){
  int cambio = 0; //0 apagado, 1 encendido
  
  if (valorFotoCelda<=200){
    digitalWrite(led, HIGH);
    if (cambio == 1){
      Serial.println(1);
      cambio = 0;
    }
  }
  else{
    digitalWrite(led, LOW);
    if (cambio == 0){
      Serial.println(0);
      cambio = 1;
    }
  }  
} 

void loop() {
  int sensorTempValue = analogRead(A0);
  temperatura(sensorTempValue);
  
  int sensorFotoValue = analogRead(A1);
  fotoCelda(sensorFotoValue);
  //Tiempo de  Segundos
  delay(5000);
}
