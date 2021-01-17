#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main();
void drawBg(sf::RenderWindow& window);

int main() {
	int x = 0;
	float angle(0.f);

	sf::RenderWindow window(sf::VideoMode(800, 800), "Simulation");
	
	sf::Event event;

	window.setFramerateLimit(100);

	sf::Transform transform;

	while (window.isOpen()) {
		drawBg(window);
		

			//Draw background


			sf::RectangleShape car(sf::Vector2f(30, 60));
			car.setFillColor(sf::Color(60, 245, 255));
			car.setPosition(425, 740 - x);

			/*car.setOrigin(440, 770 - x);
			car.rotate(angle);*/

			transform.rotate(angle, sf::Vector2f(440, 770 - x));

			window.draw(car, transform);
			x++;
			angle += 0.001;


			window.display();
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
					window.close();
			}
		}
		
	}
	return 0;
}

void drawBg(sf::RenderWindow& window) {
	window.clear(sf::Color(50, 50, 50)); //Set street colour

	//Create sidewalks
	sf::RectangleShape topLeft(sf::Vector2f(320, 320));
	topLeft.setFillColor(sf::Color(220, 220, 220));
	topLeft.setPosition(0, 0);

	sf::RectangleShape topRight(sf::Vector2f(320, 320));
	topRight.setFillColor(sf::Color(220, 220, 220));
	topRight.setPosition(480, 0);

	sf::RectangleShape botLeft(sf::Vector2f(320, 320));
	botLeft.setFillColor(sf::Color(220, 220, 220));
	botLeft.setPosition(0, 480);

	sf::RectangleShape botRight(sf::Vector2f(320, 320));
	botRight.setFillColor(sf::Color(220, 220, 220));
	botRight.setPosition(480, 480);


	//Create grass
	sf::RectangleShape topLeftGrass(sf::Vector2f(270, 270));
	topLeftGrass.setFillColor(sf::Color(24, 125, 40));
	topLeftGrass.setPosition(0, 0);

	sf::RectangleShape topRightGrass(sf::Vector2f(270, 270));
	topRightGrass.setFillColor(sf::Color(24, 125, 40));
	topRightGrass.setPosition(530, 0);

	sf::RectangleShape botLeftGrass(sf::Vector2f(270, 270));
	botLeftGrass.setFillColor(sf::Color(24, 125, 40));
	botLeftGrass.setPosition(0, 530);

	sf::RectangleShape botRightGrass(sf::Vector2f(270, 270));
	botRightGrass.setFillColor(sf::Color(24, 125, 40));
	botRightGrass.setPosition(530, 530);


	//Create street lines
	sf::RectangleShape hLines(sf::Vector2f(140, 10));
	hLines.setFillColor(sf::Color::Yellow);

	sf::RectangleShape vLines(sf::Vector2f(10, 140));
	vLines.setFillColor(sf::Color::Yellow);


	//Draw on screen
	window.draw(topLeft);
	window.draw(topRight);
	window.draw(botLeft);
	window.draw(botRight);
	window.draw(topLeftGrass);
	window.draw(topRightGrass);
	window.draw(botLeftGrass);
	window.draw(botRightGrass);

	hLines.setPosition(0, 395);
	window.draw(hLines);
	hLines.setPosition(180, 395);
	window.draw(hLines);
	hLines.setPosition(480, 395);
	window.draw(hLines);
	hLines.setPosition(660, 395);
	window.draw(hLines);

	vLines.setPosition(395, 0);
	window.draw(vLines);
	vLines.setPosition(395, 180);
	window.draw(vLines);
	vLines.setPosition(395, 480);
	window.draw(vLines);
	vLines.setPosition(395, 660);
	window.draw(vLines);
}