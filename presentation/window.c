#include "window.h"

#define BK_WINDOW_KLASS L"__BlokWindowClass"

#define BK_FREE_NOTNULL(o, f) \
	if (o) (void)f(o)

static LRESULT CALLBACK __bkWindowProcedure(
	HWND hWindow, UINT messageId, WPARAM wParam, LPARAM lParam)
{
	switch (messageId)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0LL;
	default:
		return DefWindowProcW(hWindow, messageId, wParam, lParam);
	}
}

static WPARAM __blokWindowRunMessageLoop(void)
{
	MSG events = { 0 };
	while (events.message != WM_QUIT)
	{
		if (PeekMessageW(&events, NULL, 0, 0, PM_REMOVE))
		{
			(void)TranslateMessage(&events);
			(void)DispatchMessageW(&events);
		}
		else
		{
			Sleep(1);
		}
	}
	return events.wParam;
}

static HWND __blokWindowCreate(
	HINSTANCE hInstance, PWCHAR pCaption, const int kWidth, const int kHeight)
{
	return CreateWindowExW(
		WS_EX_OVERLAPPEDWINDOW, BK_WINDOW_KLASS, L"Blok", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,
		CW_USEDEFAULT, kWidth, kHeight, NULL, NULL, hInstance, NULL);
}

static ATOM __blokWindowRegister(WNDCLASSEXW* pKlass, HINSTANCE hInstance)
{
	pKlass->cbSize = sizeof(WNDCLASSEXW);
	pKlass->style = CS_HREDRAW | CS_VREDRAW;
	pKlass->lpfnWndProc = __bkWindowProcedure;
	pKlass->cbClsExtra = 0;
	pKlass->cbWndExtra = 0;
	pKlass->hInstance = hInstance;
	pKlass->hCursor = LoadCursorW(hInstance, IDC_ARROW);
	pKlass->hIcon = LoadIconW(hInstance, IDI_APPLICATION);
	pKlass->hIconSm = LoadIconW(hInstance, IDI_APPLICATION);
	pKlass->hbrBackground = CreateSolidBrush(RGB(0, 0, 0));
	pKlass->lpszMenuName = NULL;
	pKlass->lpszClassName = BK_WINDOW_KLASS;
	return RegisterClassExW(pKlass);
}

void bkWindowInit(bkWindow* pWindow, HINSTANCE hInstance, int showFlag)
{
	if (!pWindow) return;
	ATOM registerSuccessful = __blokWindowRegister(&pWindow->klass, hInstance);
	if (!registerSuccessful)
	{
		(void)MessageBoxW(NULL, L"Window registration failed.", L"Blok", MB_OK);
		return;
	}
	pWindow->hWindow = __blokWindowCreate(hInstance, L"Blok", 800, 600);
	if (!pWindow->hWindow)
	{
		(void)MessageBoxW(NULL, L"Window creation failed.", L"Blok", MB_OK);
		return;
	}
	(void)ShowWindow(pWindow->hWindow, showFlag);
	(void)UpdateWindow(pWindow->hWindow);
	(void)__blokWindowRunMessageLoop();
}

void bkWindowFree(bkWindow* pWindow, HINSTANCE hInstance)
{
	if (!pWindow) return;
	(void)UnregisterClassW(BK_WINDOW_KLASS, hInstance);
	BK_FREE_NOTNULL(pWindow->klass.hIcon, DestroyIcon);
	BK_FREE_NOTNULL(pWindow->klass.hIconSm, DestroyIcon);
	BK_FREE_NOTNULL(pWindow->klass.hCursor, DestroyCursor);
	BK_FREE_NOTNULL(pWindow->klass.hbrBackground, DeleteObject);
	BK_FREE_NOTNULL(pWindow->hWindow, DestroyWindow);
}
