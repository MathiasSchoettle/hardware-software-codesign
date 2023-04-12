#pragma once

#include <systemc>

using namespace sc_core;

struct my_clock : public sc_module {
  
  double time;
  sc_time_unit unit;
  sc_out<bool> step_out;

  void step();

  SC_HAS_PROCESS(my_clock);
  my_clock(sc_module_name, double, sc_time_unit);
};