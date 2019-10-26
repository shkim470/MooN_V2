#pragma once
#include <afxext.h>
class CFormDLUI :	public CFormView
{
	DECLARE_DYNCREATE(CFormDLUI)
public:
	CFormDLUI();
	virtual ~CFormDLUI();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	afx_msg void OnBnClickedBnTest();
};

