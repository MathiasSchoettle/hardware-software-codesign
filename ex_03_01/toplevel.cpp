#include "toplevel.h"

toplevel::toplevel(sc_module_name name) : 
	bench("bench"), 
	average("average"),
	clock("clock", 10, SC_NS) {
		
	clock.step_out(clock_signal);

	bench.clock(clock_signal);
	bench.xn(x_signal);
	bench.yn(y_signal);
	bench.reset(reset_signal);

	average.clock(clock_signal);
	average.xn(x_signal);
	average.yn(y_signal);
	average.reset(reset_signal);
}