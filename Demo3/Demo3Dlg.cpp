
// Demo3Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Demo3.h"
#include "Demo3Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDemo3Dlg dialog



CDemo3Dlg::CDemo3Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DEMO3_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDemo3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDemo3Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CDemo3Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDemo3Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CDemo3Dlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CDemo3Dlg message handlers

BOOL CDemo3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDemo3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDemo3Dlg::OnPaint()
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
HCURSOR CDemo3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


// ����1��GetDlgItem 
void CDemo3Dlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	// 
	CString str1, str2, str3;

	GetDlgItem(IDC_EDIT1)->GetWindowTextW(str1);
	GetDlgItem(IDC_EDIT2)->GetWindowTextW(str2);
	GetDlgItem(IDC_EDIT3)->GetWindowTextW(str3);

	int a, b, c;

	// �ַ�תint
	a = _wtoi(str1.GetBuffer()); // Ĭ����unicode�ַ�����_wtoi��ת��
	b = _wtoi(str2.GetBuffer());
	c = a + b;

	// int תCString
	CString strint;
	strint.Format(L"%d", c);

	GetDlgItem(IDC_EDIT3)->SetWindowTextW(strint);
}

// ����2�� GetDlgItemText��SetDlgItemText
void CDemo3Dlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here

	int a, b, c;
	TCHAR c1[10], c2[10], c3[10];
	GetDlgItemText(IDC_EDIT1, c1, 10);
	GetDlgItemText(IDC_EDIT2, c2, 10);
	a = _ttoi(c1); // TCHAR תint
	b = _ttoi(c2);

	c = a + b;

	// ��int ת�����ַ���
	_itot_s(c, c3, 10);
	SetDlgItemText(IDC_EDIT3, c3);
}

// ����3�������ڷ���1��ֻ����������ֵ�ı������Ͳ�ͬ
void CDemo3Dlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	int a, b, c;
	TCHAR c1[10], c2[10], c3[10];
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(c1, 10);
	GetDlgItem(IDC_EDIT2)->GetWindowTextW(c2, 10);
	a = _ttoi(c1); // TCHAR תint
	b = _ttoi(c2);

	c = a + b;

	// ��int ת�����ַ���
	_itot_s(c, c3, 10);
	//SetDlgItemText(IDC_EDIT3, c3);
	GetDlgItem(IDC_EDIT3)->SetWindowTextW(c3);
}
