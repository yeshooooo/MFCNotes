/*
* CWinApp类的成员方法： 
* InitApplication 初始化工作
* InitInstance 必须重载以创建窗口对象，赋值m_pMainWnd （继承自CWinThread成员方法与变量）
* Run 重载消息循环(一般不重写) （继承自CWinThread成员方法与变量）
* OnIdle 线程空闲时被调用 （继承自CWinThread成员方法与变量）
* ExitInstance 线程终止时被调用 （继承自CWinThread成员方法与变量）
* LoadCursor 加载光标
* LoadIcon 加载图标
* 
*/

#include <afxwin.h>


class MyApp : public CWinApp
{
	virtual BOOL InitApplication() {
		return CWinApp::InitApplication();
	}

	virtual int Run()
	{
		return CWinApp::Run();

	}
	virtual BOOL OnIdle(LONG lCount)
	{
		return CWinApp::OnIdle(lCount);
	}

	virtual int ExitInstance()
	{
		return CWinApp::ExitInstance();
	}
	virtual BOOL InitInstance()
	{
		/*
		// 这些值均由WinMain函数赋值给theApp
		HINSTANCE hInstance = this->m_hInstance;
		LPTSTR lpCmdLine = this->m_lpCmdLine;
		int nCmdShow = this->m_nCmdShow;
		LPCTSTR pszExeName = this->m_pszExeName;
		LPCTSTR pszAppName = this->m_pszAppName;
		CWnd* pWnd = this->m_pMainWnd;
		return false;
		*/

		CFrameWnd* pWnd = new CFrameWnd;
		pWnd->Create(NULL, L"Hello");
		pWnd->ShowWindow(SW_SHOW);

		this->m_pMainWnd = pWnd;

		return TRUE;
		
	}
};

// 启动全局唯一应用程序实例
MyApp theApp;