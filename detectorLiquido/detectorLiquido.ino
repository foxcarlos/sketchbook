/*
  Multiple tone player
 
 Plays multiple tones on multiple pins in sequence
 
 circuit:
 * 3 8-ohm speaker on digital pins 6, 7, and 11
 
 created 8 March 2010
 by Tom Igoe 
 based on a snippet from Greg Borenstein

This example code is in the public domain.
 
 http://arduino.cc/en/Tutorial/Tone4
 
 */
 //Cuando arranca----------------------------------------------------------------------------------------
 #include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4,4,4,4,4 };
//-----------------------------------------------------------------------------------------

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  //Aqui se genera el tono de arranque ---------------------------------
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/noteDurations[thisNote];
    tone(8, melody[thisNote],noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
  //-----------------------------------------------------------------------------------------
}

void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  Serial.println(voltage);
  delay(100);
  
  if (voltage > 2){
    Serial.println("Hay señal en el pin 0 analogo");
    delay(5);        // delay in between reads for stability
    
    //sonar
    // turn off tone function for pin 11:
     noTone(8);			
    // play a note on pin 6 for 200 ms:
    tone(8, 440, 200);
    delay(200);
    
    // turn off tone function for pin 6:
    noTone(8);
    // play a note on pin 7 for 500 ms:
    tone(8, 494, 500);
    delay(500);
    
    // turn off tone function for pin 7:
    noTone(8);  
    // play a note on pin 11 for 500 ms:
    tone(8, 523, 300);
    delay(300);
  }
  else{
    Serial.println("No hay señal");
  }

}
