#include <Windows.h>
int CALLBACK wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR szCMdLine, int nCmdShow)
{
	MSG msg{}; //отвечает за вывод сообщений
	HWND hwnd{}; //указатель на объект ядра - информация об окне
	WNDCLASSEX wd{ sizeof(WNDCLASSEX) }; //характеристики окна
	wd.cbClsExtra = 0; 
	wd.cbWndExtra = 0;
	wd.hbrBackground = reinterpret_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
	wd.hCursor = LoadCursor(nullptr, IDC_ARROW); 
	wd.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	wd.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);
	wd.hInstance = hInstance;
	wd.lpfnWndProc = [](HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)->LRESULT //в какое окно, какое сообщение, необходимая для сообщения ифнормация, результат
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

	if (!RegisterClassEx(&wd)) //регистрация класса окна 
		return EXIT_FAILURE;
	hwnd = CreateWindow(wd.lpszClassName, L"Заголовок окна", WS_OVERLAPPEDWINDOW, 0, 0, 500, 600, nullptr, nullptr, wd.hInstance, nullptr);//создание окна
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, nullptr, 0, 0))
	{
		TranslateMessage(&msg); //расшифровывает сообщение (можно не писать но стоит)
		DispatchMessage(&msg); //передает сообщение в окно на обработку
	}

	return static_cast<int> (msg.wParam);
}