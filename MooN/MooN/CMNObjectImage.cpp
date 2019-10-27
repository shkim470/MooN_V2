#include "stdafx.h"
#include "CMNObjectImage.h"
#include "CGLCVCommon.h"



CMNObjectImage::CMNObjectImage()
{
}


CMNObjectImage::~CMNObjectImage()
{
}


void CMNObjectImage::Draw(void)
{
	glColor3f(0.5f, 0.5f, 1.0f);
	glBegin(GL_LINE_STRIP);
	glVertex3f(m_bgRect.v[0].x, m_bgRect.v[0].y, m_bgRect.v[0].z);
	glVertex3f(m_bgRect.v[1].x, m_bgRect.v[1].y, m_bgRect.v[1].z);
	glVertex3f(m_bgRect.v[2].x, m_bgRect.v[2].y, m_bgRect.v[2].z);
	glVertex3f(m_bgRect.v[3].x, m_bgRect.v[3].y, m_bgRect.v[3].z);
	glVertex3f(m_bgRect.v[0].x, m_bgRect.v[0].y, m_bgRect.v[0].z);
	glEnd();



	glColor3f(1.0f, 1.0f, 1.0f);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, m_texId);
	glBegin(GL_QUADS);
	glTexCoord2f(m_imgRect.t[0].x, m_imgRect.t[0].y);	glVertex3f(m_imgRect.v[0].x, m_imgRect.v[0].y, m_imgRect.v[0].z);
	glTexCoord2f(m_imgRect.t[1].x, m_imgRect.t[1].y);	glVertex3f(m_imgRect.v[1].x, m_imgRect.v[1].y, m_imgRect.v[1].z);
	glTexCoord2f(m_imgRect.t[2].x, m_imgRect.t[2].y);	glVertex3f(m_imgRect.v[2].x, m_imgRect.v[2].y, m_imgRect.v[2].z);
	glTexCoord2f(m_imgRect.t[3].x, m_imgRect.t[3].y);	glVertex3f(m_imgRect.v[3].x, m_imgRect.v[3].y, m_imgRect.v[3].z);
	glEnd();
	glDisable(GL_TEXTURE_2D);

}
void CMNObjectImage::SetImgObject(char* path, unsigned long _uid, float objSize)
{
	m_objType = _MNOBJ_IMG;
	m_objuid = _uid;

	m_srcImg = cv::imread(path, CV_LOAD_IMAGE_COLOR);
	m_texId = SINGLETON_GLCV::GetInstance()->GetGLTextureID(m_srcImg, false);

	m_bgRect.setRect(0.0f, 0.0f, objSize, objSize, 0.0f);

	float aRatio = (float)m_srcImg.cols / (float)m_srcImg.rows;
	if (aRatio < 1.0f) {
		m_imgRect.setRect(0.0f, 0.0f, objSize*aRatio, objSize, 0.0f);
	}
	else {
		aRatio = (float)m_srcImg.rows / (float)m_srcImg.cols;
		m_imgRect.setRect(0.0f, 0.0f, objSize, objSize*aRatio, 0.0f);
	}
}