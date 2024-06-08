// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.1
// LVGL version: 8.3.11
// Project name: Wecker

#include "ui.h"
#include "ui_helpers.h"
#include <lvgl.h>
#include <Arduino.h>

///////////////////// VARIABLES ////////////////////
void Appear_Animation(lv_obj_t * TargetObject, int delay);


// SCREEN: ui_Splash
void ui_Splash_screen_init(void);
void ui_event_Splash(lv_event_t * e);
lv_obj_t * ui_Splash;
lv_obj_t * ui_Logo;
lv_obj_t * ui_FETA;
lv_obj_t * ui_FetaText;


// SCREEN: ui_TimeHumidity
void ui_TimeHumidity_screen_init(void);
void ui_event_TimeHumidity(lv_event_t * e);
lv_obj_t * ui_TimeHumidity;
lv_obj_t * ui_Bckg1;
lv_obj_t * ui_Time;
lv_obj_t * ui_WeekdayDateMonth;
lv_obj_t * ui_Humidity;
lv_obj_t * ui_Drop;
lv_obj_t * ui_HumidityPercent;



// SCREEN: ui_Alarm
void ui_Alarm_screen_init(void);
void ui_event_Alarm(lv_event_t * e);
lv_obj_t * ui_Alarm;
lv_obj_t * ui_Bckg2;
lv_obj_t * ui_Wecker;
lv_obj_t * ui_WeckerSetup;
lv_obj_t * ui_HourRoller;
lv_obj_t * ui_Colon;
lv_obj_t * ui_MinRoller;
lv_obj_t * ui_EnableAlarm;
lv_obj_t * ui_Snooze;
lv_obj_t * ui____initial_actions0;
const lv_img_dsc_t * ui_imgset_[1] = {&ui_img_1_png};
const lv_img_dsc_t * ui_imgset_weather_[1] = {&ui_img_weather_1_png};

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////
void Appear_Animation(lv_obj_t * TargetObject, int delay)
{
    ui_anim_user_data_t * PropertyAnimation_0_user_data = lv_mem_alloc(sizeof(ui_anim_user_data_t));
    PropertyAnimation_0_user_data->target = TargetObject;
    PropertyAnimation_0_user_data->imgset = ui_imgset_;
    PropertyAnimation_0_user_data->imgset_size = sizeof(ui_imgset_) / (sizeof(lv_img_dsc_t *));
    PropertyAnimation_0_user_data->val = -1;
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 200);
    lv_anim_set_user_data(&PropertyAnimation_0, PropertyAnimation_0_user_data);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_y);
    lv_anim_set_values(&PropertyAnimation_0, -30, 0);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_out);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_deleted_cb(&PropertyAnimation_0, _ui_anim_callback_free_user_data);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_y);
    lv_anim_start(&PropertyAnimation_0);
    ui_anim_user_data_t * PropertyAnimation_1_user_data = lv_mem_alloc(sizeof(ui_anim_user_data_t));
    PropertyAnimation_1_user_data->target = TargetObject;
    PropertyAnimation_1_user_data->imgset = ui_imgset_;
    PropertyAnimation_1_user_data->imgset_size = sizeof(ui_imgset_) / (sizeof(lv_img_dsc_t *));
    PropertyAnimation_1_user_data->val = -1;
    lv_anim_t PropertyAnimation_1;
    lv_anim_init(&PropertyAnimation_1);
    lv_anim_set_time(&PropertyAnimation_1, 100);
    lv_anim_set_user_data(&PropertyAnimation_1, PropertyAnimation_1_user_data);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_1, _ui_anim_callback_set_opacity);
    lv_anim_set_values(&PropertyAnimation_1, 0, 255);
    lv_anim_set_path_cb(&PropertyAnimation_1, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_1, delay + 0);
    lv_anim_set_deleted_cb(&PropertyAnimation_1, _ui_anim_callback_free_user_data);
    lv_anim_set_playback_time(&PropertyAnimation_1, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_1, 0);
    lv_anim_set_early_apply(&PropertyAnimation_1, true);
    lv_anim_start(&PropertyAnimation_1);

}

///////////////////// FUNCTIONS ////////////////////
void ui_event_Splash(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        Appear_Animation(ui_Splash, 100);
        _ui_screen_change(&ui_TimeHumidity, LV_SCR_LOAD_ANIM_FADE_ON, 200, 1400, &ui_TimeHumidity_screen_init);
    }
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        Appear_Animation(ui_FETA, 200);
    }
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        Appear_Animation(ui_FetaText, 300);
    }
}
void ui_event_TimeHumidity(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT) {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_Alarm, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 0, &ui_Alarm_screen_init);
    }
}
void ui_event_Alarm(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_TimeHumidity, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0, &ui_TimeHumidity_screen_init);
    }
}

///////////////////// SCREENS ////////////////////

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Splash_screen_init();
    ui_TimeHumidity_screen_init();
    ui_Alarm_screen_init();
    ui____initial_actions0 = lv_obj_create(NULL);
    lv_disp_load_scr(ui_Splash);
}



//

char timeClock[] = "00:00";
char weekdayDateMonth[] = "Mon 28 Oct";
char humidity[] = "63%";

const char* compileTime = __TIME__;

void updateTimeClockVariable()
{
  // Extract hour
  int compilationTimeHours = (compileTime[0] - '0') * 10 + (compileTime[1] - '0');

  // Extract minute
  int compilationTimeMinutes = (compileTime[3] - '0') * 10 + (compileTime[4] - '0');

  // Extract seconds
  int compilationTimeSeconds = (compileTime[6] - '0') * 10 + (compileTime[7] - '0');

  //Seconds since midnight of compilation day
  unsigned long secondsSinceCompilationDayMidnight = millis() / 1000 + compilationTimeMinutes * 60 + compilationTimeHours * 3600;

  int minuteRaw = secondsSinceCompilationDayMidnight / 60;
  int minute = minuteRaw % 60;
  int hour = (minuteRaw / 60) % 24;

  //chars_written is the count of written chars
  int chars_written = snprintf(timeClock, sizeof(timeClock), "%02d:%02d", hour, minute);

}

void updateTime() {

    updateTimeClockVariable();
    
    lv_label_set_text(ui_Time, timeClock);
    lv_obj_invalidate(ui_Time);
}

void updateWeekdayDateMonth(){
    lv_label_set_text(ui_WeekdayDateMonth, weekdayDateMonth);
}

void updateHumidity(){
    lv_label_set_text(ui_HumidityPercent, humidity);
}