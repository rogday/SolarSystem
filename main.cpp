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

	// sys.addPlanet("Sun", 20, 1e7, {512, 512}, {0, 0});

	for (int i = 0; i < N; ++i) {
		sys.addPlanet("Sun", rand() % 30 + 1, rand(),
					  {(double)(rand() % 1024), (double)(rand() % 1024)},
					  {(double)(rand() % 15 - 7), (double)(rand() % 15 - 7)});
	}

	sys.start();
}