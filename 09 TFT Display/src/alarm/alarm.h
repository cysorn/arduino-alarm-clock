#include "sound/active_buzzer/active_buzzer.h"
#include "led/rgb_led.h"

class Alarm{
    public:
    
        bool alarmTimeMatches();

        void updateAlarmIfNecessary(unsigned short hourRollerValue, unsigned short minuteRollerValue, bool snooze, bool enabled, unsigned short currentHour, unsigned short currentMin);

        void checkIfAlarmSetAndUpdateIfNecessary();

        void checkUserReactoinIfAlarmEnabled(Ultrasonic ult, ActiveBuzzer activeBuzzer, int frequency, int dl);

        void playAlarmIfTheTimeMatches(Ultrasonic ult, ActiveBuzzer activeBuzzer, RgbLED led);



    private:
        unsigned short alarmHour = 24;
        unsigned short alarmMinute = 61;
        unsigned short clockHour = 24;
        unsigned short clockMinute = 61;
        bool snooze = false;
        bool enabled = false;
        bool gotUserReaction = false;
        int delayWaited = 0;
};