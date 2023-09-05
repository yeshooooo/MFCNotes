
// VCMFCDlgFirstDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "VCMFCDlgFirst.h"
#include "VCMFCDlgFirstDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//С��ҵ
int GetEditValue(int value)
{
	return value;

}





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


// CVCMFCDlgFirstDlg dialog



CVCMFCDlgFirstDlg::CVCMFCDlgFirstDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_VCMFCDLGFIRST_DIALOG, pParent)
	, m_CheckStatus(0)
{
	pCheckBox = NULL;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CVCMFCDlgFirstDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, m_CheckBtn);
	DDX_Check(pDX, IDC_CHECK1, m_CheckStatus);
}

// ��Ϣӳ��ĺ꣬��ĳһ����Ϣ��Ӧ������Ϣ��Ӧ����������
// ������Щ��Ϣ�Զ�ȥ����������Ӧ����
BEGIN_MESSAGE_MAP(CVCMFCDlgFirstDlg, CDialog)// ����1��Ҫ�󶨵��࣬����2������
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CVCMFCDlgFirstDlg::OnBnClickedButton1) // ���о���˫����ť���Զ���ӵ�
	ON_BN_CLICKED(IDC_BUTTON2, &CVCMFCDlgFirstDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CVCMFCDlgFirstDlg message handlers

BOOL CVCMFCDlgFirstDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

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
	pCheckBox = (CButton*)GetDlgItem(IDC_CHECK1);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CVCMFCDlgFirstDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CVCMFCDlgFirstDlg::OnPaint()
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
HCURSOR CVCMFCDlgFirstDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CVCMFCDlgFirstDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
// 	// ����1��
// 	// ȫ��API����
// 	HWND hCheckBox = ::GetDlgItem(m_hWnd, IDC_CHECK1);
// 	int iCheckApi = ::SendMessage(hCheckBox, BM_GETCHECK, 0, 0);
// 	// -------
// 	// ����2��
// 	// MFC�������Ƕ�ȫ��API�ķ�װ��Ĭ�ϴӵ�ǰ���ڻ�ȡ��ʡ�Ե�һ���������ھ��
// 	// Radio Button ,Check Box ,Button����CButton��, ���Զ�����д��CButton*
// 	// CWnd* pCheckBox =  GetDlgItem(IDC_CHECK1); // ���ؿؼ�ָ��
// 	CButton* pCheckBox =  (CButton*)GetDlgItem(IDC_CHECK1); // ���ؿؼ�ָ��
// 	// δѡ����0��ѡ����1
	int iCheck = pCheckBox->GetCheck(); // �����ϻ��Ƿ���Win32��Ϣ

	

}


void CVCMFCDlgFirstDlg::OnCancel()
{
	// TODO: Add your specialized code here and/or call the base class
	MessageBox(_T("ȡ����ť�����"));
	CDialog::OnCancel();
}


void CVCMFCDlgFirstDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
// 	int iCheck = pCheckBox->GetCheck();
// 
// 	int iRet = m_CheckBtn.GetCheck();
	//UpdateData(TRUE);
	//m_CheckStatus;
	
	// �ֶ�����Ϊ1����д������
	m_CheckStatus = 1;
	UpdateData(FALSE);
}
