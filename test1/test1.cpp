#include <Windows.h>
int CALLBACK wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR szCMdLine, int nCmdShow)
{
	MSG msg{}; //�������� �� ����� ���������
	HWND hwnd{}; //��������� �� ������ ���� - ���������� �� ����
	WNDCLASSEX wd{ sizeof(WNDCLASSEX) }; //�������������� ����
	wd.cbClsExtra = 0; 
	wd.cbWndExtra = 0;
	wd.hbrBackground = reinterpret_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
	wd.hCursor = LoadCursor(nullptr, IDC_ARROW); 
	wd.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	wd.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);
	wd.hInstance = hInstance;
	wd.lpfnWndProc = [](HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)->LRESULT //� ����� ����, ����� ���������, ����������� ��� ��������� ����������, ���������
	{
		switch (uMsg)
		{
			case WM_DESTROY:
			{
				PostQuitMessage(EXIT_SUCCESS);

			}
			return 0;
		}
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	};
	wd.lpszClassName = L"MyClass";
	wd.lpszMenuName = nullptr;
	wd.style = CS_VREDRAW | CS_HREDRAW;

	if (!RegisterClassEx(&wd)) //����������� ������ ���� 
		return EXIT_FAILURE;
	hwnd = CreateWindow(wd.lpszClassName, L"��������� ����", WS_OVERLAPPEDWINDOW, 0, 0, 500, 600, nullptr, nullptr, wd.hInstance, nullptr);//�������� ����
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, nullptr, 0, 0))
	{
		TranslateMessage(&msg); //�������������� ��������� (����� �� ������ �� �����)
		DispatchMessage(&msg); //�������� ��������� � ���� �� ���������
	}

	return static_cast<int> (msg.wParam);
}