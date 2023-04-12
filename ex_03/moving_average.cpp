#include "moving_average.h"

moving_average::moving_average(sc_module_name name) {
	SC_METHOD(registers);
	sensitive << clock << reset;
	SC_METHOD(combinators);
	sensitive << xn << xn1 << xn2 << xn3;
}

void moving_average::registers() {

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
}

void moving_average::combinators() {
	int res = xn.read() + xn1.read() + xn2.read() + xn3.read();
	result.write(res >> 2);
}