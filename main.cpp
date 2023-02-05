//megaman spritesheet with 85/70 pixels

#include "SFML/Graphics.hpp"

int main() {

	//Passo básico para renderizar uma janela
	sf::RenderWindow window(sf::VideoMode(640, 480), "megaman runnig");
	sf::Event event;

	sf::Texture texture;
	texture.loadFromFile("courseSFML/resources/mega.png");

	//Cria-se um objeto do tipo Rect que representará o tamanho do sprite
	sf::IntRect rect(0, 0, 85, 70);

	sf::Sprite sprite(texture, rect);

	sf::Clock clock;


	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::EventType::Closed)//Enquanto não fecharmos uma janela, mantemos ela ativa
				window.close();
		}

		if (clock.getElapsedTime().asSeconds() > 0.4f) {
			if (rect.left == 255)
				rect.left = 0;
			else
				rect.left += 85;

			//É necessário atualizar o spite a cada passagem do loop
			sprite.setTextureRect(rect);
			clock.restart();
		}

		window.clear();
		window.draw(sprite);
		window.display();
	}
}