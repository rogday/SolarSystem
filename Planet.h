#pragma once

#include "Settings.h"
#include <SFML/Graphics.hpp>
#include <string>

class Planet {
  private:
	std::string name;
	sf::Sprite sprite;
	static sf::Texture texture;
	double m;
	Dot pos;
	Dot dpos;
	Dot tdpos;

  public:
	Planet(std::string name, int r, double m, Dot pos, Dot dpos)
		: name(name), sprite(), m(m), pos(pos), dpos(dpos), tdpos(pos) {
		texture.loadFromFile("textures/sun.png");

		sprite.setTexture(texture);
		sprite.setScale(r / 60.0, r / 60.0);
		sprite.setPosition(pos.x, pos.y);

		sprite.setColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
	}

	int getX() const { return pos.x; }
	int getY() const { return pos.y; }

	void correctX(int x) {
		sprite.move(x, 0);
		pos.x += x;
	}
	void correctY(int y) {
		sprite.move(0, y);
		pos.y += y;
	}

	void draw(sf::RenderWindow &window) const { window.draw(sprite); }
	void calc(std::vector<Planet> &lst);
	void apply();
};