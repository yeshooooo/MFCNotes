#pragma once


// CMTDialog dialog

class CMTDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CMTDialog)

public:
	CMTDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CMTDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
