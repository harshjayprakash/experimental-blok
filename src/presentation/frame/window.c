#include "window.h"
#include "../events/process.h"

#define __BLOK_CLEANUP_RESOURCE(object, cleanFn) \
    if (object != NULL) { (void) cleanFn(object); }

LRESULT CALLBACK __BlokWindowProcedure(
    HWND window, UINT messageId, WPARAM dataWord, LPARAM dataLong)
{
    switch (messageId)
    {   
    case WM_DESTROY:
        PostQuitMessage(0);
        return TRUE;

    case WM_PAINT:
        BlokProcessEventOnPaint(window);
        return TRUE;

    case WM_SIZE:
        BlokProcessEventOnResize(window);
        return TRUE;

    case WM_KEYDOWN:
        BlokProcessEventOnKeyDown(window, dataWord);
        return TRUE;

    case WM_LBUTTONDOWN:
        BlokProcessEventOnLeftMouseDown(window, dataLong);
        return TRUE;

    case WM_LBUTTONUP:
        BlokProcessEventOnLeftMouseUp(window, dataLong);
        return TRUE;

    case WM_MOUSEMOVE:
        BlokProcessEventOnMouseHover(window, dataLong);
        return TRUE;

    default:
        return DefWindowProcW(window, messageId, dataWord, dataLong);
    }
}

void BlokWindowInit(Window *window, HINSTANCE instance)
{
    if (!window) { return; }
    if (!instance) { return; }

    window->klassName = L"BlokViewportWindow";
    window->caption = L"Blok 25H2.1";

    window->klass.cbSize = sizeof(WNDCLASSEXW);
    window->klass.style = CS_HREDRAW | CS_VREDRAW;
    window->klass.lpfnWndProc = __BlokWindowProcedure;
    window->klass.cbClsExtra = 0;
    window->klass.cbWndExtra = 0;
    window->klass.hInstance = instance;
    window->klass.hIcon = LoadIconW(window->klass.hInstance, IDI_APPLICATION);
    window->klass.hCursor = LoadCursorW(NULL, IDC_ARROW);
    window->klass.hbrBackground = CreateSolidBrush(RGB(0, 0, 0));
    window->klass.lpszMenuName = 0;
    window->klass.lpszClassName = window->klassName;
    window->klass.hIconSm = LoadIconW(window->klass.hInstance, IDI_APPLICATION);

    window->klassAtomIdx = RegisterClassExW(&window->klass);
    
    if (window->klassAtomIdx == 0)
    {
        (void) MessageBoxW(0, L"Window Class Registeration Failed", L"Blok", 
            MB_OK | MB_ICONERROR);
        BlokWindowFree(window, instance);
        return;
    }

    window->handle = CreateWindowExW(0L, window->klassName, window->caption, 
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, 0, 0, instance, 0);
    
    if (!window->handle)
    {
        (void) MessageBoxW(0, L"Window Creation Failed", L"Blok", MB_OK | MB_ICONERROR);
        BlokWindowFree(window, instance);
        return;
    }
}

void BlokWindowShow(Window *window, DWORD showFlag)
{
    if (!window) { return; }
    if (!window->handle) { return; }

    (void) ShowWindow(window->handle, showFlag);

    MSG message = {0};

    for (;;)
    {
        if (PeekMessageW(&message, 0, 0, 0, PM_REMOVE))
        {
            (void) TranslateMessage(&message);
            (void) DispatchMessageW(&message);

            if (message.message == WM_QUIT) { break; }
        }

        (void) UpdateWindow(window->handle);
        Sleep(1);
    }
}

void BlokWindowFree(Window *window, HINSTANCE instance)
{
    if (!window) { return; }
    
    __BLOK_CLEANUP_RESOURCE(window->handle, DestroyWindow);
    __BLOK_CLEANUP_RESOURCE(window->klass.hIcon, DestroyIcon);
    __BLOK_CLEANUP_RESOURCE(window->klass.hIconSm, DestroyIcon);
    __BLOK_CLEANUP_RESOURCE(window->klass.hCursor, DestroyCursor);
    __BLOK_CLEANUP_RESOURCE(window->klass.hbrBackground, DeleteObject);
    
    if (window->klassAtomIdx != 0)
    {
        (void) UnregisterClassW(window->klassName, instance);
    }
}