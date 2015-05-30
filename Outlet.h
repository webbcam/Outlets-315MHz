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

#ifndef Outlet_h
#define Outlet_h
#include "Arduino.h"

class Outlet {
    public:
        Outlet(int pin);
        
        // every channel needs to implement its own specific toggle function
        virtual void toggle(int channel, bool state) = 0;   
        
    protected:
        int DATA_PIN;
        void preamble();
        void highShort();
        void highLong();
        void lowShort();
        void lowLong();

};

#endif

