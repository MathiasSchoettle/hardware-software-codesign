#pragma once

#include "moving_average.h"
#include "testbench.h"

#include <systemc>

using namespace sc_core;

struct toplevel : public sc_module {
	testbench bench;
	moving_average average;

	toplevel(sc_module_name);

private:
	sc_clock clock;
	sc_signal<bool> reset_signal;
	sc_signal<int> x_signal, y_signal;
};
