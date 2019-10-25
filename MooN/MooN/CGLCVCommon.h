#pragma once

#include "MNSingletone.h"

#include "data_type.h"
#include "opencv/cv.h"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/photo.hpp"

#include <gl/gl.h>
#include <gl/glu.h>


class CGLCVCommon
{
public:
	CGLCVCommon();
	~CGLCVCommon();

	GLuint GetGLTextureID(cv::Mat& _img, bool _IsThumbnail);  
	cv::Mat GenThumbnail(cv::Mat& _img, unsigned short _thumbnail_size);


};

typedef CMNSingleton<CGLCVCommon> SINGLETON_CVMng;