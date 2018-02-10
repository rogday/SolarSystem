#pragma once

#include "Planet.h"
#include <functional>

class System {
  private:
	sf::RenderWindow window;
	std::vector<Planet> lst;

  private:
	static void loopOverMat(std::vector<Planet> &, int, int,
							std::function<void(Planet &)>);
	void parallelize(std::function<void(Planet &)>);

  public:
	System();
	void addPlanet(std::string, long double, long double, Dot, Dot);
	void start();
};