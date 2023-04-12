#include "clock.h"

#include <iostream>

my_clock::my_clock(sc_module_name name, double time, sc_time_unit unit) 
  : time(time), unit(unit)
{
    SC_THREAD(step);
}

void my_clock::step() {

  step_out.write(false);

  while (true) {
    wait(time, unit);
    step_out.write(!step_out.read());
  }
}