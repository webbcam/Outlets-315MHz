/**
The MIT License (MIT)

Copyright (c) 2015 Cameron J. Webb  (cam@webbhacks.com)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
**/

#include "Outlet.h"
#include "Arduino.h"

unsigned long _PULSE = 0.30 * 1000; //  milliseconds -> microseconds
unsigned long _LONG = 6 * _PULSE;
unsigned long _SHORT = 2 * _PULSE;

Outlet::Outlet(int pin) {
    DATA_PIN = pin;
    pinMode(DATA_PIN, OUTPUT);
    digitalWrite(DATA_PIN, LOW);
}

void Outlet::highLong() {
    digitalWrite(DATA_PIN, HIGH);
    delayMicroseconds(_LONG);
    digitalWrite(DATA_PIN, LOW);
}

void Outlet::highShort() {
    digitalWrite(DATA_PIN, HIGH);
    delayMicroseconds(_SHORT);
    digitalWrite(DATA_PIN, LOW);
}

void Outlet::lowLong() {
    delayMicroseconds(_LONG);
}

void Outlet::lowShort() {
    delayMicroseconds(_SHORT);
}

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