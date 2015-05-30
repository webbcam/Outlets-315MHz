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

#ifndef ChannelF_h
#define ChannelF_h
#include "Arduino.h"
#include "Outlet.h"

class ChannelF : public Outlet {
    public:
        ChannelF(int pin);
        void toggle(int channel, bool state);
        
    private:
        void ch1ON();
        void ch1OFF();

        void ch2ON();
        void ch2OFF();
        
        void ch3ON();
        void ch3OFF();

};

#endif
