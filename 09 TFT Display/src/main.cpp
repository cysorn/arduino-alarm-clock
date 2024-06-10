#include <lvgl.h>

#include <Arduino.h>
#include "display.h"
#include "ui/ui.h"
#include "ultrasonic/ultrasonic.h"

#define DELAY_TIME 5
Ultrasonic ult(200, DELAY_TIME);

void setup()
{
  Serial.begin( 9600 ); 

  lcdInit();
  lvglInit();
  ui_init();
}




void loop()
{
  ult.getDistanceInCmOnceInDelay(true);
  lv_timer_handler();
  updateTime();
  delay(DELAY_TIME);
}
