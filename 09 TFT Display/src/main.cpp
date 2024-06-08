#include <lvgl.h>

#include <Arduino.h>
#include "display.h"
#include "ui/ui.h"



static uint8_t conv2d(const char* p); // Forward declaration needed for IDE 1.6.x
// Function to extract numbers from compile time string
static uint8_t conv2d(const char* p) {
  uint8_t v = 0;
  if ('0' <= *p && *p <= '9')
    v = *p - '0';
  return 10 * v + *++p - '0';
}

uint8_t hh = conv2d(__TIME__), mm = conv2d(__TIME__ + 3), ss = conv2d(__TIME__ + 6); // Get H, M, S from compile time



  int th = 0;
  int tm = 0;

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
  delay(5);
/*
  char hour[2];
  char min[2]; 
  itoa(hh+th++, hour, 10);
  itoa(mm+tm++, min, 10);

  delay(1000);
*/
/*
  Serial.print(hh);
  Serial.print(" ");
  Serial.print(mm);
  Serial.print(" ");
  Serial.println(ss);
*/
  //Serial.println(millis());
}
