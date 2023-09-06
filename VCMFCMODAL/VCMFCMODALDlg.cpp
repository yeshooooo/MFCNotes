
// VCMFCMODALDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "VCMFCMODAL.h"
#include "VCMFCMODALDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CVCMFCMODALDlg dialog



CVCMFCMODALDlg::CVCMFCMODALDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_VCMFCMODAL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CVCMFCMODALDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CVCMFCMODALDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CVCMFCMODALDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CVCMFCMODALDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CVCMFCMODALDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CVCMFCMODALDlg message handlers

BOOL CVCMFCMODALDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	pMainDlg = this;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CVCMFCMODALDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CVCMFCMODALDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


#include "CMTDialog.h"
void CVCMFCMODALDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CMTDialog dlg;
	dlg.DoModal();
}

// 创建非模态对话框

//#include "CFMTDialog.h"
// CFMTDialog dlg; // 这里要设置为全局变量，不然对话框会一闪而过，被自动回收
void CVCMFCMODALDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	//CFMTDialog* pFMTDlg = new CFMTDialog(); // 在堆中创建对象，也可以防止被自动销毁
// 	
// 	BOOL bRet = pFMTDlg->Create(IDD_DIALOG2); // 不同于模态对话框，这里要输入对话框ID
// 
// 	if (bRet)
// 	{
// 		pFMTDlg->ShowWindow(SW_SHOW);
// 	}
	// 把父窗口指针传给子窗口成员
	m_ChildDlg.m_pParentDlg = this; 
	BOOL bRet = m_ChildDlg.Create(IDD_DIALOG2);
	if (bRet)
	{
		m_ChildDlg.SetDlgItemTextW(IDC_EDIT1, TEXT("我是被父窗口设置的字符串"));
		m_ChildDlg.ShowWindow(SW_SHOW);
	}
}

CVCMFCMODALDlg* pMainDlg = NULL;

// 类外函数
// 参数传递方式
void GetEditText(CWnd* pDlgWnd)
{
	// 获得主对话框上编辑框的文本
	CString str;
	pDlgWnd->GetDlgItemTextW(IDC_EDIT1, str);
	MessageBox(NULL, str, TEXT("Title"), MB_OKCANCEL);
	
	// 额外补充
	HWND hDlg = pDlgWnd->GetSafeHwnd(); // 获取窗口句柄
	CWnd* pWnd = CWnd::FromHandle(hDlg); //有了窗口句柄后获取获取CWnd*
}
void CVCMFCMODALDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	GetEditText(this);

}
