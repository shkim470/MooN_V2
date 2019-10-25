#include "stdafx.h"
#include "CMNFileManager.h"


CMNFileManager::CMNFileManager()
{
	m_initCfgInfo.strInitPath = "";
}


CMNFileManager::~CMNFileManager()
{

}


// Windows Dependent //
void CMNFileManager::CStringToChar(CString _str, char* _pt, int _len)
{
	//CStringA tmpStr = CStringA(_str);
	//const char* st = tmpStr;
	//char* _pt = const_cast<char*>(st);
	CStringA tmpStr = CStringA(_str);
	const char* st = tmpStr;	
	memcpy(_pt, st, _len);
}
//Windows Dependent==============================//

bool CMNFileManager::LoadInitConfigFile(char* _path)
{
	FILE* fp = 0;
	fopen_s(&fp, _path, "rb");

	char srcPath[256];
	memset(srcPath, 0x00, sizeof(256));
	if (fp) {
		SYSTEMTIME st;
		fread(&st, sizeof(SYSTEMTIME), 1, fp);
		fread(srcPath, sizeof(srcPath), 1, fp);
		fclose(fp);
		m_initCfgInfo.strInitPath = srcPath;

		return true;
	}
	return false;	
}
bool CMNFileManager::SaveInitConfigFile(char* _path)
{
	FILE* fp = 0;
	fopen_s(&fp, _path, "wb");

	char srcPath[256];
	memset(srcPath, 0x00, sizeof(256));
	if (fp) {
		SYSTEMTIME st;
		GetSystemTime(&st);
		sprintf_s(srcPath, sizeof(srcPath), m_initCfgInfo.strInitPath.c_str(), fp);

		fwrite(&st, sizeof(SYSTEMTIME), 1, fp);
		fwrite(srcPath, 256, 1, fp);
		fclose(fp);

		return true;
	}
	return false;
}