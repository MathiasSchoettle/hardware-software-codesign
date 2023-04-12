#include "toplevel.h"

int sc_main(int argc, char* argv[]) {
	toplevel top("top");

	sc_trace_file* file = sc_create_vcd_trace_file("traces");
	sc_trace(file, top.bench.clock, "clock");
	sc_trace(file, top.bench.reset, "reset");
	sc_trace(file, top.bench.xn, "xn");
	sc_trace(file, top.bench.yn, "yn");

	sc_start(100, SC_NS);

	sc_close_vcd_trace_file(file);

	return 0;
}