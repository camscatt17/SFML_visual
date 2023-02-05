//Movimento de objeto através de input

#include "SFML/Graphics.hpp"

int main() {

	sf::RenderWindow window(sf::VideoMode(320, 480), "car moving by input");
	window.setFramerateLimit(60);
	
	sf::Event event;

	sf::Texture texture;
	texture.loadFromFile("courseSFML/resources/car.png");

	//Usa-se a figura inteira, não mais especificando sua área interna
	sf::Sprite sprite(texture);
	sprite.setPosition(60, 300); //Estabelecemos onde a figura(sprite) será posicionado na window criada através do método RenderWindow

	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::EventType::Closed)//Enquanto não fecharmos uma janela, mantemos ela ativa
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			sprite.move(0, -1.0);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			sprite.move(0, 1.0);
		}

		window.clear(sf::Color::White);
		window.draw(sprite);
		window.display();
	}
}