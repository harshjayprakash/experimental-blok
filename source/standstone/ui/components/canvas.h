#ifndef ST_CANVAS_H
#define ST_CANVAS_H

#include <windows.h>

typedef struct _Canvas
{
    RECT region;
    SIZE size;
} TCanvas;

int stCanvasUpdate(TCanvas *pCanvas, const RECT *pWindowRgn);

#endif /* ST_CANVAS_H */