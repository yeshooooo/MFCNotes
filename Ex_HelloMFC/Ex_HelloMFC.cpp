// #include <afxwin.h>
// 
// // 声明应用程序类
// class CHelloApp : public CWinApp
// {
// public:
// 	virtual BOOL InitInstance();
// };
// // 建立应用程序类的实例
// CHelloApp theApp;
// 
// // 声明主窗口类
// class CMainFrame : public CFrameWnd
// {
// public:
// 	CMainFrame()
// 	{
// 		// 创建主窗口
// 		Create(NULL, TEXT("我的窗口"), WS_OVERLAPPEDWINDOW, CRect(0, 0, 480, 320));
// 
// 	}
// protected:
// 	afx_msg void OnPaint();
// 	DECLARE_MESSAGE_MAP();
// };
// 
// // 消息映射入口
// BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
// 	ON_WM_PAINT() // 绘制消息宏
// END_MESSAGE_MAP()
// 
// // 定义消息映射函数
// void CMainFrame::OnPaint()
// {
// 	CPaintDC	 dc(this);
// 	CRect rc;
// 	GetClientRect(&rc);
// 	dc.DrawText(TEXT("Hello MFC!"), -1, &rc, 
// 		DT_SINGLELINE | DT_CENTER | DT_VCENTER);
// }
// 
// // 每当应用程序首次执行时都要调用的初始化函数
// BOOL CHelloApp::InitInstance()
// {
// 	m_pMainWnd = new CMainFrame();
// 	m_pMainWnd->ShowWindow(m_nCmdShow);
// 	m_pMainWnd->UpdateWindow();
// 	return TRUE;
// }
// 
// 

#include "Ex_HelloMFC.h"
CHelloApp theApp;
BOOL CHelloApp::InitInstance()
{
	m_pMainWnd = new CMainFrame();

}

CMainFrame::CMainFrame()
{

}
