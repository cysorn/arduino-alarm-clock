// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.1
// LVGL version: 8.3.11
// Project name: Wecker

#ifndef _WECKER_UI_H
#define _WECKER_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined __has_include
#if __has_include("lvgl.h")
#include "lvgl.h"
#elif __has_include("lvgl/lvgl.h")
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif
#else
#include "lvgl.h"
#endif

#include "ui_helpers.h"
#include "ui_events.h"

void Appear_Animation(lv_obj_t * TargetObject, int delay);
// SCREEN: ui_Splash
void ui_Splash_screen_init(void);
void ui_event_Splash(lv_event_t * e);
extern lv_obj_t * ui_Splash;
extern lv_obj_t * ui_Logo;
extern lv_obj_t * ui_FETA;
extern lv_obj_t * ui_FetaText;
// SCREEN: ui_TimeSetup
void ui_TimeSetup_screen_init(void);
extern lv_obj_t * ui_TimeSetup;
extern lv_obj_t * ui_Bckg4;
extern lv_obj_t * ui_TimeSetupLabel;
extern lv_obj_t * ui_TimeChoose;
extern lv_obj_t * ui_HourChooseRoller;
extern lv_obj_t * ui_ColonTimeChoose;
extern lv_obj_t * ui_MinChooseRoller;
extern bool timeIsSeted;
extern char timeClock[];


void ui_event_CheckMark(lv_event_t * e);
extern lv_obj_t * ui_CheckMark;
// SCREEN: ui_TimeHumidity
void ui_TimeHumidity_screen_init(void);
void ui_event_TimeHumidity(lv_event_t * e);
extern lv_obj_t * ui_TimeHumidity;
extern lv_obj_t * ui_Bckg1;
extern lv_obj_t * ui_Time;
extern lv_obj_t * ui_Humidity;
extern lv_obj_t * ui_Drop;
extern lv_obj_t * ui_HumidityPercent;
// SCREEN: ui_Alarm
void ui_Alarm_screen_init(void);
void ui_event_Alarm(lv_event_t * e);
extern lv_obj_t * ui_Alarm;
extern lv_obj_t * ui_Bckg2;
extern lv_obj_t * ui_Wecker;
extern lv_obj_t * ui_WeckerSetup;
extern lv_obj_t * ui_HourRoller;
extern lv_obj_t * ui_Colon;
extern lv_obj_t * ui_MinRoller;
extern lv_obj_t * ui_EnableAlarm;
extern lv_obj_t * ui_Snooze;
extern lv_obj_t * ui____initial_actions0;


LV_IMG_DECLARE(ui_img_1386888695);    // assets/logo2-min.png
LV_IMG_DECLARE(ui_img_1_png);    // assets/1.png
LV_IMG_DECLARE(ui_img_687697873);    // assets/check_mark_not_pressed-min.png
LV_IMG_DECLARE(ui_img_2049616620);    // assets/check_mark-min.png
LV_IMG_DECLARE(ui_img_weather_1_png);    // assets/weather_1.png



LV_FONT_DECLARE(ui_font_ClockDigits);

void updateTime();

bool isAlarmEnabled();
bool isSnoozeEnabled();
unsigned short getAlarmRollerHour();
unsigned short getAlarmRollerMinute();

void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif