
// MooNView.cpp : implementation of the CMooNView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MooN.h"
#endif

#include "MooNDoc.h"
#include "MooNView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMooNView

IMPLEMENT_DYNCREATE(CMooNView, CView)

BEGIN_MESSAGE_MAP(CMooNView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMooNView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_ERASEBKGND()
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()

// CMooNView construction/destruction

CMooNView::CMooNView() noexcept
{
	// TODO: add construction code here

}

CMooNView::~CMooNView()
{
}

BOOL CMooNView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs


	return CView::PreCreateWindow(cs);
}

// CMooNView drawing

void CMooNView::OnDraw(CDC* /*pDC*/)
{
	//CMooNDoc* pDoc = GetDocument();
	//ASSERT_VALID(pDoc);
	//if (!pDoc)
	//	return;

	// TODO: add draw code for native data here
	wglMakeCurrent(m_hDC, m_hRC);
	GLRenderScene();
	SwapBuffers(m_hDC);
	wglMakeCurrent(m_hDC, NULL);
}


// CMooNView printing


void CMooNView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMooNView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMooNView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMooNView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMooNView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMooNView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMooNView diagnostics

#ifdef _DEBUG
void CMooNView::AssertValid() const
{
	CView::AssertValid();
}

void CMooNView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

//CMooNDoc* CMooNView::GetDocument() const // non-debug version is inline
//{
//	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMooNDoc)));
//	return (CMooNDoc*)m_pDocument;
//}
#endif //_DEBUG


// CMooNView message handlers





// Init OpenGL View
void CMooNView::GLResize(int cx, int cy)
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
void CMooNView::GLRenderScene()
{
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	m_layer3D.Render();

	glFlush();
}
BOOL CMooNView::GLInitialzation()
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

BOOL CMooNView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default

	return TRUE;
}


int CMooNView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	GLInitialzation();

	return 0;
}


void CMooNView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	VERIFY(wglMakeCurrent(m_hDC, m_hRC));
	GLResize(cx, cy);
	VERIFY(wglMakeCurrent(NULL, NULL));
}
