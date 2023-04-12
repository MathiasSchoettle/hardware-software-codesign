#include "testbench.h"

#include <iostream>

testbench::testbench(sc_module_name name) {
	SC_THREAD(generate);
	sensitive << clock.neg();
}

void testbench::generate() {
	reset.write(true);
	xn.write(0);
	wait();

	reset.write(false);
	xn.write(50);

	for (int i = 0; i < 4; ++i) {
		std::cout << "xn: " << 50 << ", yn: " << yn.read() << std::endl;
		wait();
	}

	xn.write(10);
	std::cout << "xn: " << 10 << ", yn: " << yn.read() << std::endl;
	wait();

	xn.write(50);
	for (int i = 0; i < 5; ++i) {
		std::cout << "xn: " << 50 << ", yn: " << yn.read() << std::endl;
		wait();
	}
}