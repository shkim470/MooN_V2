#pragma once

#include "MNSingletone.h"

#include "data_type.h"



class CGLCVCommon
{
public:
	CGLCVCommon();
	~CGLCVCommon();

	GLuint GetGLTextureID(cv::Mat& _img, bool _IsThumbnail);  
	cv::Mat GenThumbnail(cv::Mat& _img, unsigned short _thumbnail_size);


};

typedef CMNSingleton<CGLCVCommon> SINGLETON_GLCV;