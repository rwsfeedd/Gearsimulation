#include "Gear.hpp"

	

//Konstruktor
Gear::Gear(int t, double r) : teeth(t), radius(r), angle(0.0) {}

int Gear::getTeeth() const{
	return teeth;
}
