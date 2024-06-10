#include "pitches.h"
#include "ultrasonic/ultrasonic.h"

class PassiveBuzzer{
    public:
        PassiveBuzzer();
        void playAlarm(Ultrasonic ult);

};
