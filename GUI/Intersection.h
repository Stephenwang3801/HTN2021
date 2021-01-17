#include <iostream>
#include <vector>
#include "Car.h"

using namespace std;

class Intersection {
private:
	std::vector<Car> inCars;
	int x1, x2, y1, y2;
	float rate;

	/*
	* x1             x2
	* ----------------- y1
	* -       -       -
	* -   q2  -   q1  -
	* -       -       -
	* -----------------
	* -       -       -
	* -   q3  -   q4  -
	* -       -       -
	* ----------------- y2
	*/
public:

	Intersection(int width, int rdw, float rate);

	/*
	* Assume two cars from same road do not occupy the intersecting area together (for safety and realistic reasons)
	* Assume two cars from different roads do not enter the intersecting area at the EXACT same time (tick)
	* FIFO
	*/
	void inInt(std::vector<Car>& cars);

	void outInt(std::vector<Car>& cars);

	bool checkOrg(int org);

	bool checkDes(int des);

	Car getOrgCar(int org);

	void checkCol();
};