// CFMTDialog.cpp : implementation file
//

#include "pch.h"
#include "VCMFCMODAL.h"
#include "CFMTDialog.h"
#include "afxdialogex.h"


// CFMTDialog dialog

IMPLEMENT_DYNAMIC(CFMTDialog, CDialog)

CFMTDialog::CFMTDialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG2, pParent)
{

}

CFMTDialog::~CFMTDialog()
{
}

void CFMTDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFMTDialog, CDialog)
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
	delete this; //��������ָ�룬��ֹ�ڴ�й©
	CDialog::PostNcDestroy();

}
