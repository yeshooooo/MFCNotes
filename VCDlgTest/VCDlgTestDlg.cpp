
// VCDlgTestDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "VCDlgTest.h"
#include "VCDlgTestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CVCDlgTestDlg dialog



CVCDlgTestDlg::CVCDlgTestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_VCDLGTEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CVCDlgTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_List);
}

BEGIN_MESSAGE_MAP(CVCDlgTestDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON3, &CVCDlgTestDlg::OnBnClickedButton3)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CVCDlgTestDlg::OnLvnItemchangedList1)
END_MESSAGE_MAP()


// CVCDlgTestDlg message handlers

BOOL CVCDlgTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CVCDlgTestDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CVCDlgTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CVCDlgTestDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	
	// 弹出新加载的模态对话框
	CDialog dlg(IDD_DIALOG1);
	dlg.DoModal();



	// 这里的MessageBox是win32的封装，他是CWnd里的
	MessageBox(TEXT("这是我在VC驿站学习的第一个对话框程序！"));

	//List Control添加一列
	m_List.InsertColumn(0, _T("我是第0列"));
	m_List.InsertItem(0, TEXT("aaa"));

	CFile mFile;
	mFile.Open(_T("D:\\123.txt"), CFile::modeCreate | CFile::modeReadWrite);
	mFile.Write("123", 3); // 这里不能用宽字符，否则写不全
	mFile.Close();
}


void CVCDlgTestDlg::OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}
