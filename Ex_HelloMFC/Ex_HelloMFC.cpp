// #include <afxwin.h>
// 
// // ����Ӧ�ó�����
// class CHelloApp : public CWinApp
// {
// public:
// 	virtual BOOL InitInstance();
// };
// // ����Ӧ�ó������ʵ��
// CHelloApp theApp;
// 
// // ������������
// class CMainFrame : public CFrameWnd
// {
// public:
// 	CMainFrame()
// 	{
// 		// ����������
// 		Create(NULL, TEXT("�ҵĴ���"), WS_OVERLAPPEDWINDOW, CRect(0, 0, 480, 320));
// 
// 	}
// protected:
// 	afx_msg void OnPaint();
// 	DECLARE_MESSAGE_MAP();
// };
// 
// // ��Ϣӳ�����
// BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
// 	ON_WM_PAINT() // ������Ϣ��
// END_MESSAGE_MAP()
// 
// // ������Ϣӳ�亯��
// void CMainFrame::OnPaint()
// {
// 	CPaintDC	 dc(this);
// 	CRect rc;
// 	GetClientRect(&rc);
// 	dc.DrawText(TEXT("Hello MFC!"), -1, &rc, 
// 		DT_SINGLELINE | DT_CENTER | DT_VCENTER);
// }
// 
// // ÿ��Ӧ�ó����״�ִ��ʱ��Ҫ���õĳ�ʼ������
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
