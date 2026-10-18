#ifndef BLOK_VIEWPORT_H
#define BLOK_VIEWPORT_H

#include "components/canvas.h"
#include "components/panel.h"
#include "controls/button.h"
#include "controls/progressbar.h"
#include "controls/text.h"
#include "controls/toggle.h"
#include "frame/window.h"
#include <windows.h>

typedef struct _Viewport
{
    TWindow window;
    RECT region;
    POINT mousePos;
    HFONT hFont;
    BOOL isLeftMouseDown;
    BOOL isRightMouseDown;
    TCanvas canvas;
    BOOL isCanvasLocked;
    BOOL isGridVisible;
    TPanel panel;
    BOOL isInterfaceVisible;
    TText coordinatesText;
    TButton clearAllButton;
    TButton generateButton;
    TText obstructCountText;
    TProgressBar obstructMemoryBar;
    TText lockedToggleText;
    TToggle lockedToggle;
} TViewport;

int BlokViewportInit(TViewport *pViewport, HINSTANCE hInstance);

int BlokViewportShow(TViewport *pViewport, DWORD showFlag);

int BlokViewportFree(TViewport *pViewport, HINSTANCE hInstance);

#endif /* BLOK_VIEWPORT_H */