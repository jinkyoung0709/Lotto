// Lotto2.h : Lotto2 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CLotto2App:
// �� Ŭ������ ������ ���ؼ��� Lotto2.cpp�� �����Ͻʽÿ�.
//

class CLotto2App : public CWinApp
{
public:
	CLotto2App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CLotto2App theApp;