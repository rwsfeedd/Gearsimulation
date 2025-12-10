#include "Gear.hpp"
#include <map>
#include <string>

//module m = p / PI
//footheight hf = m + c
//headheight ha = m
//footdiametre df = d - 2 * hf
//headdiametre da = d + 2 * m = m * (z + 2)
//partition p = m * PI
//tooththickness sp = p / 2
//toothheight h = 2 * m + c

//Constructor
Gear::Gear(int teeth, float diametre) : teeth(teeth), diametre(diametre) {
	clearance = 0.f;
}

int Gear::getTeeth() const{
	return teeth;
}

float Gear::getDiametre() const{
	return diametre;
}

float Gear::getClearance() const{
	return clearance;
}

sf::ConvexShape Gear::getShape() const{
	sf::ConvexShape retShape;

	//numbPoints directs how many Points of the Gear will be drawn
	//Case 0: no teeth -> numbPoints = 0 -> only the headcircle is drawn
	//Case 1: spike teeth with 1 Point per tooth -> numbPoints = numbTeeth + pointsBetweenTeeth = 2 * numbTeeth
	//Case 2: better teeth with 2 Points per tooth -> numbPoints = 2 * numbTeeth + pointsBetweenTeeth = 3 * numbTeeth
	int numbPoints = 3 * teeth;

	retShape.setPointCount(numbPoints);

	float PI = acos(-1.0);

	float m = diametre / teeth;
	float hf = m + clearance;
	float ha = m;
	float da = diametre + 2 * m;
	float df = diametre - 2 * hf;
	//float p = m * PI;
	//float sp = p / 2;
	//float h = 2 * m;

	float rad = 0.f;

	for(int i = 0; i < numbPoints; i++) {
		if(numbPoints == 2*teeth) {
			rad = 2*PI/16;	

			if(i % 2 == 1){
				retShape.setPoint(i, {(da / 2) * cos((i * rad)), (da / 2) * sin(i * rad)});
				continue;
			}
			retShape.setPoint(i, {((df / 2) * cos((i * rad))), ((df / 2) * sin(i * rad))});
			continue;
		}

		if(numbPoints == 3 * teeth) {
			rad = 2*PI/8;	

			switch(i % 3){
				case 1: //first Point of teeth
					retShape.setPoint(i, {((da / 2) * cos((((i-1)/3) * rad)+(rad/3))), ((da / 2) * sin((((i-1)/3) * rad)+(rad/3)))});
					break;
				case 2: //second Point of teeth
					retShape.setPoint(i, {((da / 2) * cos((((i-2)/3) * rad)+2*(rad/3))), ((da / 2) * sin((((i-2)/3) * rad)+2*(rad/3)))});
					break;
				default: //case for 0 and 3. Is a Point between teeth
					retShape.setPoint(i, {((df / 2) * cos(((i/3) * rad))), ((df / 2) * sin((i/3) * rad))});
			}
		}
	}

	//retShape.setOrigin({diametre/2, diametre/2});

	return retShape;
}

string Gear::getString() const{
	string ret;
	ret = "Teeth: " + to_string(teeth) + ", Diametre: " + to_string(diametre);
	return ret;
}	
