#include "stdafx.h"
#include "GLLayer3D.h"
#include "CMNData.h"



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

	
	std::map<unsigned long, CMNObject*> mapObj = SINGLETON_MNDATAMng::GetInstance()->GetObjectList();
	std::map<unsigned long, CMNObject*>::iterator iter = mapObj.begin();
	for (; iter != mapObj.end(); iter++) {
		iter->second->Draw();
	}
}
void CGLLayer3DForImg::InitView(int _nWidth, int _nHeight)
{
	m_nWidth = _nWidth;
	m_nHeight = _nHeight;
}