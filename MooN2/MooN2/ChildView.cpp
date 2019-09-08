
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "MooN2.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
	ON_WM_CREATE()
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	wglMakeCurrent(m_hDC, m_hRC);
	GLRenderScene();
	SwapBuffers(m_hDC);
	wglMakeCurrent(m_hDC, NULL);
	
	// Do not call CWnd::OnPaint() for painting messages
}


BOOL CChildView::GLInitialzation()
{
	int nPixelFormat;
	m_hDC = ::GetDC(m_hWnd);

	static PIXELFORMATDESCRIPTOR pfd =
	{
	 sizeof(PIXELFORMATDESCRIPTOR),
	 1,
	 PFD_DRAW_TO_WINDOW |
	 PFD_SUPPORT_OPENGL |
	 PFD_DOUBLEBUFFER,
	 PFD_TYPE_RGBA,
	 24,
	 0,0,0,0,0,0,
	 0,0,
	 0,0,0,0,0,
	 32,
	 0,
	 0,
	 PFD_MAIN_PLANE,
	 0,
	 0,0,0
	};
	nPixelFormat = ChoosePixelFormat(m_hDC, &pfd);
	VERIFY(SetPixelFormat(m_hDC, nPixelFormat, &pfd));
	m_hRC = wglCreateContext(m_hDC);
	VERIFY(wglMakeCurrent(m_hDC, m_hRC));
	wglMakeCurrent(NULL, NULL);


	glClearDepth(1.0f);								// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);						// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);						    // The Type Of Depth Testing To Do

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);					// Type Of Blending To Perform
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations

	glShadeModel(GL_SMOOTH);
	glDisable(GL_LIGHTING);

	return TRUE;
}
void CChildView::GLRenderScene()
{
	
	glClearColor(0.5f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	
	m_glLayer3D.Render();

	
	//glEnable(GL_DEPTH_TEST); // ±íÀÌ Å×½ºÆ® On

	//glLoadIdentity();
	//gluLookAt(0.0f, 0.0f, 1000.0f, 0.0f, 10.f, 0.0f, 0.0f, 1.0f, 0.0f);

	//glColor3f(1.0f, 1.0f, 1.0f);
	//glBegin(GL_QUADS);
	//glVertex3f(-50, -50, 0);
	//glVertex3f(50, -50, 0);
	//glVertex3f(50, 50, 0);
	//glVertex3f(-50, 50, 0);
	//glEnd();

	glFlush();
}


void CChildView::GLResize(int cx, int cy)
{
	GLfloat fAspect;
	if (cy == 0)		cy = 1;

	glViewport(0, 0, cx, cy);    
	fAspect = (GLfloat)cx / (GLfloat)cy;

	glMatrixMode(GL_PROJECTION);   
	glLoadIdentity();

	gluPerspective(60.0f, fAspect, 1.0f, 10000.0f);  

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void CChildView::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	VERIFY(wglMakeCurrent(m_hDC, m_hRC));
	GLResize(cx, cy);
	VERIFY(wglMakeCurrent(NULL, NULL));
}


BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default

	return TRUE;
}


int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	GLInitialzation();

	return 0;
}
