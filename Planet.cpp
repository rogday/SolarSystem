#include "Planet.h"

#include <cmath>

sf::Texture Planet::texture;

void Planet::calc(std::vector<Planet> &lst) {
	long double R, a, dx = 0, dy = 0;

	for (auto &plnt : lst) {
		if (this == &plnt)
			continue;

		R = std::hypot(pos.x - plnt.pos.x, pos.y - plnt.pos.y);

		if (R < Settings::Eps)
			continue;

		a = Settings::G * plnt.m / R * R * Settings::Speed;

		dx += a * (plnt.pos.x - pos.x) / R;
		dy += a * (plnt.pos.y - pos.y) / R;
	}

	tdpos.x = dpos.x + dx;
	tdpos.y = dpos.y + dy;
}
void Planet::apply() {
	dpos = tdpos;
	pos += dpos;
	sprite.move(dpos.x, dpos.y);
}