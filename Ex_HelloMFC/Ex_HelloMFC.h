#pragma once

#include <afxwin.h>

// ��������
class CHelloApp : public CWinApp
{
public:
	// �������
	virtual BOOL InitInstance();
};

class CMainFrame : public CFrameWnd
{
public:
	CMainFrame();
};