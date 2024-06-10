#include <lvgl.h>

#include <Arduino.h>
#include "display.h"
#include "ui/ui.h"
#include "sound/active_buzzer/active_buzzer.h"

#define DELAY_TIME 5
Ultrasonic ult(200, DELAY_TIME);
ActiveBuzzer activeBuzzer;

void setup()
{
  Serial.begin( 9600 ); 

  lcdInit();
  lvglInit();
  ui_init();
}


void loop()
{
  float tmp = ult.getDistanceInCmOnceInDelay(true);
  //For some reason at the start returns 0.00
  if(tmp < 10 && tmp >= 0.01){
    /*
    Serial.println("Im here!");
    Serial.print(tmp);
    Serial.print("<");
    Serial.println(10);
    */
    activeBuzzer.playAlarm(ult);
  }
  
  lv_timer_handler();
  updateTime();
  delay(DELAY_TIME);
}