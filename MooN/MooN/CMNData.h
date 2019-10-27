#pragma once

#include "MNSingletone.h"
#include "data_type.h"
#include "CMNObjectImage.h"

class CMNDataMng
{
public:
	CMNDataMng();
	~CMNDataMng();

	void AddObjects(CMNObject* pobj);
	void AddImageData(char* _path);
	std::map<unsigned long, CMNObject*>& GetObjectList() { return m_mapObect; }

private:
	unsigned int getHashCode(const char * szText);

	std::map<unsigned long, CMNObject*> m_mapObect;


};


typedef CMNSingleton<CMNDataMng> SINGLETON_MNDATAMng;
