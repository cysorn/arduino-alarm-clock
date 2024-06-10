#include <lvgl.h>

#include <Arduino.h>
#include "display.h"
#include "ui/ui.h"
#include "sound/active_buzzer/active_buzzer.h"
#include "alarm/alarm.h"

#define DELAY_TIME 5
Ultrasonic ult(200, DELAY_TIME);
ActiveBuzzer activeBuzzer;
Alarm alarm;

void setup()
{
  Serial.begin( 9600 ); 

  lcdInit();
  lvglInit();
  ui_init();
}


void loop()
{

  if(isAlarmEnabled()){
    alarm.updateAlarmIfNecessary(getAlarmRollerHour(), getAlarmRollerMinute(), isSnoozeEnabled(), isAlarmEnabled());
    alarm.checkUserReactoinIfAlarmEnabled(ult, activeBuzzer);
  }
  
  lv_timer_handler();
  updateTime();
  delay(DELAY_TIME);
}