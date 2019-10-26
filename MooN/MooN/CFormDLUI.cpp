#include "stdafx.h"
#include "MooN.h"
#include "CFormDLUI.h"

IMPLEMENT_DYNCREATE(CFormDLUI, CFormView)
CFormDLUI::CFormDLUI()
	: CFormView(IDD_FORM_UI)
{
}


CFormDLUI::~CFormDLUI()
{
}

void CFormDLUI::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFormDLUI, CFormView)
	ON_BN_CLICKED(IDC_BN_TEST, &CFormDLUI::OnBnClickedBnTest)
END_MESSAGE_MAP()


BOOL CFormDLUI::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	// TODO: Add your specialized code here and/or call the base class

	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}


void CFormDLUI::OnBnClickedBnTest()
{
	// TODO: Add your control notification handler code here
	AfxMessageBox(L"Click");
}
