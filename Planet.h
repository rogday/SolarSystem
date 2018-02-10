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

	void draw(sf::RenderWindow &window) { window.draw(circle); }

	void calc(std::vector<Planet> &lst);
	void apply();
};