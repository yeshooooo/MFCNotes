#include <afxwin.h>

/*
* 1.MFC������һ��ȫ��Ӧ�ö��󣬼�����CWinAppʵ��InitInstance����ʾ����theApp��������CWinApp������Ķ���
* �ö��������Ӧ�ý��̵����̡߳�
* 2. CFrameWnd�������ڴ���Ӧ�ó����������
* 3. WinApp�ĳ�Աָ��m_pMainWndָ�򴰿�CFrameWnd
*
* afxwin.h ��MFC����ǳ���Ҫ��ͷ�ļ���CWinThread,CWinApp,CWnd���඼�ڴ�ͷ�ļ��У� ���������windows.hͷ�ļ�����ñ�֤�þ�
* ��ͷ�ļ����С�
*/

class MyApp : public CWinApp
{
	// ������ڵ�
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