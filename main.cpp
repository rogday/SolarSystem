#include "System.h"

#include <iostream>

int main(int argc, char const *argv[]) {
	srand(time(nullptr));

	std::cout << "Heoll, wrold!" << std::endl;

	System sys;

	const int N = 20;

	for (int i = 0; i < N; ++i) {
		long double m = 1e9 + rand() % 10000 - 5000;
		sys.addPlanet(
			"Sun", 8 * m / (1e9 + 5000), m,
			{(long double)(rand() % 512), (long double)(rand() % 512)},
			{(long double)(rand() % 5 - 2), (long double)(rand() % 5 - 2)});
	}

	sys.start();
}