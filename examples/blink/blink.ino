/*********************************************************************
This is an example sketch that controls "Woods Wireless
Remote Control Outlets" with a 315MHz RF Transmitter and Arduino

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
                         Simple Blink Sketch
  This sketch will just cycle through each minor channel of the 
  set of outlets turning each one on and then each one off
*********************************************************************/


#include "Outlets.h"  //  include all channels

ChannelF outlet(5); //  make a new outlet instance with
                    //  major channel F
void setup() {
  //  nothing to set up

}

void loop() {
  //  turn each minor channel of outlet set on
  outlet.toggle(1, true); //  turn ch1 on
  delay(1000);
  outlet.toggle(2, true); //  turn ch2 on
  delay(1000);
  outlet.toggle(3, true); //  turn ch3 on
  delay(500);
  outlet.toggle(1, false);  //  turn ch1 off
  delay(500);
  outlet.toggle(2, false);  //  turn ch2 off
  delay(500);
  outlet.toggle(3, false);  //  turn ch3 off
  delay(1000);

}
