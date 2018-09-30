// Lotto2View.h : CLotto2View 클래스의 인터페이스
//


#pragma once


class CLotto2View : public CView
{
protected: // serialization에서만 만들어집니다.
	CLotto2View();
	DECLARE_DYNCREATE(CLotto2View)

// 특성입니다.
public:
	CLotto2Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CLotto2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
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

#ifndef _DEBUG  // Lotto2View.cpp의 디버그 버전
inline CLotto2Doc* CLotto2View::GetDocument() const
   { return reinterpret_cast<CLotto2Doc*>(m_pDocument); }
#endif

