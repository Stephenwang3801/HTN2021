#define _USE_MATH_DEFINES
#include <math.h>

class Path {
public:
	int width, rdw, org;
	float x, y;
	float rate;
	double pi = M_PI;

	Path();

	Path(int width, int rdw, int org, float rate);

	void setStart();

	float getX();

	float getY();

	void setRate(float rate);
};

class StraightPath : public Path {
public:
	StraightPath(int width, int rdw, int org, float rate) : Path(width, rdw, org, rate) {};

	void move(float rate);
};

class LeftPath : public Path {
public:
	LeftPath(int width, int rdw, int org, float rate) : Path(width, rdw, org, rate) {};

	void moveTo(float rate);

	void moveOut(float rate);

	void moveFr(float rate);
};

class RightPath : public Path {
public:
	RightPath(int width, int rdw, int org, float rate) : Path(width, rdw, org, rate) {};

	void moveTo(float rate);

	void moveOut(float rate);

	void moveFr(float rate);
};