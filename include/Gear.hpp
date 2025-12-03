#ifndef GEAR_H
#define GEAR_H

class Gear {
	private:
		int teeth;
		double radius;
		double angle;
	public:
		Gear(int t, double r);

		int getTeeth() const;
};
#endif
