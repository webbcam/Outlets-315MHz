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

#ifndef ChannelF_h
#define ChannelF_h
#include "Arduino.h"

#include "Outlet.h"
class ChannelF : public Outlet {
    public:
        ChannelF(int pin);
        void toggle(int channel, bool state);
        void ch1(bool state);
        void ch2(bool state);
        void ch3(bool state);
    private:
        void ch1ON();
        void ch1OFF();

        void ch2ON();
        void ch2OFF();
        
        void ch3ON();
        void ch3OFF();

};

#endif
