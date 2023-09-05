// CMTDialog.cpp : implementation file
//

#include "pch.h"
#include "VCMFCMODAL.h"
#include "CMTDialog.h"
#include "afxdialogex.h"


// CMTDialog dialog

IMPLEMENT_DYNAMIC(CMTDialog, CDialogEx)

CMTDialog::CMTDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CMTDialog::~CMTDialog()
{
}

void CMTDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMTDialog, CDialogEx)
END_MESSAGE_MAP()


// CMTDialog message handlers


BOOL CMTDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	SetDlgItemText(IDC_EDIT1, TEXT("hello VCÊ‰’æ"));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
