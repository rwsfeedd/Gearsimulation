#ifndef GEAR_H
#define GEAR_H

#include <map>
#include <string>
#include <SFML/Graphics.hpp>
#include <cmath>

using namespace std;

class Gear {
	private:
		int teeth;
		float diametre;
		float clearance;

		map<int, map<float, float>> vertices;

	public:
		Gear(int teeth, float diametre);

		int getTeeth() const;
		float getDiametre() const;
		float getClearance() const;
		sf::ConvexShape getShape();
		string getString() const;
		
};
#endif
