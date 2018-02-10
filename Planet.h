#pragma once

#include "Settings.h"
#include <SFML/Graphics.hpp>
#include <string>

class Planet {
  private:
	std::string name;
	sf::CircleShape circle;
	double m;
	Dot pos;
	Dot dpos;
	Dot tdpos;

  public:
	Planet(std::string name, int r, double m, Dot pos, Dot dpos)
		: name(name), circle(r, 30), m(m), pos(pos), dpos(dpos), tdpos(pos) {
		circle.setPosition(pos.x, pos.y);
	}

	int getX() const { return pos.x; }
	int getY() const { return pos.y; }

	void correctX(int x) {
		circle.move(x, 0);
		pos.x += x;
	}
	void correctY(int y) {
		circle.move(0, y);
		pos.y += y;
	}

	void draw(sf::RenderWindow &window) const { window.draw(circle); }
	void calc(std::vector<Planet> &lst);
	void apply();
};