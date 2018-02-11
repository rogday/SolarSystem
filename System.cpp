#include "System.h"
#include <iostream>
#include <thread>

System::System() {
	if (!bg.loadFromFile("textures/bg.png"))
		throw("fukk");

	bg.setRepeated(true);

	sf::VideoMode vm = sf::VideoMode::getDesktopMode();

	int size = std::min(vm.width, vm.height);

	sf::ContextSettings set;
	set.antialiasingLevel = 8;

	window.create(sf::VideoMode(size, size), "Solar System",
				  sf::Style::Titlebar | sf::Style::Close, set);

	window.setPosition(
		sf::Vector2i((vm.width - size) / 2, (vm.height - size) / 2));

	window.setFramerateLimit(75);
}

void System::loopOverMat(int beg, int end, std::function<void(Planet &)> func) {

	for (int k = beg; k != end; ++k)
		func(lst[k]);
}

void System::parallelize(std::function<void(Planet &)> func) {
	static std::vector<std::thread> thrds(Settings::Threads);

	int cnt = 0, k = 0;
	int len = std::min(Settings::Threads, (int)lst.size());
	int shift = std::max(1, (int)lst.size() / Settings::Threads);

	for (; cnt < len - 1; k += shift)
		thrds[cnt++] =
			std::thread(&System::loopOverMat, this, k, k + shift, func);

	thrds[cnt++] = std::thread(&System::loopOverMat, this, k, lst.size(), func);

	while (cnt)
		thrds[--cnt].join();
}

void System::start() {
	std::cout << lst.size() << std::endl;

	sf::Event event;
	sf::Sprite sprite(bg);

	int bx = bg.getSize().x / 2;
	int by = bg.getSize().y / 2;

	long long x = 0, xp = x, y = 0, yp = y;

	while (window.isOpen()) {
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed)
				window.close();

		window.draw(sprite);

		parallelize([this](Planet &plnt) { plnt.calc(this->lst); });
		parallelize([](Planet &plnt) { plnt.apply(); });

		x = y = 0;

		for (auto &plnt : lst) {
			x += plnt.getX();
			y += plnt.getY();
		}
		x = window.getSize().x / 2 - x / lst.size();
		y = window.getSize().y / 2 - y / lst.size();

		sprite.setOrigin(((int)sprite.getOrigin().x + xp - x + bx) % bx,
						 ((int)sprite.getOrigin().y + yp - y + by) % by);

		for (auto &plnt : lst) {
			plnt.correctX(x);
			plnt.correctY(y);
			plnt.draw(window);
		}

		window.display();
	}
}