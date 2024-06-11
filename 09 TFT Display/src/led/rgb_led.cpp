#include "rgb_led.h"
#include <Arduino.h>

RgbLED::RgbLED()
{
    pinMode(LED_R, OUTPUT);              
    pinMode(LED_G, OUTPUT);
    pinMode(LED_B, OUTPUT);
}

void RgbLED::shineColor(short int red, short int green, short int blue){
    digitalWrite(LED_R, red);
    digitalWrite(LED_G, green);
    digitalWrite(LED_B, blue);
}