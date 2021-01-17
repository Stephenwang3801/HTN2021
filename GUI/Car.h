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
	Car(int width, int rdw, int org, int des, float rate);

	int getOrg();

	int getDes();

	float getX();

	float getY();

	int pathType();

	void setRate(float rate);

	void setAccel(bool foo);

	void setDecel(bool foo);

	void decelerate();

	void rstRate();
};