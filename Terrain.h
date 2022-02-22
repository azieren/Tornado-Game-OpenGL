#pragma once
#include "Point.h"

class Terrain
{

private:
	float scale;
	point p[4];
	int cows;
	point *cow_positions;
	float* foundCow;
public:
	Terrain();
	Terrain(float s) : Terrain() { scale = s; };
	Terrain(int nb_cow, float s);
	void draw();
	int getNCows() { return cows; };
	point getCows(int i) { if (i > cows) { return { 0.0, 0.0, 0.0 }; } return cow_positions[i]; };
	void setCow(int i);
	float hasfoundCow(int i) { if (i > cows) { return false; } return foundCow[i]; };
	void setfoundCow(int i, float v);
	float getLimit() { return scale / 2.0; };
	~Terrain() {};
};

