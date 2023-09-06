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

	//m_defaulta.SetWindowTextW(TEXT("��ӭ�������vc��վ��"));
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
	DestroyWindow(); // ���ٷ�ģ̬����
}


void CFMTDialog::PostNcDestroy()
{
	// TODO: Add your specialized code here and/or call the base class
	//delete this; //��������ָ�룬��ֹ�ڴ�й©
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
	// ����2�� ��ȡ�����ڵ�ָ��
	// ��ȡ�Ӵ����ϵ�����
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
// 	// �Ӵ��ڿ���ֱ�ӻ�ȡ�����ڵ�����,��ȡ������CWnd* ���͵ģ���Ϊ�Ѿ���ȷ֪����
// 	// ������ָ�����ͣ�����ֱ��ǿת
// 	CVCMFCMODALDlg* pParent =  (CVCMFCMODALDlg*)GetParent();
// 	pParent->SetDlgItemTextW(IDC_EDIT1, str);
// 
// 	// ����1: ȫ�ֱ�����
// 	pMainDlg->SetDlgItemTextW(IDC_EDIT1, str);

// 	// ����3�� App�෨
// 	CVCMFCMODALDlg* pParent = (CVCMFCMODALDlg*)AfxGetApp()->m_pMainWnd;
// 	pParent->SetDlgItemTextW(IDC_EDIT1, str);

	// ����4�� �������ݷ�
	// ��CWnd* ���� VOID*��Ϊ�˷�ֹ�ظ����������벻ͨ��
	CVCMFCMODALDlg* pMainWnd = (CVCMFCMODALDlg*)m_pParentDlg;
	m_pParentDlg->SetDlgItemTextW(IDC_EDIT1, str);

}
