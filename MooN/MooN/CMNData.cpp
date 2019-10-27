#include "stdafx.h"
#include "CMNData.h"


CMNDataMng::CMNDataMng()
{
}


CMNDataMng::~CMNDataMng()
{
	std::map<unsigned long, CMNObject*>::iterator iter = m_mapObect.begin();
	for (; iter != m_mapObect.end(); iter++) {
		delete iter->second;
	}
	m_mapObect.swap(std::map<unsigned long, CMNObject*>());
}

unsigned int CMNDataMng::getHashCode(const char * szText)
{
	unsigned int hash = 5381;
	int c;

	while (c = *szText++)
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return hash;
}


void CMNDataMng::AddObjects(CMNObject* pobj)
{
	if (pobj->m_objType == 0) {
		if (m_mapObect.find(pobj->m_objuid) == m_mapObect.end()) {
			m_mapObect[pobj->m_objuid] = (CMNObjectImage*)pobj;
		}
	}
	else {
		delete pobj;
	}
}

void CMNDataMng::AddImageData(char* _path)
{
	CMNObject* pObj = new CMNObjectImage;	
	pObj->SetImgObject(_path, getHashCode(_path), MNOBJ_SIZE);
	AddObjects(pObj);	   	 
}