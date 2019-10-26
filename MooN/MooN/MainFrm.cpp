
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "MooN.h"

#include "MainFrm.h"
#include "CMNFileManager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWndEx)

const int  iMaxUserToolbars = 10;
const UINT uiFirstUserToolBarId = AFX_IDW_CONTROLBAR_FIRST + 40;
const UINT uiLastUserToolBarId = uiFirstUserToolBarId + iMaxUserToolbars - 1;

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWndEx)
	ON_WM_CREATE()
	ON_COMMAND(ID_FILE_OPEN_FOLDER, &CMainFrame::OnFileOpenFolder)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame construction/destruction

CMainFrame::CMainFrame() noexcept
{
	// TODO: add member initialization code here	
}

CMainFrame::~CMainFrame()
{
	CloseMooN();
	SINGLETON_FileMng::Destory();
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWndEx::OnCreate(lpCreateStruct) == -1)
		return -1;

//	BOOL bNameValid;

	if (!m_wndMenuBar.Create(this))
	{
		TRACE0("Failed to create menubar\n");
		return -1;      // fail to create
	}

	if (!m_wndFileView.Create(L"File Window", this, CRect(0, 0, 400, 400), TRUE, 0x01, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_LEFT))
	{
		TRACE0("Failed to create File View window\n");
		return FALSE; // failed to create
	}
	if (!m_wndOutput.Create(L"   Output   ", this, CRect(0, 0, 200, 200), TRUE, 0x02, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_BOTTOM))
	{
		TRACE0("Failed to create Output window\n");
		return FALSE; // failed to create
	}

	if (!m_wndFromUI.Create(L"   Setting   ", this, CRect(0, 0, 200, 200), TRUE, 0x03, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CBRS_BOTTOM))
	{
		TRACE0("Failed to create Output window\n");
		return FALSE; // failed to create
	}

	DWORD dwStyle = ~(AFX_CBRS_CLOSE | AFX_CBRS_FLOAT);
//	CTabbedPane* pTabbedPane = m_wndFileView.CreateTabbedPane();
	m_wndFileView.SetControlBarStyle(dwStyle);
	m_wndFileView.RecalcLayout();
	m_wndOutput.SetControlBarStyle(dwStyle);
	m_wndOutput.RecalcLayout();

	m_wndFromUI.SetControlBarStyle(dwStyle);
	m_wndFromUI.RecalcLayout();

//	m_wndMenuBar.SetPaneStyle(m_wndMenuBar.GetPaneStyle() | CBRS_SIZE_DYNAMIC | CBRS_TOOLTIPS | CBRS_FLYBY);

	// prevent the menu bar from taking the focus on activation
	CMFCPopupMenu::SetForceMenuFocus(FALSE);


	//if (!m_wndStatusBar.Create(this))
	//{
	//	TRACE0("Failed to create status bar\n");
	//	return -1;      // fail to create
	//}
	//m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));
//	OnApplicationLook(theApp.m_nAppLook);


	m_wndMenuBar.EnableDocking(CBRS_ALIGN_ANY);
	m_wndFileView.EnableDocking(CBRS_ALIGN_ANY);
	m_wndOutput.EnableDocking(CBRS_ALIGN_ANY);
	m_wndFromUI.EnableDocking(CBRS_ALIGN_ANY);
	
	EnableDocking(CBRS_ALIGN_ANY);

	DockPane(&m_wndFileView);

	DockPane(&m_wndMenuBar);
	DockPane(&m_wndOutput);
	CDockablePane* pTabbedBar = NULL;	
	m_wndFromUI.AttachToTabWnd(&m_wndOutput, DM_SHOW, FALSE, &pTabbedBar);



//	CWaitCursor wait;
//	theApp.m_nAppLook = id;
	CMFCVisualManagerOffice2007::SetStyle(CMFCVisualManagerOffice2007::Office2007_Silver);
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerOffice2007));
	CDockingManager::SetDockingMode(DT_SMART);
	RedrawWindow(nullptr, nullptr, RDW_ALLCHILDREN | RDW_INVALIDATE | RDW_UPDATENOW | RDW_FRAME | RDW_ERASE);


	   	 
	InitMooN();
	return 0;
}

void CMainFrame::InitMooN()
{
	// Initialize MooN //
	CString sPath;
	GetModuleFileName(nullptr, sPath.GetBuffer(_MAX_PATH + 1), _MAX_PATH);
	sPath.ReleaseBuffer();
	CString path = sPath.Left(sPath.ReverseFind(_T('\\')));
	CString strCfgFle = path + "\\userdata\\conf.bin";


	// Folder Check================ //
	CString strfolder = path + "\\userdata";
	if (PathFileExists(strfolder) == 0) {
		CreateDirectory(strfolder, NULL);
	}

	char* cfgPath = new char[256];
	memset(cfgPath, 0x00, 256);
	SINGLETON_FileMng::GetInstance()->CStringToChar(strCfgFle, cfgPath, 256);	
	//CStringA tmpStr = CStringA(strCfgFle);
	//const char* st = tmpStr;
	//char*_pt = const_cast<char*>(st);

	if (SINGLETON_FileMng::GetInstance()->LoadInitConfigFile(cfgPath)) {
		CString strCfg = (CString)SINGLETON_FileMng::GetInstance()->GetInitCfgInfo().strInitPath.c_str();
		if(strCfg != L"")
			m_wndFileView.FillFileView(strCfg);
	}

	delete[] cfgPath;
}

void CMainFrame::CloseMooN()
{
	CString sPath;
	GetModuleFileName(nullptr, sPath.GetBuffer(_MAX_PATH + 1), _MAX_PATH);
	sPath.ReleaseBuffer();
	CString path = sPath.Left(sPath.ReverseFind(_T('\\')));
	CString strCfgFle = path + "\\userdata\\conf.bin";

	char* cfgPath = new char[256];
	memset(cfgPath, 0x00, 256);
	SINGLETON_FileMng::GetInstance()->CStringToChar(strCfgFle, cfgPath, 256);
	SINGLETON_FileMng::GetInstance()->SaveInitConfigFile(cfgPath);

	delete[] cfgPath;
}


BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWndEx::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWndEx::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWndEx::Dump(dc);
}
#endif //_DEBUG



BOOL CMainFrame::LoadFrame(UINT nIDResource, DWORD dwDefaultStyle, CWnd* pParentWnd, CCreateContext* pContext)
{
	// base class does the real work
	if (!CFrameWndEx::LoadFrame(nIDResource, dwDefaultStyle, pParentWnd, pContext))
	{
		return FALSE;
	}

	return TRUE;
}



void CMainFrame::OnFileOpenFolder()
{
	// TODO: Add your command handler code here
	CString strInitPath = L"";
	_mnInitCfg initCfg = SINGLETON_FileMng::GetInstance()->GetInitCfgInfo();
	if (initCfg.strInitPath != "") {
		strInitPath = CStringA(initCfg.strInitPath.c_str());
	}
	else {
		strInitPath = L"C:\\";
	}

	// 폴더 선택 다이얼로그
	CFolderPickerDialog Picker(strInitPath, OFN_FILEMUSTEXIST, NULL, 0);
	if (Picker.DoModal() == IDOK)
	{
		// 선택된 폴더 경로얻음
		CString strFolderPath = Picker.GetPathName();
		m_wndFileView.FillFileView(strFolderPath);

		initCfg.strInitPath = CStringA(strFolderPath);
		SINGLETON_FileMng::GetInstance()->SetInitCfgInfo(initCfg);		
	}
}
