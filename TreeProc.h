#pragma once
#include "Curve.h"

class TreeProc
{
private:
	int n, b;
	int count;
	float h;
	Curve *c;
	void recursive(int curr_n, int curr_b, Curve *root);

public:
	TreeProc() :TreeProc(0.f, 0.f, 1.f) {};
	TreeProc(int nn, int bb, float hh);
	void Rotate(float time, bool addPoint, bool addLine);
	void draw(bool addPoint, bool addLine);
	~TreeProc();
};

