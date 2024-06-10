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

void ActiveBuzzer::playAlarm(Ultrasonic ult){
  int size = sizeof(passive_buzzer_durations) / sizeof(int);

  for (int note = 0; note < size; note++) {
    digitalWrite(BUZZER, passive_buzzer_notes[note]);
    delay(passive_buzzer_durations[note]);
    digitalWrite(BUZZER, !passive_buzzer_notes[note]);

    float tmp = ult.getDistanceInCmOnceInDelay(true);
    if(tmp < 10 && tmp >= 0.01){
      digitalWrite(BUZZER, LOW);
      break;
    }
  }
}