#pragma once
#include "MNSingletone.h"
#include <string>


typedef struct _mnInitCfg {
	std::string strInitPath;

}_mnInitCfg;

class CMNFileManager
{
public:
	CMNFileManager();
	~CMNFileManager();

// Converting Operation //
	void CStringToChar(CString _str, char* _pt, int _len);



// Init Configuration Info //
	_mnInitCfg m_initCfgInfo;
	bool LoadInitConfigFile(char* _path);
	bool SaveInitConfigFile(char* _path);
	void SetInitCfgInfo(_mnInitCfg _info) { m_initCfgInfo = _info; }
	_mnInitCfg GetInitCfgInfo() { return m_initCfgInfo; }	
//===========================================//
};

typedef CMNSingleton<CMNFileManager> SINGLETON_FileMng;