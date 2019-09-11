
// MooNView.h : interface of the CMooNView class
//

#pragma once
#include <gl/gl.h>
#include <gl/glu.h>

#include "GLLayer3D.h"

class CMooNView : public CView
{
protected: // create from serialization only
	CMooNView() noexcept;
	DECLARE_DYNCREATE(CMooNView)

// Attributes
public:
	CMooNDoc* GetDocument() const;

// Operations
public:

private:

	HGLRC m_hRC;
	HDC   m_hDC;
	CGLLayer3D m_layer3D;

	// GL Operations
	void GLResize(int cx, int cy);
	void GLRenderScene();
	BOOL GLInitialzation();


// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMooNView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

#ifndef _DEBUG  // debug version in MooNView.cpp
inline CMooNDoc* CMooNView::GetDocument() const
   { return reinterpret_cast<CMooNDoc*>(m_pDocument); }
#endif

