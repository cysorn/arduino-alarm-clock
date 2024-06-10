#include <Arduino.h>
#include "active_buzzer.h"
#include "pins.h"

int passive_buzzer_notes[] = {
        HIGH, LOW, HIGH, LOW, HIGH, LOW, HIGH, LOW
        };

int passive_buzzer_durations[] = {
       200, 400, 600, 200, 400, 200, 400
        };


ActiveBuzzer::ActiveBuzzer(){
    pinMode(BUZZER, OUTPUT);
}


//WORKAROUND:
//Add global increment. Increment it once here, Change the global delay
//Let it go out and iterate loop with the delay and come back as long the hand is there
//Once hand is not there anymore, put back the standard programm delay
void ActiveBuzzer::playAlarm(Ultrasonic ult){
    digitalWrite(BUZZER, HIGH);
    delay(400);
    digitalWrite(BUZZER, LOW);
}

/*
void ActiveBuzzer::playAlarm(Ultrasonic ult){
  int size = sizeof(passive_buzzer_durations) / sizeof(int);
  Serial.println("I'm in the function");
  
  // Declare and initialize tmp inside the function
  float tmp = ult.getDistanceInCm();
  Serial.print("tmp: ");
  Serial.println(tmp);
  
  do{
    Serial.println("I'm in while");
    for (int note = 0; note < size; note++) {
      Serial.println("I'm in for");
      Serial.print("tmp:");
      Serial.println(tmp);
      digitalWrite(BUZZER, passive_buzzer_notes[note]);
      delay(passive_buzzer_durations[note]);
      digitalWrite(BUZZER, !passive_buzzer_notes[note]);

      if(tmp < 10 && tmp >= 0.01){
        digitalWrite(BUZZER, LOW);
        break;
      }
      // Update tmp inside the loop for continuous reading
      tmp = ult.getDistanceInCm();
    }
  }while(tmp < 10 && tmp >= 0.01);
  Serial.println("I'm ready to exit the function.");
}
*/