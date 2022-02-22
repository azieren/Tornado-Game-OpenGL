#include "TreeProc.h"

void TreeProc::recursive(int curr_n, int curr_b, Curve *root)
{
	if (curr_n == 0) {
		return;
	}

	float tmp = h / pow(4.0f, n - curr_n), a = 0.4f;
	float cc = tmp * cos(2.0f * (curr_b + 1.f) * M_PI / b);
	float ss = tmp * sin(2.0f * (curr_b + 1.f) * M_PI / b);
	float angle[3] = { uniform(-10, 10), uniform(-60, 60), uniform(-1, 1) };

	point p0 = root->sample(0.7  + 0.3 * uniform(-1.f, 1.f));
	point p1 = { 0.33*uniform(-a, a) + cc / 3.0f, tmp / 3.0f,  0.33 * uniform(-a, a) + ss / 3.0f };
	point p2 = { 0.66 * uniform(-a, a) + cc * 2.0f / 3.0f, tmp * 2.0f / 3.0f,  0.66 * uniform(-a, a) + ss * 2.0f / 3.0f };
	point p3 = { uniform(-a, a) + cc, tmp, uniform(-a, a) + ss };

	p1.x += p0.x; p2.x += p0.x; p3.x += p0.x;
	p1.y += p0.y; p2.y += p0.y; p3.y += p0.y;
	p1.z += p0.z; p2.z += p0.z; p3.z += p0.z;

	RotateAll(&p1, angle, p0);
	RotateAll(&p2, angle, p0);
	RotateAll(&p3, angle, p0);

	root = new Curve(p0, p1, p3, 0.8f, 0.3f, 0.05f);
	root->setWidth(6.0f*0.8f* (curr_n + 1.f)/n);
	if (curr_n - 1 == 0) { 
		root->setLeaf(true); 
	}
	else {
		root->setRoot(true);
	}
	c[count] = *root;
	count += 1;

	for (int i = 0; i < b; i++)
	{
		recursive(curr_n - 1, i, root);
	}
	return;
}

TreeProc::TreeProc(int nn, int bb, float hh)
{
	count = 1;
	float deg = 0.0,  a = 0.4;
	float tmp = hh;
	n = nn;
	b = bb;
	h = hh;
	c = new Curve[ (int) pow(b, n + 1) /2];
	point p0{ a * uniform(), -hh / 2.0, a * uniform() }, p1{ a * uniform(), -1.0f * hh / 4.0f, a * uniform() };
	point p2{ a * uniform(), 1.0f * hh/4.0f, a * uniform() }, p3{ a * uniform(), hh/2.0, a * uniform() };

	Curve *root = new Curve(p0, p1, p2, p3, 0.7f, 0.1f, 0.05f);
	root->setWidth(10.0);
	root->setRoot(true);
	c[0] = *root;

	for (int i = 0; i < b; i++)
	{
		recursive(n - 1, i, root);
	}

}

void TreeProc::Rotate(float time, bool addPoint, bool addLine)
{
	for (int i = 0; i < count; i++)
	{
		if (c[i].getLeaf()) 
		{ 
			c[i].RandomRotate(2, time);
		}	
		c[i].draw(10);
		if (addPoint) { c[i].drawPoints(5.0); }
		if (addLine) { c[i].drawLines(2.0); }
	}
}

void TreeProc::draw(bool addPoint, bool addLine)
{
	for (int i = 0; i < count; i++)
	{
		c[i].draw(10);
		if (addPoint) { c[i].drawPoints(4.0); }
		if (addLine) { c[i].drawLines(2.0); }
	}
}

TreeProc::~TreeProc()
{
}
