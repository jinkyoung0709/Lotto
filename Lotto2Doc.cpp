// Lotto2Doc.cpp : CLotto2Doc Ŭ������ ����
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


// CLotto2Doc ����/�Ҹ�

CLotto2Doc::CLotto2Doc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

}

CLotto2Doc::~CLotto2Doc()
{
}

BOOL CLotto2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}




// CLotto2Doc serialization

void CLotto2Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
	}
}


// CLotto2Doc ����

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


// CLotto2Doc ���
