#include "System.h"

#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	srand(time(nullptr));

	cout << "Heoll, wrold!" << endl;

	System sys;

	int N = 42;

	if (argc == 2)
		N = atoi(argv[1]);

	for (int i = 0; i < N; ++i) {
		sys.addPlanet("Sun", 8, 1e6 + rand() % 10000 - 5000,
					  {(double)(rand() % 1024), (double)(rand() % 1024)},
					  {(double)(rand() % 15 - 7), (double)(rand() % 15 - 7)});
	}

	sys.addPlanet("Sun", 16, 1e10, {512, 512}, {15, 0});

	sys.start();
}