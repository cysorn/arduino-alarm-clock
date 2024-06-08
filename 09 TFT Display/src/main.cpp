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

/*
void timer_callback(lv_timer_t * timer) {
    updateTime();  // Call your updateTime function here

}

//lv_timer_t
lv_timer_t *tma;
*/

void setup()
{

 
  Serial.begin( 9600 ); 

  lcdInit();
  lvglInit();
  ui_init();

}

/*
void updateTimeClockVariableAAA()
{
  char timeClock[] = "09:25";
  char weekdayDateMonth[] = "Mon 28 Oct";
  char humidity[] = "63%";

  const char* compileTime = __TIME__;

  //uint8_t hh = conv2d(__TIME__), mm = conv2d(__TIME__ + 3), ss = conv2d(__TIME__ + 6); // Get H, M, S from compile time

  // Extract hour (assumes HH:MM:SS format)
  int compilationTimeHours = (compileTime[0] - '0') * 10 + (compileTime[1] - '0');

  // Extract minute
  int compilationTimeMinutes = (compileTime[3] - '0') * 10 + (compileTime[4] - '0');

  // Extract seconds
  int compilationTimeSeconds = (compileTime[6] - '0') * 10 + (compileTime[7] - '0');

  //Time since midnight
  unsigned long secondsSinceCompilationDayMidnight = millis() / 1000 + compilationTimeMinutes * 60 + compilationTimeHours * 3600;

  // Extract hour (0-23) and minute (0-59)
  //int minute = (secondsRunning % 3600) / 60;

  int minuteRaw = secondsSinceCompilationDayMidnight / 60;
  int minute = minuteRaw % 60;
  int hour = (minuteRaw / 60) % 24;

  //chars_written is the count of written chars
  int chars_written = snprintf(timeClock, sizeof(timeClock), "%02d:%02d", hour, minute);

  Serial.print("Compilation: Hours ");
  Serial.println(compilationTimeHours);

  Serial.print("Compilation: Minutes ");
  Serial.println(compilationTimeMinutes);

  Serial.print("Compilation: Seconds ");
  Serial.println(compilationTimeSeconds);
  //--------------------

  Serial.print("Minute ");
  Serial.println(minute);

  Serial.print("Hour ");
  Serial.println(hour);

  //--------------------

  Serial.print("SecondsinceCompilation");
  Serial.println(secondsSinceCompilationDayMidnight);

  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
}
*/

void loop()
{
  lv_timer_handler();
  updateTime();
  delay(20);
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
