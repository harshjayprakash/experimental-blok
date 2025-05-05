#include "canvas.h"

int blokCanvasUpdate(Canvas *pCanvas, const RECT *pWindowRgn)
{
    if (pCanvas == NULL)
        return 0;

    if (pWindowRgn == NULL)
        return 0;

    (void) CopyRect(&pCanvas->region, pWindowRgn);

    pCanvas->size.cx = pCanvas->region.right - pCanvas->region.left;
    pCanvas->size.cy = pCanvas->region.bottom - pCanvas->region.top;

    return 1;
}