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
#include "ui/ui.h"
#include <ctime>


void extractAndPrintCompileTime()
{
  const char* compileTime = __TIME__;

  // Extract hour (assumes HH:MM:SS format)
  int hour = (compileTime[0] - '0') * 10 + (compileTime[1] - '0');

  // Extract minute
  int minute = (compileTime[3] - '0') * 10 + (compileTime[4] - '0');


  Serial.print("Compiled Time: ");
  Serial.print(hour);
  Serial.print(":");
  Serial.println(minute);
}

void hoursAndMinsPassSinceClockStart(){
  
  unsigned long currentMillis = millis();

  // Calculate seconds since midnight
  unsigned long seconds = currentMillis / 1000;

  // Extract hour (0-23) and minute (0-59)
  int hour = seconds / 3600;
  int minute = (seconds % 3600) / 60;

  Serial.print("Current Time: ");
  Serial.print(hour);
  Serial.print(":");
  Serial.println(minute);
}


void timer_callback(lv_timer_t * timer) {
    updateTime();  // Call your updateTime function here

}

void loop()
{
  lv_timer_handler();
  lv_timer_create(timer_callback, 1000, NULL);
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
