float vt = 0;
int gc = 0;
float kelvin = 0;
float celcius = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {

  int sensorValue = analogRead(A0);
  kelvin = sensorValue * (5/1024.0*1000/10);
  celcius = kelvin - 2.5 - 273.15;
  Serial.println(sensorValue);
  Serial.print(celcius);Serial.println(" Celcius");
  Serial.println("=======================");
  delay(1000);
/*  vt = (sensorValue*5/1024.0*1000/10)-273.15;
  Serial.print(vt);Serial.println(" °C");
  delay(1000);*/
}
