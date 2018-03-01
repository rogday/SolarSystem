#include "System.h"

#include <iostream>
#include <random>

using namespace std;

int main(int argc, char const *argv[]) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<long long> radius(1, 20), mass(1e7, 1e10),
		position(0, 1024), speed(-25, 26);

	cout << "Heoll, wrold!" << endl;

	System sys;

	int N = 42;

	if (argc == 2)
		N = atoi(argv[1]);

	for (int i = 0; i < N; ++i) {
		sys.addPlanet("Sun", radius(gen), mass(gen),
					  {(double)position(gen), (double)position(gen)},
					  {(double)speed(gen), (double)speed(gen)});
	}

	sys.start();
}