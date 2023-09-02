#include <afxwin.h>

/*
* 1.MFC程序有一个全局应用对象，集成自CWinApp实现InitInstance，本示例是theApp对象，他是CWinApp派生类的对象，
* 该对象代表了应用进程的主线程。
* 2. CFrameWnd往往用于创建应用程序的主窗口
* 3. WinApp的成员指针m_pMainWnd指向窗口CFrameWnd
*
* afxwin.h 是MFC程序非常重要的头文件，CWinThread,CWinApp,CWnd等类都在此头文件中， 它还会包含windows.h头文件，最好保证该句
* 在头文件首行。
*/

class MyApp : public CWinApp
{
	// 程序入口点
	virtual BOOL InitInstance()
	{
		CFrameWnd* pWnd = new CFrameWnd;
		pWnd->Create(NULL, L"Hello World!");
		pWnd->ShowWindow(SW_SHOW);
		m_pMainWnd = pWnd;
		return true;
	}

};

MyApp theApp;