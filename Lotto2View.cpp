// Lotto2View.cpp : CLotto2View Ŭ������ ����
//

#include "stdafx.h"
#include "Lotto2.h"

#include "Lotto2Doc.h"
#include "Lotto2View.h"

#include <time.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLotto2View

IMPLEMENT_DYNCREATE(CLotto2View, CView)

BEGIN_MESSAGE_MAP(CLotto2View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CLotto2View ����/�Ҹ�

CLotto2View::CLotto2View()
: Count(0)
, xpoint(0)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CLotto2View::~CLotto2View()
{
}

BOOL CLotto2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

void CLotto2View::Wait(DWORD dwMillisecond)
{
	MSG msg;
	DWORD dwStart;
	dwStart=GetTickCount();

	while(GetTickCount()-dwStart<dwMillisecond) {
		while(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}

// CLotto2View �׸���

void CLotto2View::OnDraw(CDC* pDC)
{
	CLotto2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	GetClientRect(&rect);
	Inv=1;
	if(!Count) {
		MemDC.CreateCompatibleDC(pDC);
		for(int i=0; i<45; i++) {
			largeBmp[i].LoadBitmapW(IDB_BITMAP1+i);
			smallBmp[i].LoadBitmapW(IDB_BITMAP46+i);
		}
		start.LoadBitmapW(IDB_START);
		pOldBitmap=(CBitmap *)MemDC.SelectObject(&start);
		pDC->BitBlt(rect.Width()/2-100, rect.Height()/2-100, 200, 200, &MemDC, 0, 0, SRCCOPY);

		srand(time(NULL));
		Change=2; //0�� 1�� �ƴ� ������ ��
		Move=0;
	} else if(Count<8) {
		int RandNum;

		if((Inv==1)&&(Change==0)&&(Move==0)) {
			for(int i=0, xp=0; i<Count; i++, xp++) {
				MemDC.SelectObject(&smallBmp[LottoNum[i]-1]);
				if(xp==6) {
					CFont plusFont, *pOldFont;
					plusFont.CreateFontW(50, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, _T("����ü"));
					pOldFont=pDC->SelectObject(&plusFont);
					pDC->TextOutW(650, 25, _T("+"));
					pDC->SelectObject(pOldFont);
					plusFont.DeleteObject();
					xp++;}
				pDC->BitBlt(xp*100, 0, 100, 100, &MemDC, 0, 0, SRCCOPY);
			}
			MemDC.SelectObject(&largeBmp[LottoNum[Count-1]-1]);
			pDC->BitBlt(rect.Width()/2-100, rect.Height()/2-100, 200, 200, &MemDC, 0, 0, SRCCOPY);
			Inv=0;
		}

		while(Change==1){
again:;
			RandNum=rand()%45+1;
			for(int i=0; i<Count; i++)
				if(LottoNum[i]==RandNum) goto again;
			MemDC.SelectObject(&largeBmp[RandNum-1]);
			LottoNum[Count-1]=RandNum;
			pDC->BitBlt(rect.Width()/2-100, rect.Height()/2-100, 200, 200, &MemDC, 0, 0, SRCCOPY);
			Wait(50);
		}

		if(xpoint==7) {
			CFont plusFont, *pOldFont;
			plusFont.CreateFontW(50, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, _T("����ü"));
			pOldFont=pDC->SelectObject(&plusFont);
			pDC->TextOutW(650, 25, _T("+"));
			pDC->SelectObject(pOldFont);
			plusFont.DeleteObject();
			xpoint++;
		}

		if(Move>0) {
			if(Move==1) {
				mPoint.x=rect.Width()/2;
				mPoint.y=rect.Height()/2-150;
				MemDC.SelectObject(&largeBmp[LottoNum[Count-1]-1]);
				pDC->BitBlt(rect.Width()/2-100, rect.Height()/2-100, 200, 200, &MemDC, 0, 0, SRCCOPY);
				Move++;
			}
			for(int i=1, xp=0; i<Count; i++, xp++) {
				MemDC.SelectObject(&smallBmp[LottoNum[i-1]-1]);
				if(xp==6) xp++;
				pDC->BitBlt(xp*100, 0, 100, 100, &MemDC, 0, 0, SRCCOPY);
			}
			MemDC.SelectObject(&smallBmp[LottoNum[Count-1]-1]);
			CRect Invrect(mPoint.x-52, mPoint.y-52, mPoint.x+52, mPoint.y+50);
			pDC->BitBlt(mPoint.x-50, mPoint.y-50, 100, 100, &MemDC, 0, 0, SRCCOPY);
			Wait(10);
			if(mPoint.y==50) {
				Move=0;
				Change=0;
				Inv=1;
				InvalidateRect(Invrect);
			}
			else if(mPoint.y>150) {
				mPoint.y--;
				InvalidateRect(Invrect);
			}
			else if(mPoint.x>(xpoint*100)-50) {
				mPoint.x--;
				InvalidateRect(Invrect);
			}
			else if(mPoint.x<(xpoint*100)-50) {
				mPoint.x++;
				InvalidateRect(Invrect);
			}
			else {
				mPoint.y--;
				InvalidateRect(Invrect);
			}
		}
	} else if(Count==9) {
		MemDC.SelectObject(&pOldBitmap);
		for(int i=0; i<45; i++) {
			largeBmp[i].DeleteObject();
			smallBmp[i].DeleteObject();
		}
		start.DeleteObject();
	}
}


// CLotto2View �μ�

BOOL CLotto2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CLotto2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CLotto2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CLotto2View ����

#ifdef _DEBUG
void CLotto2View::AssertValid() const
{
	CView::AssertValid();
}

void CLotto2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLotto2Doc* CLotto2View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLotto2Doc)));
	return (CLotto2Doc*)m_pDocument;
}
#endif //_DEBUG


// CLotto2View �޽��� ó����

void CLotto2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	Count++;
	xpoint++;
	Change=1;

	CRect icrect(rect.Width()/2-100, rect.Height()/2-100, rect.Width()/2+100, rect.Height()/2+100);

	InvalidateRect(icrect);

	CView::OnLButtonDown(nFlags, point);
}

void CLotto2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	Change=0;
	Move=1;
	Inv=0;

	Invalidate();

	CView::OnLButtonUp(nFlags, point);
}
