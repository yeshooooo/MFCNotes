
// MFCTest01.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMFCTest01App:
// See MFCTest01.cpp for the implementation of this class
//

class CMFCTest01App : public CWinApp
{
public:
	CMFCTest01App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMFCTest01App theApp;
