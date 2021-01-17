#include <iostream>
#include <vector>
#include "Car.h"

using namespace std;

/*
* Handle cars moving through intersection
*/
class Intersection {
private:
	std::vector<Car> inCars;
	int x1, x2, y1, y2;
	float rate;

	/*
	* x1             x2
	* ----------------- y1
	* -               -
	* -               -
	* -               -
	* -               -
	* -               -
	* -               -
	* -               -
	* ----------------- y2
	*/

public:
	Intersection(int width, int rdw, float rate) {
		x1 = width - rdw / 2;
		x2 = width + rdw / 2;

		y1 = width - rdw / 2;
		y2 = width + rdw / 2;

		this->rate = rate;

		x1 = -1;
		x2 = -1;
		y1 = -1;
		y2 = -1;
	}

	/*
	* Assume two cars from same road do not occupy the intersecting area together (for safety and realistic reasons)
	* Assume two cars from different roads do not enter the intersecting area at the EXACT same time (tick)
	* FIFO
	*/
	void inInt(std::vector<Car> &cars) {
		Car car = cars[0];
		if (car.getX() >= x1 && car.getX() <= x2) {
			if (car.getY() >= y1 && car.getY() <= y2) {
				inCars.push_back(car);
				cars.erase(cars.begin());
				std::cout << "Car entered intersection" << endl;
				checkCol();
			}
		}
	}

	void outInt(std::vector<Car>& cars) {
		Car car = inCars[0];
		if (car.getX() < x1 || car.getX() > x2 || car.getY() < y1 || car.getY() > y2) {
			car.rstRate();
			cars.push_back(car);
			inCars.erase(inCars.begin());
			std::cout << "A car left the intersection" << endl;

			inCars[0].setAccel(true);
			inCars[0].setDecel(false);
			inCars[0].rstRate();
		}
	}

	bool checkOrg(int org) {
		for (Car car : inCars) {
			if (car.getOrg() == org) {
				return true;
			}
		}
		return false;
	}

	bool checkDes(int des) {
		for (Car car : inCars) {
			if (car.getDes() == des) {
				return true;
			}
		}
		return false;
	}

	Car getOrgCar(int org) {
		for (Car car : inCars) {
			if (car.getOrg() == org) {
				return car;
			}
		}
	}

	/*
	* Control speed of entering cars to avoid collisions
	*/
	void checkCol() {
		//If equal to 0, don't change speed
		if (inCars.size() > 2) {
			Car temp = inCars.back();
			temp.setDecel(true);
		}
		else if (inCars.size() == 2) {
			Car temp1 = inCars[0];
			Car temp2 = inCars[1];

			/*
			* 0 - straight
			* 1 - left
			* 2 - right
			*/
			if (temp1.pathType() == 0 && temp2.pathType() == 0) {
				if (temp1.getOrg() == 0 && temp2.getOrg() == 2) {
					//No speed change
				}
				else if (temp1.getOrg() == 2 && temp2.getOrg() == 0) {
					//No speed change
				}
				else if (temp1.getOrg() == 1 && temp2.getOrg() == 3) {
					//No speed change
				}
				else if (temp1.getOrg() == 3 && temp2.getOrg() == 1) {
					//No speed change
				}
				else {
					temp2.setDecel(true);
				}
			}
			else if (temp1.pathType() == 2 && temp2.pathType() == 2) {
				//No speed change
			}
			else if (temp1.pathType() == 0 && temp2.pathType() == 2) {
				if (temp1.getOrg() == 0) {
					if (temp2.getOrg() == 1 || temp2.getOrg() == 2) {
						//No speed change
					}
					else {
						temp2.setDecel(true);
					}
				}
				else if (temp1.getOrg() == 1) {
					if (temp2.getOrg() == 2 || temp2.getOrg() == 3) {
						//No speed change
					}
					else {
						temp2.setDecel(true);
					}
				}
				else if (temp1.getOrg() == 2) {
					if (temp2.getOrg() == 0 || temp2.getOrg() == 3) {
						//No speed change
					}
					else {
						temp2.setDecel(true);
					}
				}
				else if (temp1.getOrg() == 3) {
					if (temp2.getOrg() == 0 || temp2.getOrg() == 1) {
						//No speed change
					}
					else {
						temp2.setDecel(true);
					}
				}
			}
			else if (temp2.pathType() == 0 && temp1.pathType() == 2) {
				if (temp2.getOrg() == 0) {
					if (temp1.getOrg() == 1 || temp1.getOrg() == 2) {
						//No speed change
					}
					else {
						temp1.setDecel(true);
					}
				}
				else if (temp2.getOrg() == 1) {
					if (temp1.getOrg() == 2 || temp1.getOrg() == 3) {
						//No speed change
					}
					else {
						temp1.setDecel(true);
					}
				}
				else if (temp2.getOrg() == 2) {
					if (temp1.getOrg() == 0 || temp1.getOrg() == 3) {
						//No speed change
					}
					else {
						temp1.setDecel(true);
					}
				}
				else if (temp2.getOrg() == 3) {
					if (temp1.getOrg() == 0 || temp1.getOrg() == 1) {
						//No speed change
					}
					else {
						temp1.setDecel(true);
					}
				}
			}
			else {
				temp2.setDecel(true);
			}
		}
		else if (inCars.size() == 1) {
		//No speed change
		}
	}
};