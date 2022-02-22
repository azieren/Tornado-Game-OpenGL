#include "Terrain.h"

Terrain::Terrain()
{
	p[0] = {-0.5, -0.5, 0.0};
	p[1] = { -0.5, 0.5, 0.0 };
	p[2] = { 0.5, -0.5, 0.0 };
	p[3] = { 0.5, 0.5, 0.0 };
	cows = 0;
	cow_positions = NULL;
	foundCow = NULL;
	scale = 1.0;
}

Terrain::Terrain(int nb_cow, float s)
{
	scale = s;
	cows = nb_cow;
	cow_positions = new point[nb_cow];
	foundCow = new float[nb_cow];
	for (int i = 0; i < nb_cow; i++)
	{
		cow_positions[i] = { scale*uniform() - scale * 0.5f, scale * uniform() - scale * 0.5f, 0.0 };
		foundCow[i] = -1.0f;
	}
	p[0] = { -0.5, -0.5, 0.0 };
	p[1] = { -0.5, 0.5, 0.0 };
	p[2] = { 0.5, -0.5, 0.0 };
	p[3] = { 0.5, 0.5, 0.0 };
}

void Terrain::draw()
{
	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i < 4; i++)
	{
		if (i == 0) glTexCoord2f(0, 0);
		if (i == 1) glTexCoord2f(0, 1);
		if (i == 2) glTexCoord2f(1, 0);
		if (i == 3) glTexCoord2f(1, 1);
		glNormal3f(0.0, 0.0, 1.0);
		glVertex3f(scale * p[i].x, scale * p[i].y, p[i].z);
	}
	glEnd();
}

void Terrain::setCow(int i)
{
	if (i > cows) { 
		return; 
	}  
	cow_positions[i] = { scale * uniform() - scale * 0.5f, scale * uniform() - scale * 0.5f, 0.0 }; 
	foundCow[i] = -1.0;
}

void Terrain::setfoundCow(int i, float v)
{
	if (i > cows) { 
		return; 
	} 
	foundCow[i] = v;

	if (v < 0.0f) {
		setCow(i);
		return;
	}
}
