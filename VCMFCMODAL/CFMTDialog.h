#pragma once


// CFMTDialog dialog

class CFMTDialog : public CDialog
{
	DECLARE_DYNAMIC(CFMTDialog)

public:
	CFMTDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CFMTDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL DestroyWindow();
	virtual void OnCancel();
	virtual void OnOK();
	virtual void PostNcDestroy();
};
