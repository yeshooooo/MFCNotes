/*
* CWinApp��ĳ�Ա������ 
* InitApplication ��ʼ������
* InitInstance ���������Դ������ڶ��󣬸�ֵm_pMainWnd ���̳���CWinThread��Ա�����������
* Run ������Ϣѭ��(һ�㲻��д) ���̳���CWinThread��Ա�����������
* OnIdle �߳̿���ʱ������ ���̳���CWinThread��Ա�����������
* ExitInstance �߳���ֹʱ������ ���̳���CWinThread��Ա�����������
* LoadCursor ���ع��
* LoadIcon ����ͼ��
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
		// ��Щֵ����WinMain������ֵ��theApp
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

// ����ȫ��ΨһӦ�ó���ʵ��
MyApp theApp;