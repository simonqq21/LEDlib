#ifndef LED_h
#define LED_h
#include "Arduino.h" 

#define LED_OFF 0
#define LED_ON 1 
#define LED_BLINK 2 
#define LED_ANALOGSET 3

class LED {
    public:
        LED(int pin);
        void begin(); 
        void startLoop();
        void on();
        void off();
        void toggle();
        void set(bool state);
        void blink(unsigned int period, double dutyCycle);
        void aSet(int aValue);
    private:
        int _pin;
        int _ledMode;
        int _curLEDState, _nextLEDState;
        unsigned long _previousMillis;
        unsigned int _blinkingPeriod;
        unsigned int _blinkOnPeriod;
        unsigned int_blinkOffPeriod;
        int _analogValue;
};

#endif