// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.1
// LVGL version: 8.3.11
// Project name: Wecker

#include "ui.h"

/*
uint8_t conv2d(const char* p) {
  uint8_t v = 0;
  if ('0' <= *p && *p <= '9')
    v = *p - '0';
  return 10 * v + *++p - '0';
}
*/

/*

char timeClock[] = "09:25";
char weekdayDateMonth[] = "Mon 28 Oct";
char humidity[] = "63%";

void updateTime(){
    uint8_t hh = conv2d(__TIME__), mm = conv2d(__TIME__ + 3), ss = conv2d(__TIME__ + 6); // Get H, M, S from compile time
    lv_label_set_text(ui_Time, timeClock);
}

void updateWeekdayDateMonth(){
    lv_label_set_text(ui_WeekdayDateMonth, weekdayDateMonth);
}

void updateHumidity(){
    lv_label_set_text(ui_HumidityPercent, humidity);
}
*/

void ui_TimeHumidity_screen_init(void)
{
    ui_TimeHumidity = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_TimeHumidity, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Bckg1 = lv_img_create(ui_TimeHumidity);
    lv_img_set_src(ui_Bckg1, &ui_img_1_png);
    lv_obj_set_width(ui_Bckg1, LV_SIZE_CONTENT);   /// 320
    lv_obj_set_height(ui_Bckg1, LV_SIZE_CONTENT);    /// 240
    lv_obj_set_align(ui_Bckg1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Bckg1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Bckg1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Time = lv_label_create(ui_TimeHumidity);
    lv_obj_set_width(ui_Time, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Time, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Time, LV_ALIGN_CENTER);
    updateTime();
    lv_obj_set_style_text_font(ui_Time, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_WeekdayDateMonth = lv_label_create(ui_TimeHumidity);
    lv_obj_set_width(ui_WeekdayDateMonth, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_WeekdayDateMonth, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_WeekdayDateMonth, 0);
    lv_obj_set_y(ui_WeekdayDateMonth, 47);
    lv_obj_set_align(ui_WeekdayDateMonth, LV_ALIGN_CENTER);
    updateWeekdayDateMonth();
    lv_obj_set_style_text_font(ui_WeekdayDateMonth, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Humidity = lv_obj_create(ui_TimeHumidity);
    lv_obj_remove_style_all(ui_Humidity);
    lv_obj_set_width(ui_Humidity, 100);
    lv_obj_set_height(ui_Humidity, 85);
    lv_obj_set_x(ui_Humidity, 121);
    lv_obj_set_y(ui_Humidity, -77);
    lv_obj_set_align(ui_Humidity, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Humidity, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Drop = lv_img_create(ui_Humidity);
    lv_img_set_src(ui_Drop, &ui_img_weather_1_png);
    lv_obj_set_width(ui_Drop, LV_SIZE_CONTENT);   /// 16
    lv_obj_set_height(ui_Drop, LV_SIZE_CONTENT);    /// 22
    lv_obj_set_align(ui_Drop, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Drop, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Drop, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_img_recolor(ui_Drop, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_Drop, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_HumidityPercent = lv_label_create(ui_Humidity);
    lv_obj_set_width(ui_HumidityPercent, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_HumidityPercent, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_HumidityPercent, 4);
    lv_obj_set_y(ui_HumidityPercent, 22);
    lv_obj_set_align(ui_HumidityPercent, LV_ALIGN_CENTER);
    updateHumidity();
    lv_obj_set_style_text_font(ui_HumidityPercent, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_TimeHumidity, ui_event_TimeHumidity, LV_EVENT_ALL, NULL);

}
