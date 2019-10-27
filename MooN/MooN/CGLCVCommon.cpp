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
	GLenum err = glGetError();	
	glGenTextures(1, &texid);
	err = glGetError();


	cv::Mat tmp;
	cv::resize(_img, tmp, cv::Size(2048, 2048));


	glBindTexture(GL_TEXTURE_2D, texid);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, tmp.cols, tmp.rows, GL_RGB, GL_UNSIGNED_BYTE, tmp.ptr());

	//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	//glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, tmp.cols, tmp.rows, 0, GL_RGB, GL_UNSIGNED_BYTE, tmp.ptr());

	return texid;
}


cv::Mat CGLCVCommon::GenThumbnail(cv::Mat& _img, unsigned short _thumbnail_size)
{
	cv::Mat thimg;
	return thimg;
}