#pragma once

#include "Settings.h"
#include <SFML/Graphics.hpp>
#include <string>

class Planet {
  private:
	std::string name;
	sf::CircleShape circle;
	sf::Sprite sprite;
	static sf::Texture texture;
	double m;
	Dot pos;
	Dot dpos;
	Dot tdpos;

  public:
	Planet(std::string name, int r, double m, Dot pos, Dot dpos)
		: name(name), circle(r, 30), sprite(), m(m), pos(pos), dpos(dpos),
		  tdpos(pos) {
		texture.loadFromFile("textures/sun.png");

		sprite.setTexture(texture);
		sprite.setScale(r / 120.0, r / 120.0);
		sprite.setPosition(pos.x, pos.y);

		float factor = (float)m / r / (1 << 31); // how red

		sprite.setColor(sf::Color(255 * factor, 255, 255));

		circle.setPosition(pos.x, pos.y);
	}

	int getX() const { return pos.x; }
	int getY() const { return pos.y; }

	void correctX(int x) {
		circle.move(x, 0);
		sprite.move(x, 0);
		pos.x += x;
	}
	void correctY(int y) {
		circle.move(0, y);
		sprite.move(0, y);
		pos.y += y;
	}

	void draw(sf::RenderWindow &window) const { window.draw(sprite); }
	void calc(std::vector<Planet> &lst);
	void apply();
};