// Lotto2View.h : CLotto2View Ŭ������ �������̽�
//


#pragma once


class CLotto2View : public CView
{
protected: // serialization������ ��������ϴ�.
	CLotto2View();
	DECLARE_DYNCREATE(CLotto2View)

// Ư���Դϴ�.
public:
	CLotto2Doc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CLotto2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	CBitmap smallBmp[45], largeBmp[45], start, *pOldBitmap;
	int Count, Change, Move, LottoNum[7], Inv;
	CRect rect;
	CDC MemDC;
	void Wait(DWORD dwMillisecond);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	int xpoint;
	CPoint mPoint;
};

#ifndef _DEBUG  // Lotto2View.cpp�� ����� ����
inline CLotto2Doc* CLotto2View::GetDocument() const
   { return reinterpret_cast<CLotto2Doc*>(m_pDocument); }
#endif

