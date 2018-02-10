#pragma once

#include "Planet.h"
#include <functional>

class System {
  private:
	sf::RenderWindow window;
	std::vector<Planet> lst;

  private:
	void loopOverMat(int, int, std::function<void(Planet &)>);
	void parallelize(std::function<void(Planet &)>);

  public:
	System();

	void addPlanet(std::string name, int r, double m, Dot pos, Dot dpos) {
		lst.push_back(Planet(name, r, m, pos, dpos));
	};

	void start();
};