#include "progressbar.h"

void blokProgressBarUpdateEx(
    ProgressBar *pPbar, const POINT *pPosition, const SIZE *pSize, const SIZE *pMargin,
    const SIZE *pBarMargin
)
{
    if (!pPbar) { return; }

    if (pPosition != (POINT *) 0)
    {
        pPbar->position.x = pPosition->x;
        pPbar->position.y = pPosition->y;
    }

    if (pSize != (SIZE *) 0)
    {
        pPbar->size.cx = pSize->cx;
        pPbar->size.cy = pSize->cy;
    }

    if (pMargin != (SIZE *) 0)
    {
        pPbar->margin.cx = pMargin->cx;
        pPbar->margin.cy = pMargin->cy;
    }

    if (pBarMargin != (SIZE *) 0)
    {
        pPbar->barMargin.cx = pBarMargin->cx;
        pPbar->barMargin.cy = pBarMargin->cy;
    }

    pPbar->region.left = pPbar->position.x + pPbar->margin.cx;
    pPbar->region.top = pPbar->position.y + pPbar->margin.cy;
    pPbar->region.right = (pPbar->position.x + pPbar->size.cx) - pPbar->margin.cx;
    pPbar->region.bottom = (pPbar->position.y + pPbar->size.cy) - pPbar->margin.cx;

    (void) CopyRect(&pPbar->barRegion, &pPbar->region);

    pPbar->barRegion.left += pPbar->barMargin.cx;
    pPbar->barRegion.top += pPbar->barMargin.cy;
    pPbar->barRegion.right -= pPbar->barMargin.cx;
    pPbar->barRegion.bottom -= pPbar->barMargin.cy;

    pPbar->barMinPoint = (pPbar->region.left + pPbar->barMargin.cx);
    pPbar->barMaxPoint = (pPbar->region.right - pPbar->barMargin.cx);
    pPbar->barMaxSize = pPbar->barMaxPoint - pPbar->barMinPoint;
}

void blokProgressBarUpdate(ProgressBar *pPbar, const POINT *pPosition)
{
    if (!pPbar) { return; }
    if (!pPosition) { return; }

    blokProgressBarUpdateEx(pPbar, pPosition, (SIZE *) 0, (SIZE *) 0, (SIZE *)0);
}

void blokProgressBarUpdateMinMax(
    ProgressBar *pPbar, const int minValue, const int maxValue)
{
    if (!pPbar) { return; }

    pPbar->barMinValue = minValue;
    pPbar->barMaxValue = maxValue;
}

void blokProgressBarUpdateValue(ProgressBar *pPbar, const int value)
{
    if (!pPbar) { return; }

    pPbar->barValue = value;
    float percent = (float) pPbar->barValue / (pPbar->barMaxValue - pPbar->barMinValue);
    pPbar->barRegion.right = pPbar->barRegion.left + ((LONG)(pPbar->barMaxSize * percent));
}