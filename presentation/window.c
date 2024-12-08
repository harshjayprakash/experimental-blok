/*****************************************************************//**
 * \file   window.c
 * \brief  Contains windows functions implementation.
 * 
 * \author Harsh Jayprakash
 * \date   04th of December 2024
 *********************************************************************/

#include "window.h"
#include "gfx/renderer.h"
#include "../service/state.h"

#define BK_WINDOW_KLASS L"__BlokWindowClass"

static LRESULT CALLBACK __bkWindowProcedure(
	HWND hWindow, UINT messageId, WPARAM wParam, LPARAM lParam)
{
	static bkRenderer renderer = { 0 };
	static bkState state = { 0 };
	static RECT windowArea = { 0 };
	switch (messageId)
	{
	case WM_CREATE:
		bkRendererInit(&renderer);
		bkStateInit(&state);
		(void)GetClientRect(hWindow, &windowArea);
		return 0LL;
	case WM_DESTROY:
		bkRendererFree(&renderer);
		bkStateFree(&state);
		PostQuitMessage(0);
		return 0LL;
	case WM_PAINT: {
		PAINTSTRUCT paint;
		HDC hWindowContext = BeginPaint(hWindow, &paint);
		HDC hBufferedContext = CreateCompatibleDC(hWindowContext);
		HBITMAP hBufferedBitmap = CreateCompatibleBitmap(hWindowContext, windowArea.right, windowArea.bottom);
		(void)SelectObject(hBufferedContext, hBufferedBitmap);
		bkRendererPaint(&renderer, &state, hBufferedContext, windowArea);
		(void)BitBlt(hWindowContext, 0, 0, windowArea.right, windowArea.bottom, hBufferedContext, 0, 0, SRCCOPY);
		(void)DeleteObject(hBufferedBitmap);
		(void)DeleteDC(hBufferedContext);
		return EndPaint(hWindow, &paint);
	}
	case WM_SIZE:
		return GetClientRect(hWindow, &windowArea);
	case WM_KEYDOWN: {
		switch ((int)wParam)
		{
		case VK_UP: 
			state.user.position.y -= 15;
			return InvalidateRect(hWindow, NULL, FALSE);
		case VK_DOWN: 
			state.user.position.y += 15;
			return InvalidateRect(hWindow, NULL, FALSE);
		case VK_LEFT: 
			state.user.position.x -= 15;
			return InvalidateRect(hWindow, NULL, FALSE);
		case VK_RIGHT: 
			state.user.position.x += 15;
			return InvalidateRect(hWindow, NULL, FALSE);
		case VK_F11:
			state.showInterface =
				(state.showInterface == 1) ? 0 : 1;
			return InvalidateRect(hWindow, NULL, FALSE);
		case VK_F5:
			state.user.position.x = 0;
			state.user.position.y = 0;
			return InvalidateRect(hWindow, NULL, FALSE);
		case VK_F1:
			(void)MessageBoxW(hWindow, L"Help: Not Implemented", L"Blok", MB_OK);
			return 0LL;
		case VK_F9:
			return InvalidateRect(hWindow, NULL, TRUE);
		case VK_F12:
			(void)MessageBoxW(hWindow, L"Export: Not Implemented", L"Blok", MB_OK);
			return 0LL;
		case VK_F3:
			// FIND THE BLOCK (FLASH ON THE SCREEN)
			return 0LL;
		case VK_F4:
			// CLOSE
		case VK_F6:
		case VK_F7:
		case VK_F8:
		case VK_F10:
			return 0LL;
		}
	}
	default:
		return DefWindowProcW(hWindow, messageId, wParam, lParam);
	}
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

void bkWindowInit(bkWindow* pWindow, HINSTANCE hInstance)
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

}

WPARAM bkWindowShow(bkWindow* pWindow, const int kShowFlag)
{
	if (!pWindow) return MAXULONG_PTR;
	MSG events = { 0 };
	(void)ShowWindow(pWindow->hWindow, kShowFlag);
	(void)UpdateWindow(pWindow->hWindow);
	while (events.message != WM_QUIT)
	{
		if (PeekMessageW(&events, NULL, 0, 0, PM_REMOVE))
		{
			(void)TranslateMessage(&events);
			(void)DispatchMessageW(&events);
		}
		else
		{
			(void)SendMessageW(pWindow->hWindow, WM_PAINT, 0, 0);
			Sleep(1);
		}
	}
	return events.wParam;
}

void bkWindowFree(bkWindow* pWindow, HINSTANCE hInstance)
{
	if (!pWindow) return;
	(void)UnregisterClassW(BK_WINDOW_KLASS, hInstance);
	if (pWindow->klass.hIcon) (void)DestroyIcon(pWindow->klass.hIcon);
	if (pWindow->klass.hIconSm) (void)DestroyIcon(pWindow->klass.hIconSm);
	if (pWindow->klass.hCursor) (void)DestroyCursor(pWindow->klass.hCursor);
	if (pWindow->klass.hbrBackground) (void)DeleteObject(pWindow->klass.hbrBackground);
	if (pWindow->hWindow) (void)DestroyWindow(pWindow->hWindow);
}
