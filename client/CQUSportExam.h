
// CQUSportExam.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCQUSportExamApp:
// �йش����ʵ�֣������ CQUSportExam.cpp
//

class CCQUSportExamApp : public CWinApp
{
public:
	CCQUSportExamApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CCQUSportExamApp theApp;