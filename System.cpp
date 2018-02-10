#include "System.h"
#include <thread>

void System::loopOverMat(std::vector<Planet> &lst, int beg, int end,
						 std::function<void(Planet &)> func) {

	for (int k = beg; k != end; ++k)
		func(lst[k]);
}

void System::parallelize(std::function<void(Planet &)> func) {
	static std::vector<std::thread> thrds(Settings::Threads);

	int cnt = 0, k = 0;
	int len = std::min(Settings::Threads, (int)lst.size());
	int shift = std::max(1, (int)lst.size() / Settings::Threads);

	for (; cnt < len - 1; k += shift)
		thrds[cnt++] = std::thread(loopOverMat, ref(lst), k, k + shift, func);

	thrds[cnt++] = std::thread(loopOverMat, ref(lst), k, lst.size(), func);

	while (cnt)
		thrds[--cnt].join();
}

System::System() {
	sf::VideoMode vm = sf::VideoMode::getDesktopMode();

	int size = std::min(vm.width, vm.height);

	window.create(sf::VideoMode(size, size), "Solar System",
				  sf::Style::Titlebar | sf::Style::Close);

	window.setPosition(
		sf::Vector2i((vm.width - size) / 2, (vm.height - size) / 2));

	window.setFramerateLimit(75);
}

void System::addPlanet(std::string name, long double r, long double m, Dot pos,
					   Dot dpos) {
	lst.push_back(Planet(name, r, m, pos, dpos));
}

void System::start() {
	sf::Event event;

	while (window.isOpen()) {
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed)
				window.close();

		window.clear(sf::Color::Black);

		parallelize([this](Planet &plnt) { plnt.calc(this->lst); });
		parallelize([](Planet &plnt) { plnt.apply(); });

		int x = 0, y = 0;

		for (auto &plnt : lst) {
			x += plnt.getX();
			y += plnt.getY();
		}

		for (auto &plnt : lst) {
			plnt.correctX(window.getSize().x / 2 - x / lst.size());
			plnt.correctY(window.getSize().y / 2 - y / lst.size());
			plnt.draw(window);
		}

		window.display();
	}
}