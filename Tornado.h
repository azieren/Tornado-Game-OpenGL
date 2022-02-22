#pragma once
#include "Ring.h"
#include "Dust.h"

class Tornado
{
private:
	float height;
	float radius;
	float n1, n2;
	int n_particle;
	Ring ring;
	Dust* dust;

public:
	Tornado(float h, float r, int n1_ring, int n2_ring, int p);
	void draw();
	void drawParticle();
	void generateParticles(float life);
	float getRadius() { return radius; };
	float getHeight() { return height; };
	~Tornado();
};

