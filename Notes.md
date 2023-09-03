# 1. 几种MFC应用程序类型常用类型

MFC常用的几种已经写好的框架单文档、多文档与基于对话框

基于对话框：一般含以下三个类：CAboutDlg、程序名App、程序名Dlg

基于单文档: 一般含以下四个类：CMainFrame、程序名App、程序名Doc、程序名View

基于多文档: 一般含以下5个类: CMainFrame、CChildFrame、程序名App、程序名Doc、程序名View

# 2. MFC Object 和Windows Object 的对应关系

![image-20230903031428168](https://yeshooonotes.oss-cn-shenzhen.aliyuncs.com/notespic/202309030314240.png)

# 3. 访问控件的方法

[访问控件的7种方法](https://blog.csdn.net/pengz0807/article/details/47685583)

[类型转换](https://blog.csdn.net/pengz0807/article/details/47685733)

```cpp
// Demo3Dlg.cpp : implementation file

// 方法1：GetDlgItem 
void CDemo3Dlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	// 
	CString str1, str2, str3;

	GetDlgItem(IDC_EDIT1)->GetWindowTextW(str1);
	GetDlgItem(IDC_EDIT2)->GetWindowTextW(str2);
	GetDlgItem(IDC_EDIT3)->GetWindowTextW(str3);

	int a, b, c;

	// 字符转int
	a = _wtoi(str1.GetBuffer()); // 默认是unicode字符集用_wtoi来转换
	b = _wtoi(str2.GetBuffer());
	c = a + b;

	// int 转CString
	CString strint;
	strint.Format(L"%d", c);

	GetDlgItem(IDC_EDIT3)->SetWindowTextW(strint);
}

// 方法2： GetDlgItemText和SetDlgItemText
void CDemo3Dlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here

	int a, b, c;
	TCHAR c1[10], c2[10], c3[10];
	GetDlgItemText(IDC_EDIT1, c1, 10);
	GetDlgItemText(IDC_EDIT2, c2, 10);
	a = _ttoi(c1); // TCHAR 转int
	b = _ttoi(c2);

	c = a + b;

	// 将int 转换成字符型
	_itot_s(c, c3, 10);
	SetDlgItemText(IDC_EDIT3, c3);
}

// 方法3：类似于方法1，只是用来接收值的变量类型不同
void CDemo3Dlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	int a, b, c;
	TCHAR c1[10], c2[10], c3[10];
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(c1, 10);
	GetDlgItem(IDC_EDIT2)->GetWindowTextW(c2, 10);
	a = _ttoi(c1); // TCHAR 转int
	b = _ttoi(c2);

	c = a + b;

	// 将int 转换成字符型
	_itot_s(c, c3, 10);
	//SetDlgItemText(IDC_EDIT3, c3);
	GetDlgItem(IDC_EDIT3)->SetWindowTextW(c3);
}
```

