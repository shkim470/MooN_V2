// FormUIView.cpp : implementation file
//

#include "stdafx.h"
#include "MooN.h"
#include "FormUIView.h"


// CFormUIView

IMPLEMENT_DYNAMIC(CFormUIView, CDockablePane)

CFormUIView::CFormUIView()
{
	m_uiView = NULL;
}

CFormUIView::~CFormUIView()
{
}


BEGIN_MESSAGE_MAP(CFormUIView, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()



// CFormUIView message handlers




int CFormUIView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	m_uiView = new CFormDLUI;
	if (!m_uiView->Create(NULL, NULL, WS_CHILD | WS_VISIBLE, CRect(0, 0, 300, 300), this, 0, NULL))
	{
		AfxMessageBox(_T("Failed in creating CMyFormView"));
	}

	return 0;
}


void CFormUIView::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	if (m_uiView)
		m_uiView->SetWindowPos(NULL, 0, 0, cx, cy, SWP_NOZORDER);
}
