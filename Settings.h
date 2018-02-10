#pragma once

struct Dot {
	int x;
	int y;
	Dot &operator+=(Dot &another) {
		x += another.x;
		y += another.y;
		return *this;
	}
};

namespace Settings {
const double G = 6.67408e-11;
const int Threads = 12;
} // namespace Settings