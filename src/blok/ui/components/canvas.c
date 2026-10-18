#include "canvas.h"

int BlokCanvasUpdate(TCanvas *pCanvas, const RECT *pWindowRgn)
{
    if (pCanvas == NULL || pWindowRgn == NULL)
    {
        return 0;
    }

    if (CopyRect(&pCanvas->region, pWindowRgn) == FALSE)
    {
        return 0;
    }

    pCanvas->size.cx = pCanvas->region.right - pCanvas->region.left;
    pCanvas->size.cy = pCanvas->region.bottom - pCanvas->region.top;

    return 1;
}