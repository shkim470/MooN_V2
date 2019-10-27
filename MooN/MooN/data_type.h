#pragma once

#include <vector>
#include <map>

#include "opencv/cv.h"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/photo.hpp"

#include <gl/gl.h>
#include <gl/glu.h>

#define	MNOBJ_SIZE 100
enum MNTIMER_EVTID { _MNRENDER=100};
enum MNOBJECT_TYPE { _MNOBJ_IMG=0};


struct POINT3D
{
	float x, y, z;
	
	void set(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}
};

struct POINT2D
{
	float x, y;

	void set(float _x, float _y)
	{
		x = _x;
		y = _y;
	}
};

struct _stClassificationLabel
{
	float cx, cy, w, h;
	int code;
	wchar_t name[256];
};


struct _stSegmentationLabel
{
	std::vector<POINT2D> pnts;
	int num;
	int code;
	wchar_t name[256];
};

struct _stMNRect3D
{
	POINT3D v[4];
	POINT2D t[4];
	
	void setRect(float cx, float cy, float w, float h, float z)
	{
		v[0].set(cx - w * 0.5f, cy - h * 0.5f, z);
		v[1].set(cx + w * 0.5f, cy - h * 0.5f, z);
		v[2].set(cx + w * 0.5f, cy + h * 0.5f, z);
		v[3].set(cx - w * 0.5f, cy + h * 0.5f, z);

		t[0].set(0.0f, 1.0f);
		t[1].set(1.0f, 1.0f);
		t[2].set(1.0f, 0.0f);
		t[3].set(0.0f, 0.0f);
	}
};