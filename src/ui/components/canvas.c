#include "canvas.h"

void blokCanvasUpdate(Canvas *pCanvas, const RECT *pWindowRgn)
{
    if (!pCanvas) { return; }
    if (!pWindowRgn) { return; }

    (void) CopyRect(&pCanvas->region, pWindowRgn);

    pCanvas->size.cx = pCanvas->region.right - pCanvas->region.left;
    pCanvas->size.cy = pCanvas->region.bottom - pCanvas->region.top;
}