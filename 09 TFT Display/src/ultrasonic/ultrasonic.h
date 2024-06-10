
class Ultrasonic
{
    public:
        Ultrasonic(short distanceRequestFrequencyMs, short sleepDelay);
        float getDistanceInCmOnceInDelay(bool verbose);
        float getDistanceInCm();

    private:
        #define SPEED_OF_SOUND 343.2f
        #define SPEED_OF_SOUND_CM (SPEED_OF_SOUND / 10000.0)

        void trigger();

        short distanceRequestFrequencyMs = 0;
        int sleepedTimeCounter = 0;
        int sleepDelay = 0;
};