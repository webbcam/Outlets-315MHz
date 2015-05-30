/*********************************************************************
This is a library to control "Woods Wireless Remote Control Outlets"
with a 315MHz RF Transmitter and Arduino

You can pick up a set of outlets here:   
        https://amzn.com/B003ZTWYXY
Along with a transmitter to talk to it:
        http://amzn.com/B00LNADJS6

Please see http://www.webbhacks.com/Outlets
for more detailed information on this project

Written by Cameron J. Webb  (cam@webbhacks.com)

Copyright (c) 2015 Cameron J. Webb  
MIT License, check LICENSE for more information
All text above must be included in any redistribution

**********************************************************************
                         Outlet Interface Class
*********************************************************************/

#include "Outlet.h"
#include "Arduino.h"

//  length of pulsewidth for signals (same for all commands)
unsigned long _PULSE = 0.30 * 1000; //  milliseconds -> microseconds
unsigned long _LONG = 6 * _PULSE;
unsigned long _SHORT = 2 * _PULSE;

Outlet::Outlet(int pin) {
    DATA_PIN = pin;     //  pin of MCU to send signal to transmitter
    pinMode(DATA_PIN, OUTPUT);
    digitalWrite(DATA_PIN, LOW);    // default state is low
}

//  long pulse width (high)
void Outlet::highLong() {
    digitalWrite(DATA_PIN, HIGH);
    delayMicroseconds(_LONG);
    digitalWrite(DATA_PIN, LOW);
}

//  short pulse width (high)
void Outlet::highShort() {
    digitalWrite(DATA_PIN, HIGH);
    delayMicroseconds(_SHORT);
    digitalWrite(DATA_PIN, LOW);
}

//  long delay (low)
void Outlet::lowLong() {
    delayMicroseconds(_LONG);
}
//  short delay (low)
void Outlet::lowShort() {
    delayMicroseconds(_SHORT);
}

//  every signal starts out with this preamble
//  to initiate communication with outlet
void Outlet::preamble() {
    highShort();
    lowLong();
    highLong();
    lowShort();

    highLong();
    lowShort();
    highShort();
    lowLong();

    highLong();
    lowShort();
    highShort();
    lowLong();
}