#include "pch.h"
#include "GLLayer3D.h"



CGLLayer3D::CGLLayer3D()
{

}
CGLLayer3D::~CGLLayer3D()
{

}

void CGLLayer3D::Render()
{
	glLoadIdentity();
	gluLookAt(0.0f, 0.0f, 1000.0f, 0.0f, 10.f, 0.0f, 0.0f, 1.0f, 0.0f);

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	glVertex3f(-50, -50, 0);
	glVertex3f(50, -50, 0);
	glVertex3f(50, 50, 0);
	glVertex3f(-50, 50, 0);
	glEnd();

}
void CGLLayer3D::InitView(int _nWidth, int _nHeight)
{
	m_nWidth = _nWidth;
	m_nHeight = _nHeight;
}