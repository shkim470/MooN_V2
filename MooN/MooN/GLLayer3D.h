#pragma once
#include "GLLayer.h"
class CGLLayer3D : public CGLLayer
{
public:
	CGLLayer3D();
	~CGLLayer3D();

	void Render();
	void InitView(int _nWidth, int _nHeight);
};

