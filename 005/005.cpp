/*
* CWinThread
*/

#include <afxwin.h>

// �̴߳�����
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
	// ����һ����Ķ���
	char param[10] = "Hello";
	CWinThread t(ThreadFun, param);

	// �ֲ���������Ҫ�Զ�����,�����߳̽�����ʱ����쳣��������������
	t.m_bAutoDelete = FALSE; 

	// �����̵߳ĳ�Ա�����������߳�
	t.CreateThread();
	// ���������Ա����
	printf("������%s\n", t.m_pThreadParams);
	printf("�߳̾��: %d\n", t.m_hThread);
	printf("�߳�ID:%d\n", t.m_nThreadID);
	// �ȴ��߳�ִ�����
	WaitForSingleObject(t.m_hThread, INFINITE);

	printf("main����");

}