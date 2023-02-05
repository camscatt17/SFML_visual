#include "SFML/Graphics.hpp"

int main() {

	//Passo básico para renderizar uma janela
	sf::RenderWindow window(sf::VideoMode(256, 256), "first image");
	sf::Event event;

	sf::Texture texture;
	texture.loadFromFile("courseSFML/resources/red.png");

	sf::Sprite sprite(texture, sf::IntRect(0, 0, 32, 32));


	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::EventType::Closed)//Enquanto não fecharmos uma janela, mantemos ela ativa
				window.close();
		}

		window.clear();
		window.draw(sprite);
		window.display();
	}
}