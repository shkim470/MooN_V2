#include "stdafx.h"
#include "CGLCVCommon.h"


CGLCVCommon::CGLCVCommon()
{
}


CGLCVCommon::~CGLCVCommon()
{
}


GLuint CGLCVCommon::GetGLTextureID(cv::Mat& _img, bool _IsThumbnail)
{
	GLuint texid = 0;

	glGenTextures(1, &texid);
	glBindTexture(GL_TEXTURE_2D, texid);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, _img.cols, _img.rows, GL_RGB, GL_UNSIGNED_BYTE, _img.ptr());

	return texid;
}


cv::Mat CGLCVCommon::GenThumbnail(cv::Mat& _img, unsigned short _thumbnail_size)
{
	cv::Mat thimg;

	return thimg;
}