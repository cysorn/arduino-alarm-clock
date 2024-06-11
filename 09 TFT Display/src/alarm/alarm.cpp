#include "alarm.h"

/*
Alarm::Alarm(unsigned short hourRollerValue, unsigned short minuteRollerValue, bool snooze, bool enabled): alarmHour(hourRollerValue), alarmMinute(minuteRollerValue), snooze(snooze), enabled(enabled){

}*/

void Alarm::updateAlarmIfNecessary(unsigned short hourRollerValue, unsigned short minuteRollerValue, bool snoozeCheckbox, bool enabledSwitch, unsigned short currentHour, unsigned short currentMinute){
    bool changed = false;

    if(alarmHour != hourRollerValue)
    {
        alarmHour = hourRollerValue;
        changed = true;
    }
    if(alarmHour != minuteRollerValue)
    {
        alarmMinute = minuteRollerValue;
        changed = true;
    }
    if(snooze != snoozeCheckbox){
        snooze = snoozeCheckbox;
        changed = true;
    }
    if(enabled != enabledSwitch)
    {
        enabled = enabledSwitch; 
        changed = true;
    }

    if(changed == false)
    {
        gotUserReaction = false;
    }

    clockHour = currentHour;
    clockMinute = currentMinute;
}

void Alarm::checkUserReactoinIfAlarmEnabled(Ultrasonic ult, ActiveBuzzer activeBuzzer, int frequency, int dl){


    if(enabled && gotUserReaction == false && alarmTimeMatches())
    {
        if(frequency <= delayWaited)
        {
            float tmp = ult.getDistanceInCm();
            if(tmp < 20 && tmp >= 0.01){
                gotUserReaction = true;
                /*
                if(snooze)
                {
                    alarm
                }
                */
            }
            delayWaited = 0;
        }
        delayWaited += dl;
    }
}

//Called for every beep
void Alarm::playAlarmIfTheTimeMatches(Ultrasonic ult, ActiveBuzzer activeBuzzer, RgbLED led){
    if(alarmTimeMatches())
    {
        if(gotUserReaction != true)
        {
            activeBuzzer.playAlarm(ult);
            led.shineColor(255, 0, 0);
        }
    }
    else{
        gotUserReaction = false;
    }

    if(gotUserReaction){
        led.shineColor(0, 0, 0);
    }
}

bool Alarm::alarmTimeMatches(){
    return alarmHour == clockHour && alarmMinute == clockMinute;
}