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

# 4. VC驿站教程中MFC部分

[地址](https://www.bilibili.com/video/BV1Bb411e7av?p=23&vd_source=c6ca89f75d00cd4da634736edfcca1ae)

### 4.1 MFC框架简介

![image-20230904191903880](https://yeshooonotes.oss-cn-shenzhen.aliyuncs.com/notespic/202309041919422.png)

![image-20230904192225383](https://yeshooonotes.oss-cn-shenzhen.aliyuncs.com/notespic/202309041922913.png)

![image-20230904194922872](https://yeshooonotes.oss-cn-shenzhen.aliyuncs.com/notespic/202309041949257.png)

==默认添加了消息处理函数OnInitDialog函数==

### 4.2 MFC中常用窗口类及关系

![image-20230904212011578](https://yeshooonotes.oss-cn-shenzhen.aliyuncs.com/notespic/202309042120946.png)

* 这里的创建窗口，获得窗口等，都是类中标识的成员变量HWND m_hWnd这个窗口

  [Cwnd类介绍](https://blog.csdn.net/wzhrsh/article/details/103647953)
  
* 

2、CWnd与HWND的区别是什么？如何转换呢？直接强制类型转换可以吗？
①、区别
HWND是句柄，CWnd是MFC中的窗口基类，CWnd中包含HWND类型的句柄成员变量是m_hWnd，HWND是Windows系统中对所有窗口的一种标识，即窗口句柄。这是一个SDK概念。  
CWnd是MFC类库中所有窗口类的基类。微软在MFC中将所有窗口的通用操作都封装到了这个类中，如：ShowWindow、EnableWindow 等等，同时它也封装了窗口句柄即 m_hWnd 成员。

②、如何得到窗口对象指针 CWnd* pCWnd;
a、在窗口类的作用域中，直接就是 this，this 就是本窗口的窗口对象指针；
b、主窗口的类对象指针：AfxGetApp()->m_pMainWnd, //AfxGetApp()->m_pMainWnd 就是主窗口的窗口对象指针；
c、pCWnd = GetDlgItem(ID_EDIT_NAME); //GetDlgItem 函数可以得到某个控件的窗口对象指针。

③、如何得到窗口句柄 HWND hWnd;
a、在窗口类的作用域中：hWnd = this->m_hWnd;
b、非窗口类的作用域中：hWnd = GetDlgItem(ID_EDIT_NAME);
c、hWnd = ::GetDlgItem(this->m_hWnd, IDC_STATIC_MODE); //得到本窗体内某个控件的句柄

④、转换，他们两个是不同的类型，所以不能直接强制类型转换，要通过函数去转换：
CWnd* pWnd = NULL;
HWND hWnd = NULL;

pWnd = CWnd::FromHandle(hWnd);
hWnd = GetSafeHwnd(pWnd);

### 4.3 工程向导创建的对话框工程详解

#### 4.3.1 工程向导

![image-20230904231842005](https://yeshooonotes.oss-cn-shenzhen.aliyuncs.com/notespic/202309042318124.png)

单文档类似于记事本，多文档类似于word,ppt，多个文档视图

写小程序之类的，一般选对话框，因为可以方便的拖放控件

![image-20230904233717693](https://yeshooonotes.oss-cn-shenzhen.aliyuncs.com/notespic/202309042337752.png)

这里可以选择默认对话框的基类，为了简单这里选CDialog

![image-20230904233925322](https://yeshooonotes.oss-cn-shenzhen.aliyuncs.com/notespic/202309042339366.png)

#### 4.3.2 工程详解

![image-20230904234523304](https://yeshooonotes.oss-cn-shenzhen.aliyuncs.com/notespic/202309042345473.png)



**1. 对话框类**

![image-20230905000232402](https://yeshooonotes.oss-cn-shenzhen.aliyuncs.com/notespic/202309050002427.png)

DoDataExchange: 进行数据校验或者控件的变量绑定，绑定的时候会往这里自动添加代码，一般不需要手动绑定

```cpp
// 消息映射的宏，把某一条消息对应的类消息响应函数绑定起来
// 来了这些消息自动去调用他的响应函数
// 添加消息响应的时候，会自动往这里加东西，一般不需要手动编写
BEGIN_MESSAGE_MAP(CVCMFCDlgFirstDlg, CDialog)// 参数1：要绑定的类，参数2：父类
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CVCMFCDlgFirstDlg::OnBnClickedButton1) // 这行就是双击按钮后自动添加的
END_MESSAGE_MAP()
```

OnPaint: 进行对话框界面描画的时候调用，一般不动，手动画线，方框这种，就需要在这编写

![image-20230905002901185](https://yeshooonotes.oss-cn-shenzhen.aliyuncs.com/notespic/202309050029185.png)

**2. 主线程类**(app类)

![image-20230905003422730](https://yeshooonotes.oss-cn-shenzhen.aliyuncs.com/notespic/202309050034177.png)

```cpp
//InitInstance()
...
    	CVCMFCDlgFirstDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal(); // 创建一个模态对话框，然后阻塞住，不会往下走，对话框关闭后才往下走
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	...
```

**3.类的属性**

![image-20230905003503388](https://yeshooonotes.oss-cn-shenzhen.aliyuncs.com/notespic/202309050035777.png)

![image-20230905003740215](https://yeshooonotes.oss-cn-shenzhen.aliyuncs.com/notespic/202309050037667.png)

![image-20230905004146844](https://yeshooonotes.oss-cn-shenzhen.aliyuncs.com/notespic/202309050041876.png)

![image-20230905004300193](https://yeshooonotes.oss-cn-shenzhen.aliyuncs.com/notespic/202309050043226.png)

下拉页中就可以添加响应函数

==给按钮添加响应函数的方法==

1. 双击对话框rc上的按钮
2. 在类属性事件下拉菜单的
3. 在对话框rc中右键按钮-> add event handler

属性中的消息

![image-20230905004735313](https://yeshooonotes.oss-cn-shenzhen.aliyuncs.com/notespic/202309050047368.png)

如添加鼠标右键抬起的消息

![image-20230905004833617](https://yeshooonotes.oss-cn-shenzhen.aliyuncs.com/notespic/202309050048642.png)

注意加的位置，他TODO让加哪里就加哪里

![image-20230905004925389](https://yeshooonotes.oss-cn-shenzhen.aliyuncs.com/notespic/202309050049440.png)

添加重载虚函数

![image-20230905005030423](https://yeshooonotes.oss-cn-shenzhen.aliyuncs.com/notespic/202309050050473.png)

```cpp
void CVCMFCDlgFirstDlg::OnCancel()
{
	// TODO: Add your specialized code here and/or call the base class
	MessageBox(_T("取消按钮被点击"));
	CDialog::OnCancel();
}
```

答案：
0、CMFCDlgFirstApp::ExitInstance() 中的 MessageBox(_T(“线程退出”)); 为什么不好用？
虽然 CMFCDlgFirstApp 也属于MFC的类，但不是直接或者间接派生自 CWnd，所以默认调用的是全局的 MessageBox API 函数，也就是应该这样：MessageBox(NULL, _T("线程退出"), _T("提示"), MB_OK);
而不是调用 CWnd 中的这样： MessageBox(_T("线程退出"));
