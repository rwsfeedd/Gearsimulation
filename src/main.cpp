#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "Gear.hpp"

using namespace std;

int main() {
	cout << "Starting Gearsimulation!" << endl;

	Gear gearTest(8, 100.f);
	cout << gearTest.getString() << endl;
	sf::ConvexShape gearShape = gearTest.getShape();
	gearShape.setPosition({300.f, 300.f});


	sf::RenderWindow window(sf::VideoMode({500,500}), "Gearsimulation");

	while (window.isOpen()) {
		while (const std::optional event = window.pollEvent()){
			if (event->is<sf::Event::Closed>())
				window.close();
		}

		//wird noch sehr oft hintereinander ausgeführt. bei keiner Änderung nur einmal malen
		window.clear();
		window.draw(gearShape);
		window.display();
	}	
	
	return 0;
}
