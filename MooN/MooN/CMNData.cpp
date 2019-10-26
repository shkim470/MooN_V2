#include "stdafx.h"
#include "CMNData.h"


CMNDataMng::CMNDataMng()
{
}


CMNDataMng::~CMNDataMng()
{
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
}

void CMNDataMng::AddImageData(char* _path)
{
	CMNObject* pObj = new CMNObjectImage;
	
	pObj->m_objuid = getHashCode(_path);
	pObj->SetImgObject(_path);

	   	 
}