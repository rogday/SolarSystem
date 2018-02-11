#include "Planet.h"

#include <cmath>

void Planet::calc(std::vector<Planet> &lst) {
	long double R, a, dx = 0, dy = 0;

	for (auto &plnt : lst) {
		if (this == &plnt)
			continue;

		R = std::hypot(pos.x - plnt.pos.x, pos.y - plnt.pos.y);

		// if (R < 1e-11)
		//	continue;

		a = Settings::G * plnt.m / R * R;

		dx += a * (plnt.pos.x - pos.x) / R;
		dy += a * (plnt.pos.y - pos.y) / R;
	}

	LOG(dx);
	LOG(dy);

	tdpos.x = dpos.x + dx;
	tdpos.y = dpos.y + dy;
}
void Planet::apply() {
	dpos = tdpos;
	pos += dpos;
	circle.move(dpos.x, dpos.y);
}