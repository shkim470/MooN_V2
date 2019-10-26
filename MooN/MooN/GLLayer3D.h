#pragma once
#include "GLLayer.h"
class CGLLayer3DForImg: public CGLLayer
{
public:
	CGLLayer3DForImg();
	~CGLLayer3DForImg();

	void Render();
	void InitView(int _nWidth, int _nHeight);
};

