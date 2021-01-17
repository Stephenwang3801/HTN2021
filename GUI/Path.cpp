#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>

using namespace std;

class Path {
public:
	int width, rdw, org;
	double x, y;
	double pi = M_PI;

	Path() {

	}

	Path(int width, int rdw, int org) {
		this->width = width;
		this->rdw = rdw;
		this->org = org;

		setStart();
	}

	void setStart() {
		//North
		if (org == 0) {
			x = (double) width / 2 - rdw / 4;
			y = 0;
		} //East
		else if (org == 1) {
			x = width;
			y = (double) width / 2 - rdw / 4;
		} //South
		else if (org == 2) {
			x = (double) width / 2 + rdw / 4;
			y = width;
		} //West
		else if (org == 3) {
			x = 0;
			y = (double) width / 2 + rdw / 4;
		}
	}

	void move(double rate, int relPos) {
		std::cout << "Should not happen" << endl;
	}

	void setX(double d) {
		this->x += d;
	}

	void setY(double d) {
		this->y += d;
	}

	double getX() {
		return x;
	}

	double getY() {
		return y;
	}
};

class StraightPath : public Path {
public:
	StraightPath() {

	}

	StraightPath(int width, int rdw, int org) : Path(width, rdw, org) {}

	void move(double rate, int relPos) {
		if (org == 0) {
			setY(rate);
		}
		else if (org == 1) {
			setX(-rate);
		}
		else if (org == 2) {
			setY(-rate);
		}
		else if (org == 3) {
			setX(rate);
		}
	}
};

class LeftPath : public Path {
public:
	LeftPath() {

	}

	LeftPath(int width, int rdw, int org) : Path(width, rdw, org) {}

	void move(double rate, int relPos) {
		if (relPos == -1) {
			if (org == 0) {
				y += rate;
			}
			else if (org == 1) {
				x -= rate;
			}
			else if (org == 2) {
				y -= rate;
			}
			else if (org == 3) {
				x += rate;
			}
		}
		else if (relPos == 0) {
			if (org == 0) {
				x += 2 / (3 * pi) * rate;
				y += 2 / (3 * pi) * rate;
			}
			else if (org == 1) {
				x -= 2 / (3 * pi) * rate;
				y -= 2 / (3 * pi) * rate;
			}
			else if (org == 2) {
				x += 2 / (3 * pi) * rate;
				y -= 2 / (3 * pi) * rate;
			}
			else if (org == 3) {
				x += 2 / (3 * pi) * rate;
				y += 2 / (3 * pi) * rate;
			}
		}
		else if (relPos == 1) {
			if (org == 0) {
				x += rate;
			}
			else if (org == 1) {
				y += rate;
			}
			else if (org == 2) {
				x -= rate;
			}
			else if (org == 3) {
				y -= rate;
			}
		}
	}
};

class RightPath : public Path {
public:
	RightPath() {

	}

	RightPath(int width, int rdw, int org) : Path(width, rdw, org) {}

	void move(double rate, int relPos) {
		if (relPos == -1) {
			if (org == 0) {
				y += rate;
			}
			else if (org == 1) {
				x -= rate;
			}
			else if (org == 2) {
				y -= rate;
			}
			else if (org == 3) {
				x += rate;
			}
		}
		else if (relPos == 0) {
			if (org == 0) {
				x -= 2 / pi * rate;
				y += 2 / pi * rate;
			}
			else if (org == 1) {
				x -= 2 / pi * rate;
				y -= 2 / pi * rate;
			}
			else if (org == 2) {
				x += 2 / pi * rate;
				y -= 2 / pi * rate;
			}
			else if (org == 3) {
				x += 2 / pi * rate;
				y += 2 / pi * rate;
			}
		}
		else if (relPos == 1) {
			if (org == 0) {
				x -= rate;
			}
			else if (org == 1) {
				y -= rate;
			}
			else if (org == 2) {
				x += rate;
			}
			else if (org == 3) {
				y += rate;
			}
		}
	}
};