// Lotto2Doc.h : CLotto2Doc Ŭ������ �������̽�
//


#pragma once


class CLotto2Doc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CLotto2Doc();
	DECLARE_DYNCREATE(CLotto2Doc)

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// �����Դϴ�.
public:
	virtual ~CLotto2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
};


