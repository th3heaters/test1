#include <windows.h>

int CALLBACK winMain(HINSTANCE hInstance, HINSTANCE, PWSTR szCMdLine, int nCmdShow)
{
	MSG msg{}; //отвечает за вывод сообщений
	HWND hund{}; //указатель на объект ядра - информация об окне
	WNDCLASSEX wd{ sizeof(WNDCLASSEX) };
	wd.cbClsExtra = 0;
	wd.cbWndExtra = 0;
}