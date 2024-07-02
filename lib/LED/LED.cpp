#include "Arduino.h"
#include "LED.h" 

LED::LED(int pin) {
    _pin = pin;
}

void LED::begin() {
    pinMode(_pin, OUTPUT);
}

void LED::startLoop() {
    // switch (_ledMode)
    // {
    // case /* constant-expression */:
    //     /* code */
    //     break;
    
    // default:
    //     break;
    // }
}

void LED::on() {
    _ledMode = LED_ON;
}

void LED::off() {
    _ledMode = LED_OFF;
}

void LED::toggle() {
    switch (_ledMode)
    {
    case LED_OFF:
        this->on();
        break;
    
    default:
        this->off();
        break;
    }
}

void LED::set(bool state) {
    if (state)
        this->on();
    else 
        this->off();
}

void LED::blink(unsigned int period, double dutyCycle) {
    
}

void LED::aSet(int aValue) {

}
