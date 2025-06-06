#ifndef _BLOK_VIEWPORT_H_
#define _BLOK_VIEWPORT_H_

#include "controls/button.h"
#include "controls/text.h"
#include "controls/progressbar.h"
#include "controls/toggle.h"
#include "components/canvas.h"
#include "components/panel.h"
#include "frame/window.h"
#include <windows.h>

typedef struct _Viewport {
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

int blokViewportInit(TViewport *pViewport, HINSTANCE hInstance);

int blokViewportShow(TViewport *pViewport, DWORD showFlag);

int blokViewportFree(TViewport *pViewport, HINSTANCE hInstance);

#endif /* _BLOK_VIEWPORT_H_ */