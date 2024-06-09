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
 

  //char * selectedValue;
  
  //lv_roller_get_selected_str(ui_HourChooseRoller, selectedValue, 8);

  if(ui_HourChooseRoller != NULL)
  {
    uint16_t buff = lv_roller_get_selected(ui_HourChooseRoller);
    Serial.print("Selected Hour: ");
    Serial.println(buff);
  }

   delay(5);
}
