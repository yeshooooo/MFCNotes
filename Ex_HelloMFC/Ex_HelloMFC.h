#pragma once

#include <afxwin.h>

// 主程序类
class CHelloApp : public CWinApp
{
public:
	// 程序入口
	virtual BOOL InitInstance();
};

class CMainFrame : public CFrameWnd
{
public:
	CMainFrame();
};