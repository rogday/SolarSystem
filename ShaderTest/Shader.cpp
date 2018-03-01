#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

int main() {
	sf::ContextSettings settings;
	// settings.antialiasingLevel = 16;

	// Create the main window
	RenderWindow window(VideoMode(800, 800), "SFML Shader",
						Style::Titlebar | Style::Close);
	// window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(75);

	Texture m_texture, tsun;
	Sprite m_sprite, ssun;
	Shader m_shader;
	Shader sun_shader;

	if (!m_texture.loadFromFile("test.png") || !tsun.loadFromFile("sun.png") ||
		!m_shader.loadFromFile("shader.frag", Shader::Fragment) ||
		!sun_shader.loadFromFile("sun.frag", Shader::Fragment))
		throw("trash");

	m_texture.setRepeated(true);
	m_sprite.setTexture(m_texture);

	ssun.setTexture(tsun);
	ssun.scale(0.7, 0.7);
	ssun.setColor(Color(255, 255, 0));
	ssun.setOrigin(tsun.getSize().x / 2, tsun.getSize().y / 2);

	IntRect rect;
	rect.width = window.getSize().x;
	rect.height = window.getSize().y;

	m_sprite.setTextureRect(rect);
	m_shader.setUniform("texture", Shader::CurrentTexture);
	sun_shader.setUniform("texture", Shader::CurrentTexture);

	Clock clock;
	while (window.isOpen()) {
		// Process events
		Event event;

		while (window.pollEvent(event))
			if (event.type == Event::Closed)
				window.close();

		ssun.setPosition(Mouse::getPosition(window).x,
						 Mouse::getPosition(window).y);

		// Update the current example
		float x = (float)(Mouse::getPosition(window).x) / m_texture.getSize().x;
		float y = (float)(Mouse::getPosition(window).y) / m_texture.getSize().y;

		m_shader.setUniform("mouse", Glsl::Vec2(x, y));
		m_shader.setUniform("time", clock.getElapsedTime().asSeconds());

		// Clear the window
		window.clear(Color(255, 128, 0));
		window.draw(m_sprite, &m_shader);
		window.draw(ssun, &sun_shader);

		// Finally, display the rendered frame on screen
		window.display();
	}
}
