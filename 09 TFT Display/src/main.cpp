#include <lvgl.h>

#include <Arduino.h>
#include "display.h"
#include "ui/ui.h"


void setup()
{
 
  Serial.begin( 9600 ); 

  lcdInit();
  lvglInit();
  ui_init();

}

void loop()
{
  
  lv_timer_handler();
  updateTime();
  delay(5);
}
