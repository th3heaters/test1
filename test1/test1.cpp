#include <windows.h>

int CALLBACK winMain(HINSTANCE hInstance, HINSTANCE, PWSTR szCMdLine, int nCmdShow)
{
	MSG msg{}; //�������� �� ����� ���������
	HWND hund{}; //��������� �� ������ ���� - ���������� �� ����
	WNDCLASSEX wd{ sizeof(WNDCLASSEX) };
	wd.cbClsExtra = 0;
	wd.cbWndExtra = 0;
}