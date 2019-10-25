#pragma once
#include "data_type.h"
#include <gl/gl.h>
#include <gl/glu.h>

class CGLButton
{
public:
	CGLButton();
	~CGLButton();

	void SetButton(GLuint _texId, float _width, float _height, int _type);

private:
	GLuint m_buttonImg[3]; // 0 normal, 1 mouse over, 2, click
	POINT3D m_centerPos;
	POINT3D m_vecRect[4];
	


};

