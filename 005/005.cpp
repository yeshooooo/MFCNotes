/*
* CWinThread
*/

#include <afxwin.h>

// 线程处理函数
UINT ThreadFun(LPVOID param) {
	for (int i = 0; i < 5; ++i)
	{
		char* str = (char*)param;
		printf("%s\n", str);
		Sleep(1000);
	}
	return 0;

}
int main() {
	// 定义一个类的对象
	char param[10] = "Hello";
	CWinThread t(ThreadFun, param);

	// 局部变量不需要自动销毁,否则线程结束的时候会异常，他会销毁两次
	t.m_bAutoDelete = FALSE; 

	// 调用线程的成员函数，创建线程
	t.CreateThread();
	// 输出其他成员变量
	printf("参数：%s\n", t.m_pThreadParams);
	printf("线程句柄: %d\n", t.m_hThread);
	printf("线程ID:%d\n", t.m_nThreadID);
	// 等待线程执行完毕
	WaitForSingleObject(t.m_hThread, INFINITE);

	printf("main结束");

}