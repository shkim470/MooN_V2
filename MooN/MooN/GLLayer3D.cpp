#include "stdafx.h"
#include "GLLayer3D.h"



CGLLayer3DForImg::CGLLayer3DForImg()
{

}
CGLLayer3DForImg::~CGLLayer3DForImg()
{

}

void CGLLayer3DForImg::Render()
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
void CGLLayer3DForImg::InitView(int _nWidth, int _nHeight)
{
	m_nWidth = _nWidth;
	m_nHeight = _nHeight;
}