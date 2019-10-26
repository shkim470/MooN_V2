#pragma once
#include "CMNObject.h"
class CMNObjectImage :	public CMNObject
{
public:
	CMNObjectImage();
	~CMNObjectImage();


	void Draw(void);
	void SetImgObject(char* path, float objSize = _DEFAULT_IMGOBJ_SIZE);

private:
	cv::Mat m_srcImg;
	cv::Mat m_thumbnail;

	GLuint m_texId;
	_stMNRect3D m_imgRect;
	_stMNRect3D m_bgRect;
};

