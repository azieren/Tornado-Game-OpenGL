#include "Tornado.h"

Tornado::Tornado(float h, float r, int n1_ring, int n2_ring, int p)
{
	height = h;
	radius = r;
	n1 = n1_ring;
	n2 = n2_ring;
	dust = new Dust[p];
	n_particle = p;
	ring = Ring(radius, h, n1, n2);

	generateParticles(1.0);

}

void Tornado::draw()
{
	ring.draw(1.0, 0.0, 0.0);
}

void Tornado::drawParticle()
{
	glColor3f(1.0, 1.0, 0.0);
	
	for (int i = 1; i <= n_particle; i++) {
		glPointSize(1.8*uniform() + 0.2);
		glBegin(GL_POINTS);
		glNormal3f(dust[i].x(), dust[i].y(), dust[i].z());
		glVertex3f(dust[i].x(), dust[i].y(), dust[i].z());
		//glVertex3f(dust[i-1].x(), dust[i-1].y(), dust[i-1].z());
		glEnd();
	}

	
	glPointSize(1.);
}

void Tornado::generateParticles(float life)
{
	point pos;
	float angle = 0.0;

	for (int i = 0; i < n_particle; i++) {
		angle = 360.0 * uniform();
		pos = { radius*cos(angle * (float)M_PI/180.0f), radius * sin(angle * (float)M_PI / 180.0f), uniform(0.0, height*1.05 ) };
		dust[i] = Dust(pos, life*uniform(0.5,1));
	}
}

Tornado::~Tornado()
{
}
