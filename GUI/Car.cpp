#include "Path.h"


class Car {
private:
	int width, rdw;
	int org, des;
	float x, y;
	float orgRate, rate;
	Path path;
	bool decel, accel;

public:
	Car(int width, int rdw, int org, int des, float rate) {
		this->width = width;
		this->rdw = rdw;
		this->org = org;
		this->des = des;
		this->rate = rate;
		orgRate = rate;
		decel = false;
		accel = false;

		if (org == 0) {
			if (des == 1) {
				path = LeftPath(width, rdw, 0, rate);
			}
			else if (des == 2) {
				path = StraightPath(width, rdw, 0, rate);
			}
			else if (des == 3) {
				path = RightPath(width, rdw, 0, rate);
			}
		}
		else if (org == 1) {
			if (des == 0) {
				path = RightPath(width, rdw, 0, rate);
			}
			else if (des == 2) {
				path = LeftPath(width, rdw, 0, rate);
			}
			else if (des == 3) {
				path = StraightPath(width, rdw, 0, rate);
			}
		}
		else if (org == 2) {
			if (des == 0) {
				path = StraightPath(width, rdw, 0, rate);
			}
			else if (des == 1) {
				path = RightPath(width, rdw, 0, rate);
			}
			else if (des == 3) {
				path = LeftPath(width, rdw, 0, rate);
			}
		}
		else if (org == 3) {
			if (des == 0) {
				path = LeftPath(width, rdw, 0, rate);
			}
			else if (des == 1) {
				path = StraightPath(width, rdw, 0, rate);
			}
			else if (des == 2) {
				path = RightPath(width, rdw, 0, rate);
			}
		}

		x = path.getX();
		y = path.getY();
	}

	int getOrg() {
		return org;
	}

	int getDes() {
		return des;
	}

	float getX() {
		return x;
	}

	float getY() {
		return y;
	}

	/*
	* 0 - straight
	* 1 - left
	* 2 - right
	*/
	int pathType() {
		if (org - des == 2 || org - des == -2) {
			return 0;
		}
		else if (org - des == -1 || org - des == 3) {
			return 1;
		}
		else if (org - des == 1 || org - des == -3) {
			return 2;
		}
	}

	void setRate(float rate) {
		this->rate = rate;
	}

	void setAccel(bool foo) {
		accel = foo;
	}

	void setDecel(bool foo) {
		decel = foo;
	}

	void decelerate() {
		this->rate -= 0.05;
		if (rate == 0) {
			decel = false;
		}
	}

	void rstRate() {
		if (rate == orgRate) {
			accel = false;
		}
		else if (accel) {
			this->rate += 0.05;
		}
	}
};