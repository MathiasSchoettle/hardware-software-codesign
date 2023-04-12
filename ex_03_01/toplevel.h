#pragma once

#include "moving_average.h"
#include "testbench.h"
#include "clock.h"

#include <systemc>

using namespace sc_core;

struct toplevel : public sc_module {
	testbench bench;
	moving_average average;
	my_clock clock;

	toplevel(sc_module_name);

private:
	sc_signal<bool> reset_signal, clock_signal;
	sc_signal<int> x_signal, y_signal;
};
