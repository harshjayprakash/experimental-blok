#ifndef ST_VIEWPORT_H
#define ST_VIEWPORT_H

#include "controls/button.h"
#include "controls/text.h"
#include "controls/progressbar.h"
#include "controls/toggle.h"
#include "components/canvas.h"
#include "components/panel.h"
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

int stViewportInit(TViewport *pViewport, HINSTANCE hInstance);

int stViewportShow(TViewport *pViewport, DWORD showFlag);

int stViewportFree(TViewport *pViewport, HINSTANCE hInstance);

#endif /* ST_VIEWPORT_H */