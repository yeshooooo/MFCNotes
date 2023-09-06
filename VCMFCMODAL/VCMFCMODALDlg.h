
// VCMFCMODALDlg.h : header file
//

#pragma once
#include "CFMTDialog.h"

// CVCMFCMODALDlg dialog
class CVCMFCMODALDlg : public CDialog
{
// Construction
public:
	CVCMFCMODALDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_VCMFCMODAL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CFMTDialog m_ChildDlg;
	afx_msg void OnBnClickedButton3();
};

// 在主窗口类的头文件中，声明主窗口类的全局变量指针
extern CVCMFCMODALDlg* pMainDlg;
