#pragma once

#include "Planet.h"
#include <functional>

class System {
  private:
	sf::RenderWindow window;
	std::vector<Planet> lst;

  private:
	static void loopOverMat(std::vector<Planet> &lst, int beg, int end,
							std::function<void(Planet &)> func);
	void parallelize(std::function<void(Planet &)> func);

  public:
	System();

	void addPlanet(std::string name, int r, double m, Dot pos, Dot dpos);

	void start();
};