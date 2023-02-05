//Movimento de objeto atrav�s de input

#include "SFML/Graphics.hpp"

int main() {

	sf::RenderWindow window(sf::VideoMode(320, 480), "car moving by input");
	window.setFramerateLimit(60);
	
	sf::Event event;

	sf::Texture texture;
	texture.loadFromFile("courseSFML/resources/car.png");

	//Usa-se a figura inteira, n�o mais especificando sua �rea interna
	sf::Sprite sprite(texture);
	sprite.setPosition(60, 300); //Estabelecemos onde a figura(sprite) ser� posicionado na window criada atrav�s do m�todo RenderWindow

	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::EventType::Closed)//Enquanto n�o fecharmos uma janela, mantemos ela ativa
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