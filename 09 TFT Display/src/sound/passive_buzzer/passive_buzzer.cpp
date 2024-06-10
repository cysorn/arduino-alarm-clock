#include <Arduino.h>
#include "passive_buzzer.h"
#include "pins.h"

int melody[] = {
       
        };

        int durations[] = {
       
        };
PassiveBuzzer::PassiveBuzzer(){
    pinMode(BUZZER, OUTPUT);
}

void PassiveBuzzer::playAlarm(Ultrasonic ult){
    int size = sizeof(durations) / sizeof(int);

  for (int note = 0; note < size; note++) {
    //to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int duration = 1000 / durations[note];
    tone(BUZZER, melody[note], duration);

    //to distinguish the notes, set a minimum time between them.
    //the note's duration + 30% seems to work well:
    int pauseBetweenNotes = duration * 1.30;
    delay(pauseBetweenNotes);
    
    //stop the tone playing:
    noTone(BUZZER);
    float tmp = ult.getDistanceInCmOnceInDelay(true);
    if(tmp < 10 && tmp >= 0.01){
      break;
    }
  }
}