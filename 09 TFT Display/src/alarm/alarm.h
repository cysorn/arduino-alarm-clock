#include "ultrasonic/ultrasonic.h"
#include "sound/active_buzzer/active_buzzer.h"

class Alarm{
    public:
        Alarm();
        void updateAlarmIfNecessary(unsigned short hourRollerValue, unsigned short minuteRollerValue, bool snooze, bool enabled);

        void checkIfAlarmSetAndUpdateIfNecessary();

        void checkUserReactoinIfAlarmEnabled(Ultrasonic ult, ActiveBuzzer activeBuzzer);

        void playAlarmIfTheTimeMatches(Ultrasonic ult, ActiveBuzzer activeBuzzer, unsigned short currentHour, unsigned short currentMin);

    private:
        unsigned short alarmHour = 24;
        unsigned short alarmMinute = 61;
        bool snooze = false;
        bool enabled = false;
        bool gotUserReaction = false;
};