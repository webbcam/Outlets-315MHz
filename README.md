#Outlets

This is an Arduino library for controlling "Woods Indoor Wireless Remote Control Outlets"

HARDWARE:

    HARDWARE REQUIREMENTS:
        Woods Wireless Outlets:    https://amzn.com/B003ZTWYXY
        315MHz Transmitter:     http://amzn.com/B00LNADJS6
        9V or 12V DC Power Supply
        Arduino (or similar MCU)

    CONNECTIONS:
        Arduino: PIN 4  ->  315MHz-Module: DATA PIN
        12V powersupply + -> 315MHz-Module: VCC
        12V powersupply - -> 315MHz-Module: GND & Arduino: GND

    SETUP:
        12V Powersupply to power the 315MHz-Module
        * Make sure to use common ground with Arduino

        Connect an Arduino pin (here we use pin 4) to DATA PIN of Transmitter


SOFTWARE:
    
    SETUP:
        Create a new sketch
        To include the library you have two options
            - You can include every channel:
                #include "Outlets.h"

                        OR

            - Or you can include a specific channel you need:
                #include "ChannelF.h"

        Before void setup() you want to intialize all your outlets you
        will be controlling by calling the particular channel of the
        outlet (A-H) and passing it the Arduino pin connected to DATA:

            ChannelF outlet_name(pin_Number);

    USE:
        You can toggle the outlet's state by calling its toggle function
        and passing it the channel (1-3) and power state 
        (true->on or false->off)

            i.e.
            outlet_name.toggle(1, true);


Please see the examples for more information!

*NOTE: Currently the only channel I have is Channel-F. My goal is to get 
each Channel on here (A-H?) over time. Please feel free to add any 
channels you've figured out yourself


