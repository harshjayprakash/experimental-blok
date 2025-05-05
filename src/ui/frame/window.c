#include "window.h"
#include "../events/process.h"

#define BLOK_CLEANUP_RESOURCE(object, cleanFn)                                           \
    if (object != NULL)                                                                  \
    {                                                                                    \
        (void)cleanFn(object);                                                           \
        object = NULL;                                                                   \
    }

LRESULT CALLBACK _blokWindowProcedure(
    HWND hWindow, UINT messageId, WPARAM dataWord, LPARAM dataLong)
{
    switch (messageId)
    {   
    case WM_DESTROY:
        PostQuitMessage(0);
        return TRUE;

    case WM_PAINT:
        blokProcessEventOnPaint(hWindow);
        return TRUE;

    case WM_SIZE:
        blokProcessEventOnResize(hWindow);
        return TRUE;

    case WM_KEYDOWN:
        blokProcessEventOnKeyDown(hWindow, dataWord);
        return TRUE;

    case WM_LBUTTONDOWN:
        blokProcessEventOnLeftMouseDown(hWindow, dataLong);
        return TRUE;

    case WM_RBUTTONDOWN:
        blokProcessEventOnRightMouseDown(hWindow, dataLong);
        return TRUE;

    case WM_LBUTTONUP:
        blokProcessEventOnLeftMouseUp(hWindow, dataLong);
        return TRUE;

    case WM_RBUTTONUP:
        blokProcessEventOnRightMouseUp(hWindow, dataLong);
        return TRUE;

    case WM_MOUSEMOVE:
        blokProcessEventOnMouseHover(hWindow, dataLong);
        return TRUE;

    default:
        return DefWindowProcW(hWindow, messageId, dataWord, dataLong);
    }
}

void blokWindowInit(Window *pWindow, HINSTANCE hInstance)
{
    if (!pWindow) { return; }
    if (!hInstance) { return; }

    pWindow->klassName = L"BlokViewportWindow";
    pWindow->caption = L"Blok 5.0 --25H2A";

    pWindow->klass.cbSize = sizeof(WNDCLASSEXW);
    pWindow->klass.style = CS_HREDRAW | CS_VREDRAW;
    pWindow->klass.lpfnWndProc = _blokWindowProcedure;
    pWindow->klass.cbClsExtra = 0;
    pWindow->klass.cbWndExtra = 0;
    pWindow->klass.hInstance = hInstance;
    pWindow->klass.hIcon = LoadIconW(pWindow->klass.hInstance, IDI_APPLICATION);
    pWindow->klass.hCursor = LoadCursorW(NULL, IDC_ARROW);
    pWindow->klass.hbrBackground = CreateSolidBrush(RGB(0, 0, 0));
    pWindow->klass.lpszMenuName = 0;
    pWindow->klass.lpszClassName = pWindow->klassName;
    pWindow->klass.hIconSm = LoadIconW(pWindow->klass.hInstance, IDI_APPLICATION);

    pWindow->klassAtomIdx = RegisterClassExW(&pWindow->klass);
    
    if (pWindow->klassAtomIdx == 0)
    {
        (void) MessageBoxW(0, L"Window Class Registeration Failed", L"Blok", 
            MB_OK | MB_ICONERROR);
        blokWindowFree(pWindow, hInstance);
        return;
    }

    pWindow->hHandle = CreateWindowExW(0L, pWindow->klassName, pWindow->caption, 
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, 0, 0, hInstance, 0);
    
    if (!pWindow->hHandle)
    {
        (void) MessageBoxW(0, L"Window Creation Failed", L"Blok", MB_OK | MB_ICONERROR);
        blokWindowFree(pWindow, hInstance);
        return;
    }
}

void blokWindowShow(Window *pWindow, DWORD showFlag)
{
    if (!pWindow) { return; }
    if (!pWindow->hHandle) { return; }

    (void) ShowWindow(pWindow->hHandle, showFlag);

    MSG message = {0};

    for (;;)
    {
        if (PeekMessageW(&message, 0, 0, 0, PM_REMOVE))
        {
            (void) TranslateMessage(&message);
            (void) DispatchMessageW(&message);

            if (message.message == WM_QUIT) { break; }
        }

        (void) UpdateWindow(pWindow->hHandle);
        Sleep(1);
    }
}

void blokWindowFree(Window *pWindow, HINSTANCE hInstance)
{
    if (!pWindow) { return; }
    
    __BLOK_CLEANUP_RESOURCE(pWindow->hHandle, DestroyWindow);
    __BLOK_CLEANUP_RESOURCE(pWindow->klass.hIcon, DestroyIcon);
    __BLOK_CLEANUP_RESOURCE(pWindow->klass.hIconSm, DestroyIcon);
    __BLOK_CLEANUP_RESOURCE(pWindow->klass.hCursor, DestroyCursor);
    __BLOK_CLEANUP_RESOURCE(pWindow->klass.hbrBackground, DeleteObject);
    
    if (pWindow->klassAtomIdx != 0)
    {
        (void) UnregisterClassW(pWindow->klassName, hInstance);
    }
}