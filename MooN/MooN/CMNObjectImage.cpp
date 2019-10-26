#include "stdafx.h"
#include "CMNObjectImage.h"


CMNObjectImage::CMNObjectImage()
{
}


CMNObjectImage::~CMNObjectImage()
{
}


void CMNObjectImage::Draw(void)
{

}
void CMNObjectImage::SetImgObject(char* path, float objSize)
{
	m_srcImg = cv::imread(path);
	
	m_bgRect.setRect(0.0f, 0.0f, objSize, objSize, 0.0f);


}