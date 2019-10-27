#pragma once
#include "data_type.h"

#define _DEFAULT_IMGOBJ_SIZE 100.0f
class CMNObject
{
public:
	CMNObject();
	virtual ~CMNObject();

	//Operations
	virtual void Draw(void) = 0;
	virtual void SetImgObject(char* path, unsigned long _uid, float objSize = _DEFAULT_IMGOBJ_SIZE) = 0;

	int m_objType;
	unsigned long m_objuid;
	

	//int GetObjType() { return m_objType; }
	//unsigned long GetObjUID() { return m_objuid; }

	void	SetObjectPos(float x, float y, float z) { m_objPos.set(x, y, z); }
	POINT3D GetObjectPos() { return m_objPos; }

protected:
	std::vector<_stClassificationLabel> m_clsLabelInfo;
	std::vector<_stSegmentationLabel> m_segLabelInfo;	

	POINT3D m_objPos;
	

};

