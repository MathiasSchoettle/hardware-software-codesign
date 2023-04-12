#pragma once

#include <systemc>

using namespace sc_core;

struct moving_average : public sc_module {
	sc_in<bool> clock, reset;
	sc_in<int> xn;
	sc_out<int> yn;

	void compute();

	SC_HAS_PROCESS(moving_average);
	moving_average(sc_module_name);

private:
	sc_signal<int> xn1, xn2, xn3, result;
};