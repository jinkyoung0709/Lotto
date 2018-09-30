// Lotto2Doc.cpp : CLotto2Doc 클래스의 구현
//

#include "stdafx.h"
#include "Lotto2.h"

#include "Lotto2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLotto2Doc

IMPLEMENT_DYNCREATE(CLotto2Doc, CDocument)

BEGIN_MESSAGE_MAP(CLotto2Doc, CDocument)
END_MESSAGE_MAP()


// CLotto2Doc 생성/소멸

CLotto2Doc::CLotto2Doc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CLotto2Doc::~CLotto2Doc()
{
}

BOOL CLotto2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CLotto2Doc serialization

void CLotto2Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}


// CLotto2Doc 진단

#ifdef _DEBUG
void CLotto2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CLotto2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CLotto2Doc 명령
