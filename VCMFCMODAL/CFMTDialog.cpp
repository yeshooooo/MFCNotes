// CFMTDialog.cpp : implementation file
//

#include "pch.h"
#include "VCMFCMODAL.h"
#include "CFMTDialog.h"
#include "afxdialogex.h"
#include "VCMFCMODALDlg.h"


// CFMTDialog dialog

IMPLEMENT_DYNAMIC(CFMTDialog, CDialog)

CFMTDialog::CFMTDialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG2, pParent)
{

	//m_defaulta.SetWindowTextW(TEXT("欢迎大家来到vc驿站！"));
}

CFMTDialog::~CFMTDialog()
{
}

void CFMTDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_defaulta);
}


BEGIN_MESSAGE_MAP(CFMTDialog, CDialog)
	ON_EN_CHANGE(IDC_EDIT1, &CFMTDialog::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &CFMTDialog::OnBnClickedButton1)
END_MESSAGE_MAP()


// CFMTDialog message handlers


BOOL CFMTDialog::DestroyWindow()
{
	// TODO: Add your specialized code here and/or call the base class

	return CDialog::DestroyWindow();
}


void CFMTDialog::OnCancel()
{
	// TODO: Add your specialized code here and/or call the base class

	//CDialog::OnCancel();
	DestroyWindow();
}


void CFMTDialog::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	//CDialog::OnOK();
	DestroyWindow(); // 销毁非模态窗口
}


void CFMTDialog::PostNcDestroy()
{
	// TODO: Add your specialized code here and/or call the base class
	//delete this; //销毁自身指针，防止内存泄漏
	CDialog::PostNcDestroy();

}


void CFMTDialog::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CFMTDialog::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	// 方法2： 获取父窗口的指针
	// 获取子窗口上的内容
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
// 	// 子窗口可以直接获取父窗口的引用,获取到的是CWnd* 类型的，因为已经明确知道了
// 	// 父窗口指针类型，所以直接强转
// 	CVCMFCMODALDlg* pParent =  (CVCMFCMODALDlg*)GetParent();
// 	pParent->SetDlgItemTextW(IDC_EDIT1, str);
// 
// 	// 方法1: 全局变量法
// 	pMainDlg->SetDlgItemTextW(IDC_EDIT1, str);

// 	// 方法3： App类法
// 	CVCMFCMODALDlg* pParent = (CVCMFCMODALDlg*)AfxGetApp()->m_pMainWnd;
// 	pParent->SetDlgItemTextW(IDC_EDIT1, str);

	// 方法4： 参数传递法
	// 用CWnd* 或者 VOID*是为了防止重复包含，编译不通过
	CVCMFCMODALDlg* pMainWnd = (CVCMFCMODALDlg*)m_pParentDlg;
	m_pParentDlg->SetDlgItemTextW(IDC_EDIT1, str);

}
