#include "System.h"
#include <thread>

System::System() {
	sf::VideoMode vm = sf::VideoMode::getDesktopMode();

	int size = std::min(vm.width, vm.height);

	window.create(sf::VideoMode(size, size), "Solar System",
				  sf::Style::Titlebar | sf::Style::Close);

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