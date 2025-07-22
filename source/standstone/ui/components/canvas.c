#include "canvas.h"

int stCanvasUpdate(
    TCanvas *pCanvas,
    const RECT *pWindowRgn)
{
    if (pCanvas == NULL || pWindowRgn == NULL)
    {
        return 0;
    }

    BOOL success = CopyRect(&pCanvas->region, pWindowRgn);
    
    if (!success)
    {
        return 0;
    }

    pCanvas->size.cx = pCanvas->region.right - pCanvas->region.left;
    pCanvas->size.cy = pCanvas->region.bottom - pCanvas->region.top;

    return 1;
}