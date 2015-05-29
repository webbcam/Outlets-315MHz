#include "Outlets.h"

ChannelF outlet(5);
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  outlet.toggle(1, true);
  delay(1000);
  outlet.toggle(2, true);
  delay(1000);
  outlet.toggle(3, true);
  delay(500);
  outlet.toggle(1, false);
  delay(500);
  outlet.toggle(2, false);
  delay(500);
  outlet.toggle(3, false);
  delay(1000);

}
