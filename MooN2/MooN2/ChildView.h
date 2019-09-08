
// ChildView.h : interface of the CChildView class
//


#pragma once
#include <gl/gl.h>
#include <gl/glu.h>

#include "GLLayer3D.h"
#include "GLLayer2D.h"


// CChildView window

class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
public:
	HGLRC m_hRC;
	HDC   m_hDC;

private:
	CGLLayer3D m_glLayer3D;
//	CGLLayer2D m_glLayer2D;

// Operations
public:
	void GLResize(int cx, int cy);
	void GLRenderScene();
	BOOL GLInitialzation();

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

