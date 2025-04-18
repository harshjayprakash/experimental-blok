#ifndef _BLOK_VIEWPORT_H_
#define _BLOK_VIEWPORT_H_

#include "controls/button.h"
#include "controls/text.h"
#include "controls/progressbar.h"
#include "controls/toggle.h"
#include "components/canvas.h"
#include "components/panel.h"
#include "frame/window.h"
#include <Windows.h>

typedef struct _Viewport {
    Window window;
    RECT region;
    COORD mousePos;
    HFONT font;
    BOOL mouseDown;

    Canvas canvas;
    int isCanvasLocked;
    int isGridVisible;

    Panel panel;
    int isInterfaceVisible;
    Text coordinatesText;
    Button clearAllButton;
    Button generateButton;
    Text obstructCountText;
    ProgressBar obstructMemoryBar;
    Text lockedToggleText;
    Toggle lockedToggle;
} Viewport;

void BlokViewportInit(Viewport *viewport, HINSTANCE instance);

void BlokViewportShow(Viewport *viewport, DWORD showFlag);

void BlokViewportFree(Viewport *viewport, HINSTANCE instance);

#endif // _BLOK_VIEWPORT_H_