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
                            CHANNEL F
*********************************************************************/

#include "Arduino.h"
#include "ChannelF.h"

ChannelF::ChannelF(int pin) : Outlet(pin) {
    //  make outlet instance with passed DATA pin
}

//  toggle() function
//  parameters:
//      int channel -> minor channel of outlet
//      boolean state -> true=on ; false=off
void ChannelF::toggle(int channel, bool state) {
    //  send signal 5x to cover for noise picked up in receiver
    for (int i=0; i<5; i++) {   
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

/*********************************************************************
                        ***    SIGNALS      ***
*********************************************************************/

//  Ch.1  -  ON
void ChannelF::ch1ON() {
    preamble(); // initiate communication with receiver
    
    //  fluff
    for (int i=0; i<2; i++) {
        highShort();
        lowLong();
    }

    // payload
    highLong();
    lowShort();
    highShort();
    lowLong();

    //  fluff
    for (int i=0; i<6; i++) {
        highShort();
        lowLong();
    }

    //  pause
    delayMicroseconds(11800);
}

//  Ch.1  -  OFF
void ChannelF::ch1OFF() {
    preamble(); //  initiate communication with receiver

    //  fluff
    for (int i=0; i<2; i++) {
        highShort();
        lowLong();
    }

    //  payload
    highShort();
    lowLong();
    highLong();
    lowShort();

    //  fluff
    for (int i=0; i<6; i++) {
        highShort();
        lowLong();
    }

    //  pause
    delayMicroseconds(11800);
}

//  Ch.2  -  ON
void ChannelF::ch2ON() {
    preamble(); //  initiate communication with receiver

    //  fluff
    for (int i=0; i<4; i++) {
        highShort();
        lowLong();
    }

    //  payload
    highLong();
    lowShort();
    highShort();
    lowLong();

    //  fluff
    for (int i=0; i<4; i++) {
        highShort();
        lowLong();
    }

    //  pause
    delayMicroseconds(11800);
}

//  Ch.2  -  OFF
void ChannelF::ch2OFF() {
    preamble(); //  initiate communication with receiver

    //  fluff
    for (int i=0; i<4; i++) {
        highShort();
        lowLong();
    }

    //  payload
    highShort();
    lowLong();
    highLong();
    lowShort();

    //  fluff
    for (int i=0; i<4; i++) {
        highShort();
        lowLong();
    }

    //  pause
    delayMicroseconds(11800);
}

//  Ch.3  -  ON
void ChannelF::ch3ON() {
    preamble(); //  initiate communication with receiver

    //  payload
    highShort();
    lowLong();
    highLong();
    lowShort();

    //  fluff
    for (int i=0; i<8; i++) {
        highShort();
        lowLong();
    }

    //  pause
    delayMicroseconds(11800);
}

//  Ch.3  -  OFF
void ChannelF::ch3OFF() {
    preamble(); //  initiate communication with receiver

    //  payload
    highLong();
    lowShort();
    highShort();
    lowLong();

    //  fluff
    for (int i=0; i<8; i++) {
        highShort();
        lowLong();
    }

    //  pause
    delayMicroseconds(11800);
}


