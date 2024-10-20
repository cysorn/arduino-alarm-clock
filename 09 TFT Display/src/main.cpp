#include <lvgl.h>

#include <Arduino.h>
#include "display.h"
#include "ui/ui.h"
#include "alarm/alarm.h"


//TODO:
//Snooze function
//After snooze the alarm time select must be locked

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

int waiterCounter = 0;
void loop()
{
    if(isAlarmEnabled()){
      alarmm.updateAlarmIfNecessary(getAlarmRollerHour(), getAlarmRollerMinute(), isSnoozeEnabled(), isAlarmEnabled(), currentHour, currentMinute);

      alarmm.playAlarmIfTheTimeMatches(ult, activeBuzzer, led);
      alarmm.checkUserReactoinIfAlarmEnabled(ult, activeBuzzer, DELAY_TIME * 2, DELAY_TIME);
    }
  lv_timer_handler();
  updateTime();
  delay(DELAY_TIME);
}
