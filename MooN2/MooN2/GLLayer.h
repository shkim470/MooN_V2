#pragma once
#include <gl/gl.h>
#include <gl/glu.h>

class CGLLayer
{

public:
	CGLLayer();
	virtual ~CGLLayer();

	//Operations
	virtual void Render(void) = 0;
	virtual void InitView(int _nWidth, int _nHeight) = 0;

protected:
	// Attributes
	int m_nWidth;
	int m_nHeight;

};

