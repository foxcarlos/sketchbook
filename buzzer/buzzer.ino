#define pausar 200

void beep(unsigned char pausa)
        {
            analogWrite(9, 20);
            delay(pausa);                 // Espera
            analogWrite(9, 0);            // Apaga
            delay(pausa);                 // Espera
        }
void setup()
        {
            pinMode(9, OUTPUT);
            //beep(50);
            //beep(50);
            //beep(50);
            delay(1000);
        }
     void loop()
       {    
         beep(pausar);
       }
