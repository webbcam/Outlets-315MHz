/**
The MIT License (MIT)

Copyright (c) 2015 Cameron J. Webb (cam@webbhacks.com)

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

#include "Arduino.h"
#include "ChannelF.h"

ChannelF::ChannelF(int pin) : Outlet(pin) {
    //  make outlet instance
}

void ChannelF::toggle(int channel, bool state) {
    for (int i=0; i<5; i++) {   //  send signal 5x to cover for noise picked up in receiver
        switch(channel) {
            case 1:
                state ? ch1ON() : ch1OFF();
                break;
            case 2:
                state ? ch2ON() : ch2OFF();
                break;
            case 3:
                state ? ch3ON() : ch3OFF();
                break;
        }
    }
}

void ChannelF::ch1(bool state) {

    if (state == true) {
        //  turn outlet on
        for (int i=0; i<5; i++) {   
            ch1ON();    // send x5 to account for poor receiver 
        }
    }
    else {
        //  turn outlet off
        for (int i=0; i<5; i++) {  
            ch1OFF();   //  send x5 to account for poor receiver 
        }
    }
}

void ChannelF::ch2(bool state) {

    if (state == true) {
        //  turn outlet on
        for (int i=0; i<5; i++) {   
            ch2ON();    // send x5 to account for poor receiver 
        }
    }
    else {
        //  turn outlet off
        for (int i=0; i<5; i++) {  
            ch2OFF();   //  send x5 to account for poor receiver 
        }
    }
}

void ChannelF::ch3(bool state) {

    if (state == true) {
        //  turn outlet on
        for (int i=0; i<5; i++) {   
            ch3ON();    // send x5 to account for poor receiver 
        }
    }
    else {
        //  turn outlet off
        for (int i=0; i<5; i++) {  
            ch3OFF();   //  send x5 to account for poor receiver 
        }
    }
}


void ChannelF::ch1ON() {
    preamble();
    for (int i=0; i<2; i++) {
        highShort();
        lowLong();
    }

    highLong();
    lowShort();
    highShort();
    lowLong();

    for (int i=0; i<6; i++) {
        highShort();
        lowLong();
    }
    delayMicroseconds(11800);
}

void ChannelF::ch1OFF() {
    preamble();
    for (int i=0; i<2; i++) {
        highShort();
        lowLong();
    }
    highShort();
    lowLong();
    highLong();
    lowShort();

    for (int i=0; i<6; i++) {
        highShort();
        lowLong();
    }
    delayMicroseconds(11800);
}

void ChannelF::ch2ON() {
    preamble();
    for (int i=0; i<4; i++) {
        highShort();
        lowLong();
    }

    highLong();
    lowShort();
    highShort();
    lowLong();

    for (int i=0; i<4; i++) {
        highShort();
        lowLong();
    }
    delayMicroseconds(11800);
}

void ChannelF::ch2OFF() {
    preamble();
    for (int i=0; i<4; i++) {
        highShort();
        lowLong();
    }

    highShort();
    lowLong();
    highLong();
    lowShort();

    for (int i=0; i<4; i++) {
        highShort();
        lowLong();
    }

    delayMicroseconds(11800);
}

void ChannelF::ch3ON() {
    preamble();

    highShort();
    lowLong();
    highLong();
    lowShort();

    for (int i=0; i<8; i++) {
        highShort();
        lowLong();
    }
    delayMicroseconds(11800);

}

void ChannelF::ch3OFF() {
    preamble();

    highLong();
    lowShort();
    highShort();
    lowLong();

    for (int i=0; i<8; i++) {
        highShort();
        lowLong();
    }

    delayMicroseconds(11800);
}


