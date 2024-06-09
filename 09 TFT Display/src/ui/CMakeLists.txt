SET(SOURCES ui_Splash.c
    ui_TimeSetup.c
    ui_TimeHumidity.c
    ui_Alarm.c
    ui.c
    ui_comp_hook.c
    ui_helpers.c
    ui_events.c
    ui_img_1386888695.c
    ui_img_1_png.c
    ui_img_687697873.c
    ui_img_2049616620.c
    ui_img_weather_1_png.c
    fonts/ui_font_ClockDigits.c)

add_library(ui ${SOURCES})
