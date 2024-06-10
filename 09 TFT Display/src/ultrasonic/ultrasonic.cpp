#include "pins.h"

#include <Arduino.h>
#include "ultrasonic.h"

Ultrasonic::Ultrasonic(short distanceRequestFrequencyMs, short sleepDelay): distanceRequestFrequencyMs(distanceRequestFrequencyMs), sleepDelay(sleepDelay){
    pinMode(ULTRA_TRIG, OUTPUT);
    pinMode(ULTRA_ECHO, INPUT);
}

void Ultrasonic::trigger(){
    digitalWrite(ULTRA_TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(ULTRA_TRIG, LOW);
}


float Ultrasonic::getDistanceInCmOnceInDelay(bool verbose){
    float distance = previousDistance;
    if(distanceRequestFrequencyMs <= sleepedTimeCounter){
        distance = getDistanceInCm();
        previousDistance = distance; //next function call this will be the previous distance
        if(verbose)
        {
            Serial.print("The distance:");
            Serial.println(distance);
            Serial.println();
        }
        sleepedTimeCounter = 0;
    }
    sleepedTimeCounter += sleepDelay;
    return distance;
}


float Ultrasonic::getDistanceInCm(){
    trigger();
    unsigned long duration = pulseIn(ULTRA_ECHO, HIGH);
    return 0.5 * duration * SPEED_OF_SOUND_CM;
}