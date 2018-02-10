#include "System.h"

#include <iostream>

int main(int argc, char const *argv[]) {
	srand(time(nullptr));
	std::cout << "Heoll, wrold!" << std::endl;
	System sys;

	for (int i = 20; i < 512; i += 10)
		for (int k = 20; k < 512; k += 10)
			sys.addPlanet("Solar", 2, 2e8, {i, k},
						  {rand() % 4 - 2, rand() % 4 - 2});

	sys.start();
}