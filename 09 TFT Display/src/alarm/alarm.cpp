#include "alarm.h"

/*
Alarm::Alarm(unsigned short hourRollerValue, unsigned short minuteRollerValue, bool snooze, bool enabled): alarmHour(hourRollerValue), alarmMinute(minuteRollerValue), snooze(snooze), enabled(enabled){

}*/

void Alarm::updateAlarmIfNecessary(unsigned short hourRollerValue, unsigned short minuteRollerValue, bool snoozeCheckbox, bool enabledSwitch){
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
}

void Alarm::checkUserReactoinIfAlarmEnabled(Ultrasonic ult, ActiveBuzzer activeBuzzer){

    if(enabled && gotUserReaction == false)
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
    }
}

//Called for every beep
void Alarm::playAlarmIfTheTimeMatches(Ultrasonic ult, ActiveBuzzer activeBuzzer, unsigned short currentHour, unsigned short currentMin){
    if(alarmHour == currentHour && alarmMinute == currentMin)
    {
        if(gotUserReaction != true)
        {
            activeBuzzer.playAlarm(ult);
        }
    }
    else{
        gotUserReaction = false;
    }
}