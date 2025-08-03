/**
 * @file canvas.c
 * @brief Canvas Implementation.
 * @author harshjayprakash
 * @date 2025-07-23
 ****************************************************************************************/

#include "canvas.h"

int stCanvasUpdate(TCanvas *pCanvas, const RECT *pWindowRgn)
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