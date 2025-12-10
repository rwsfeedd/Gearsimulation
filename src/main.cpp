#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "Gear.hpp"

using namespace std;

int main() {
	cout << "Zahnradsimulation starten!" << endl;
	Gear gearTest(8, 100.f);
	//sf::ConvexShape gearShape = gearTest.getShape();
	//gearTest.setPosition({400, 400});
	cout << gearTest.getString() << endl;

	sf::RenderWindow window(sf::VideoMode({500,500}), "SFML works!");

	float PI = 3.1416;

	//z muss mindestens 2 sein

	int z = 8; //Zähnezahl
	float d = 300.f; //Teilkreisdurchmesser = m * z
	float midX = 200.f;
	float midY = 200.f;	

	float m; //Modul = p / PI
	float c;//Kopfspiel
	float hf;//Fußhöhe hf = m + c
	float ha;//Kopfhöhe ha = m
	float df; //Fußkreis = d - 2 * hf
	float da; //Kopfkreisdurchmesser = d + 2m = m * (z + 2)
	float p;//Teilung p = m * PI
	float sp; //Zahndicke = p/2
	float h;//Zahnhöhe h = 2 * m + c

	m = d / z;
	c = 0.f;
	hf = m + c;
	ha = m;
	df = d - 2 * hf;
	da = d + 2 * m;
	p = m * PI;
	sp = p / 2;
	h = 2 * m;

	//Teilkreis definieren
	sf::CircleShape partCircle(d / 2);
	partCircle.setFillColor(sf::Color::Transparent);
	partCircle.setOutlineThickness(1.f);
	partCircle.setOrigin({d / 2, d / 2});
	partCircle.setPosition({midX, midY});
	//Fußkreis definieren	 / 2
	sf::CircleShape footCircle(df / 2);
	footCircle.setFillColor(sf::Color::Transparent);
	footCircle.setOutlineThickness(1.f);
	footCircle.setOrigin({df / 2, df / 2});
	footCircle.setPosition({midX, midY});
	//Kopfkreis definieren
	sf::CircleShape headCircle(da / 2);
	headCircle.setFillColor(sf::Color::Transparent);
	headCircle.setOutlineThickness(1.f);
	headCircle.setOrigin({da / 2, da / 2});
	headCircle.setPosition({midX, midY});
	//Zahnsegmente aufteilen für z = 8
	sf::RectangleShape lines[8];
	for(int i = 0; i < z; i++) {
		lines[i].setSize({da, 1});	
		lines[i].setOrigin({da/2, 1});
		lines[i].rotate(sf::degrees((360/8)*(i+1)));
		lines[i].setPosition({midX, midY});
	}

	while (window.isOpen()) {
		while (const std::optional event = window.pollEvent()){
			if (event->is<sf::Event::Closed>())
				window.close();
		}

		//wird noch sehr oft hintereinander ausgeführt. bei keiner Änderung nur einmal malen
		window.clear();
		window.draw(partCircle);
		window.draw(footCircle);
		window.draw(headCircle);
		window.draw(gearTest.getShape());
		for(int i = 0; i < 8; i++){
			window.draw(lines[i]);
		}
		window.display();
	}	
	
	return 0;
}
