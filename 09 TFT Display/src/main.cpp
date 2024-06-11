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
RgbLED led;

void setup()
{
  Serial.begin( 9600 ); 

  lcdInit();
  lvglInit();
  ui_init();
}

//int waiter = 1000;
int waiterCounter = 0;
void loop()
{
  //if(waiterCounter >= waiter){
    if(isAlarmEnabled()){
      alarmm.updateAlarmIfNecessary(getAlarmRollerHour(), getAlarmRollerMinute(), isSnoozeEnabled(), isAlarmEnabled(), currentHour, currentMinute);
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
     /*
      Serial.print(alarmm.delayWaited);
      Serial.println();
      Serial.println();
      */
      alarmm.playAlarmIfTheTimeMatches(ult, activeBuzzer, led);
      //DELAY_TIME * 2 means that alarm sound will play 2 iterations before ultrasonic sensor will start
      alarmm.checkUserReactoinIfAlarmEnabled(ult, activeBuzzer, DELAY_TIME * 2, DELAY_TIME);
    }
    //waiterCounter=0;
    //Serial.println("\n");
  //}
  //waiterCounter += 5;
  
  lv_timer_handler();
  updateTime();
  delay(DELAY_TIME);
}