#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
//#include "include/Gear.hpp"

using namespace std;

int main() {
	cout << "Zahnradsimulation starten!" << endl;
	//Gear g1(2,4.3);
	//cout << g1.getTeeth() + 3.14*cos(180/3.14) << endl;

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
	h = 75.f;	

	cout << "Ausgabe Zahnradmaße: m=" << m 
		<< ",c=" << c 
	   	<< ",h=" << h 
	   	<< ",hf=" << hf 
	   	<< ",ha=" << ha 
	   	<< ",df=" << df
		<< ",da=" << da 
		<< ",p=" << p
		<< ",sp=" << sp << endl; 

	//Kreisumfang = 2 * PI * r
	//(Bogenmaß) 1 Radiant = 180Grad/PI
	//y = sin t
	//x = cos t

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

	sf::ConvexShape gear;

	gear.setPointCount(4);

	float rad = 0.f;

	gear.setPoint(0, {midX, midY});
	gear.setPoint(1, {midX + (df / 2), midY});
	rad = (sp/d);	
	gear.setPoint(2, {midX + ((d / 2) * cos(rad)), midY - ((d / 2) * sin(rad))});
	//rad = -((5/3)*sp)/(PI*da*da);
	rad = - 0.5 * PI;	
	gear.setPoint(3, {midX + ((da / 2) * cos(rad)), midY + ((da / 2) * sin(rad))});
	//gear.setPoint(2, {midX + (d / 2 * cos((sp * PI)/(PI * d))), midY + (d / 2 * sin((sp * PI)/(PI * d)))});
	//gear.setPoint(1, {midX + cos(), };	
	//

	/* Code für einen Kreis mit 4 Punkten
	for(int i = 0; i < 4; i++) {
		float x = midX + (df / 2 * cos((i+1)*0.5*PI));
		float y = midY + (df / 2 * sin((i+1)*0.5*PI));
		cout << "Punkt " + to_string(i) + ":x=" + to_string(x) + "|y=" + to_string(y) << endl;
		gear.setPoint(i, {x, y});
	}
	*/
	
	//gear.setFillColor(sf::Color::Green);

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
		window.draw(gear);
		for(int i = 0; i < 8; i++){
			window.draw(lines[i]);
		}
		window.display();
	}	
	
	return 0;
}
