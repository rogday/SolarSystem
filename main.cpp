#include "System.h"

#include <iostream>
#include <random>

using namespace std;

int main(int argc, char const *argv[]) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<long long> dis(1e7, 1e10);

	cout << "Heoll, wrold!" << endl;

	System sys;

	int N = 42;

	if (argc == 2)
		N = atoi(argv[1]);

	for (int i = 0; i < N; ++i) {
		double m = dis(gen);
		cout << m << endl;
		sys.addPlanet("Sun", rand() % 30 + 1, m,
					  {(double)(rand() % 1024), (double)(rand() % 1024)},
					  {(double)(rand() % 15 - 7), (double)(rand() % 15 - 7)});
	}

	sys.start();
}