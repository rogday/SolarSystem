#include "Planet.h"

#include <cmath>

void Planet::calc(std::vector<Planet> &lst) {
	double R, F, a, dx = 0, dy = 0;

	for (auto &plnt : lst) {
		if (this == &plnt)
			continue;

		R = std::hypot(pos.x - plnt.pos.x, pos.y - plnt.pos.y);

		if (R < 1e-11)
			continue;

		F = Settings::G * m * plnt.m / R * R;
		a = F / m;
		dx += a * (plnt.pos.x - pos.x) / R;
		dy += a * (plnt.pos.y - pos.y) / R;
	}

	tdpos.x = dpos.x + dx;
	tdpos.y = dpos.y + dy;
}
void Planet::apply() {
	dpos = tdpos;
	pos += dpos;
	circle.move(dpos.x, dpos.y);
}