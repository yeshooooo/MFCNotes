
// Demo3.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CDemo3App:
// See Demo3.cpp for the implementation of this class
//

class CDemo3App : public CWinApp
{
public:
	CDemo3App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CDemo3App theApp;
