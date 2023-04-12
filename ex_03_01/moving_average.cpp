#include "moving_average.h"

moving_average::moving_average(sc_module_name name) {
	SC_THREAD(compute);
	sensitive << clock << reset;
}

void moving_average::compute() {
	while (true) {

		int res = xn.read() + xn1.read() + xn2.read() + xn3.read();
		result.write(res >> 2);

		if (reset.read()) {
			xn1.write(0);
			xn2.write(0);
			xn3.write(0);
			yn.write(0);
		}
		else if (clock.posedge()) {
			xn1.write(xn.read());
			xn2.write(xn1.read());
			xn3.write(xn2.read());
			yn.write(result.read());
		}

		wait();
	}
}