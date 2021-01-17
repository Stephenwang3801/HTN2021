#define _USE_MATH_DEFINES
#include <math.h>

class Path {
public:
	int width, rdw, org;
	float x, y;
	float rate;
	double pi = M_PI;

	Path();

	Path(int width, int rdw, int org, float rate) {
		this->width = width;
		this->rdw = rdw;
		this->org = org;
		this->rate = rate;

		x = 0;
		y = 0;

		setStart();
	}
	void setStart() {
		//North
		if (org == 0) {
			x = width / 2 - rdw / 4;
			y = 0;
		} //East
		else if (org == 1) {
			x = width;
			y = width / 2 - rdw / 4;
		} //South
		else if (org == 2) {
			x = width / 2 + rdw / 4;
			y = width;
		} //West
		else if (org == 3) {
			x = 0;
			y = width / 2 + rdw / 4;
		}
	}

	float getX() {
		return x;
	}

	float getY() {
		return y;
	}

	void setRate(float rate) {
		this->rate = rate;
	}
};
	
class StraightPath : public Path {
public:
	StraightPath(int width, int rdw, int org, float rate) : Path(width, rdw, org, rate) {};

	void move(float rate) {
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
};

class LeftPath : public Path {
public:
	LeftPath(int width, int rdw, int org, float rate) : Path(width, rdw, org, rate) {};

	void moveTo(float rate) {
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

	void moveOut(float rate) {
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

	void moveFr(float rate) {
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
};

class RightPath : public Path {
public:
	RightPath(int width, int rdw, int org, float rate) : Path(width, rdw, org, rate) {};

	void moveTo(float rate) {
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

	void moveOut(float rate) {
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

	void moveFr(float rate) {
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
};