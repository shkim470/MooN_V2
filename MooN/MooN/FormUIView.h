#pragma once
#include "CFormDLUI.h"

// CFormUIView

class CFormUIView : public CDockablePane
{
	DECLARE_DYNAMIC(CFormUIView)

private:
	CFormDLUI* m_uiView;

public:
	CFormUIView();
	virtual ~CFormUIView();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};


