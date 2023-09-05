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

# 5. MFC控件指针及控件变量绑定

### 5.1 控件指针的获取

核心API函数: GetDlgItem

==MFC中可以叫控件指针，WIN32中叫控件句柄，因为MFC对控件进行了封装，不同的控件是不同的类，相对于获得CWND的指针了==

① 随时用，随时取

```cpp
void CVCMFCDlgFirstDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	// 方法1：
	// 全局API函数
	HWND hCheckBox = ::GetDlgItem(m_hWnd, IDC_CHECK1);
	int iCheckApi = ::SendMessage(hCheckBox, BM_GETCHECK, 0, 0);
	// -------
	// 方法2：
	// MFC方法，是对全局API的封装，默认从当前窗口获取，省略第一个参数窗口句柄
	// Radio Button ,Check Box ,Button都是CButton类, 所以都可以写出CButton*
	// CWnd* pCheckBox =  GetDlgItem(IDC_CHECK1); // 返回控件指针
	CButton* pCheckBox =  (CButton*)GetDlgItem(IDC_CHECK1); // 返回控件指针
	// 未选中是0，选中是1
	int iCheck = pCheckBox->GetCheck(); // 本质上还是发送Win32消息

}
```



② 声明类成员变量指针，初始化函数中获取

假如有多个按钮，每次都要获取就比较麻烦，这时候就可以声明成成员变量，在初始化函数中获取

注意成员变量在构造函数中也要赋值为NULL

### 5.2 控件变量的绑定

因为直接用指针可能不安全，衍生出了下面控件变量的绑定

==可以用开源控件类增强他的功能==

① 绑定控件类型变量

控件绑定成变量加了什么？

![image-20230905214409265](https://yeshooonotes.oss-cn-shenzhen.aliyuncs.com/notespic/202309052144416.png)

![image-20230905214354633](https://yeshooonotes.oss-cn-shenzhen.aliyuncs.com/notespic/202309052143739.png)

然后就可以随便用了

② 绑定值类型变量

==不同于控件类型的变量，值类型的变量需手动设置数据流的流向==

UpdateData(TRUE); // **控件的界面上的值保存到变量**

UpdateData(FALSE); // **变量的值显示到控件的界面上**

![image-20230905221636305](https://yeshooonotes.oss-cn-shenzhen.aliyuncs.com/notespic/202309052216650.png)

```cpp
void CVCMFCDlgFirstDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
// 	int iCheck = pCheckBox->GetCheck();
// 
// 	int iRet = m_CheckBtn.GetCheck();
	UpdateData(TRUE); //数据绑定到变量
	m_CheckStatus;
}
```

```cpp
	// 手动设置为1，回写给界面
	m_CheckStatus = 1;
	UpdateData(FALSE);
```

# 6. MFC 创建模态与非模态对话框

### 6.1 创建模态对话框



步骤：

#### 6.1.1 创建对话框模板

![image-20230905235428263](https://yeshooonotes.oss-cn-shenzhen.aliyuncs.com/notespic/202309052354309.png)

#### 6.1.2 绑定自定义对话框类

1. 只弹出对话框，不进行交互

```cpp
void CVCMFCMODALDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CDialog dlg(IDD_DIALOG1);
	dlg.DoModal();
}

```

2. ==弹出对话框并进行交互，就必须要绑定自定义的对话框类了==

![image-20230906001746514](https://yeshooonotes.oss-cn-shenzhen.aliyuncs.com/notespic/202309060017593.png)

![image-20230906001901119](https://yeshooonotes.oss-cn-shenzhen.aliyuncs.com/notespic/202309060019167.png)



```cpp

```



#### 6.1.3 创建模态对话框：DoModal

这里已经绑定了，所以下面就不用填ID了

```cpp
#include "CMTDialog.h"
void CVCMFCMODALDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CMTDialog dlg;
	dlg.DoModal();
}

```



新创建出来的Dialog对话框类空空如也

```cpp
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
};

```

给他添加事件

![image-20230906003200401](https://yeshooonotes.oss-cn-shenzhen.aliyuncs.com/notespic/202309060032499.png)

![image-20230906003536449](https://yeshooonotes.oss-cn-shenzhen.aliyuncs.com/notespic/202309060035510.png)

#### 6.1.4 销毁模态对话框： CDialog::OnOk(), CDialog::OnCancel(), CDialog::OnClose()这三个都可以



### 6.2 创建非模态对话框

#### 6.2.1 创建对话框模板

同6.1.1 创建对话框模板

#### 6.2.2 绑定自定义对话框类

同6.1.2绑定自定义对话框类

### 6.2.3 创建非模态对话框：Create、ShowWindow

==与模态对话框创建完了自动显示不一样，非模态对话框创建完了需要手动Show一下==

```cpp
// 创建非模态对话框

#include "CFMTDialog.h"
CFMTDialog dlg; // 这里要设置为全局变量，不然对话框会一闪而过，被自动回收,也可以设置为主对话框类的成员变量，也可以在主对话框button函数里new出来
void CVCMFCMODALDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here

	BOOL bRet = dlg.Create(IDD_DIALOG2); // 不同于模态对话框，这里要输入对话框ID

	if (bRet)
	{
		dlg.ShowWindow(SW_SHOW);
	}
}
```



#### 6.2.4 销毁非模态对话框： CWnd::DestroyWindow()可以

==非模态对话框销毁必须调用DestroyWindow==

在OnCancel()等里面，不能再调用父类的了，要调用DestroyWindow

```cpp
// 右上角的X跟Cancel按钮都是调用的OnCancel
void CFMTDialog::OnCancel()
{
	// TODO: Add your specialized code here and/or call the base class

	//CDialog::OnCancel();
	DestroyWindow(); //关闭非模态对话框
}
// ok按钮调用的是OnOK
void CFMTDialog::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	//CDialog::OnOK();
	DestroyWindow(); // 销毁非模态窗口
}
```



#### 6.2.5 若要销毁自身窗口指针的话，可以重载PostNcDestroy()函数，之后添加delete this;

==如果说非模态对话框是全局变量或者主对话框的成员变量，这一步没有==。但是如果，非模态对话框是下面这种new出来的指针，就要手动销毁

==全局变量或者主对话框的成员变量千万不能使用delete，因为没new==

```cpp
#include "CFMTDialog.h"
// CFMTDialog dlg; // 这里要设置为全局变量，不然对话框会一闪而过，被自动回收
void CVCMFCMODALDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	CFMTDialog* pFMTDlg = new CFMTDialog(); // 在堆中创建对象，也可以防止被自动销毁
	BOOL bRet = pFMTDlg->Create(IDD_DIALOG2); // 不同于模态对话框，这里要输入对话框ID

	if (bRet)
	{
		pFMTDlg->ShowWindow(SW_SHOW);
	}
}

```

如果不销毁的话，每次点击它都会new，就会内存泄漏

![image-20230906012108957](https://yeshooonotes.oss-cn-shenzhen.aliyuncs.com/notespic/202309060121993.png)

```cpp
void CFMTDialog::PostNcDestroy()
{
	// TODO: Add your specialized code here and/or call the base class
    //注意：让加哪里就加哪里，不用加错位置
	delete this; //销毁自身指针，防止内存泄漏
	CDialog::PostNcDestroy();

}
```

![image-20230906012615272](https://yeshooonotes.oss-cn-shenzhen.aliyuncs.com/notespic/202309060126591.png)
