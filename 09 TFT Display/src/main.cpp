#include <lvgl.h>

#include <Arduino.h>
#include "display.h"
#include "ui/ui.h"
#include "alarm/alarm.h"


//TODO:
//Snooze doesn't work yet
//After snooze the alarm roller must not move
//Add 5 sec hand hold to completely disable alarm and not only disable snooze

#define DELAY_TIME 5
Ultrasonic ult(200, DELAY_TIME);
ActiveBuzzer activeBuzzer;
Alarm alarmm;

void setup()
{
  Serial.begin( 9600 ); 

  lcdInit();
  lvglInit();
  ui_init();
}

////int waiter = 1000;
int waiterCounter = 0;
void loop()
{
  //if(waiterCounter >= waiter){
    if(isAlarmEnabled()){
      alarmm.updateAlarmIfNecessary(getAlarmRollerHour(), getAlarmRollerMinute(), isSnoozeEnabled(), isAlarmEnabled());
      /*
      Serial.print("Roller hour:");
      Serial.println(getAlarmRollerHour());
      Serial.print("Roller minute:");
      Serial.println(getAlarmRollerMinute());
      Serial.print("Is snooze enabled:");
      Serial.println(isSnoozeEnabled());
      Serial.print("Is alarm enabled:");
      Serial.println(isAlarmEnabled());
      */
      alarmm.playAlarmIfTheTimeMatches(ult, activeBuzzer, currentHour, currentMinute);
      alarmm.checkUserReactoinIfAlarmEnabled(ult, activeBuzzer);
    }
    //waiterCounter=0;
    //Serial.println("\n");
  //}
  //waiterCounter += 5;
  
  lv_timer_handler();
  updateTime();
  delay(DELAY_TIME);
}