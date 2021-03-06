#pragma once

#define NDEBUG

struct Dot {
	double x;
	double y;
	Dot &operator+=(Dot &another) {
		x += another.x;
		y += another.y;
		return *this;
	}
};

#ifndef NDEBUG

#include <iostream>
#define LOG(x) std::cout << x << std::endl

#else

#define LOG(x)

#endif

namespace Settings {
const double G = 6.67408e-11;
// const long double Scale = 1;
const double Speed = 1;

extern int Threads;

const double Eps = 1e-18;
} // namespace Settings