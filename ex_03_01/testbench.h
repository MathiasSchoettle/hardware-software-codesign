#pragma once

#include <systemc>

using namespace sc_core;

struct testbench : public sc_module {
	sc_in<bool> clock;
	sc_in<int> yn;
	sc_out<int> xn;
	sc_out<bool> reset;

	void generate();

	SC_HAS_PROCESS(testbench);
	testbench(sc_module_name);
};