#include "progressbar.h"

void BlokProgressBarUpdateEx(
    ProgressBar *pbar, const POINT *position, const SIZE *size, const SIZE *margin,
    const SIZE *barMargin
)
{
    if (!pbar) { return; }

    if (position != (POINT *) 0)
    {
        pbar->position.x = position->x;
        pbar->position.y = position->y;
    }

    if (size != (SIZE *) 0)
    {
        pbar->size.cx = size->cx;
        pbar->size.cy = size->cy;
    }

    if (margin != (SIZE *) 0)
    {
        pbar->margin.cx = margin->cx;
        pbar->margin.cy = margin->cy;
    }

    if (barMargin != (SIZE *) 0)
    {
        pbar->barMargin.cx = barMargin->cx;
        pbar->barMargin.cy = barMargin->cy;
    }

    pbar->region.left = pbar->position.x + pbar->margin.cx;
    pbar->region.top = pbar->position.y + pbar->margin.cy;
    pbar->region.right = (pbar->position.x + pbar->size.cx) - pbar->margin.cx;
    pbar->region.bottom = (pbar->position.y + pbar->size.cy) - pbar->margin.cx;

    (void) CopyRect(&pbar->barRegion, &pbar->region);

    pbar->barRegion.left += pbar->barMargin.cx;
    pbar->barRegion.top += pbar->barMargin.cy;
    pbar->barRegion.right -= pbar->barMargin.cx;
    pbar->barRegion.bottom -= pbar->barMargin.cy;

    pbar->barMinPoint = (pbar->region.left + pbar->barMargin.cx);
    pbar->barMaxPoint = (pbar->region.right - pbar->barMargin.cx);
    pbar->barMaxSize = pbar->barMaxPoint - pbar->barMinPoint;
}

void BlokProgressBarUpdate(ProgressBar *pbar, const POINT *position)
{
    if (!pbar) { return; }
    if (!position) { return; }

    BlokProgressBarUpdateEx(pbar, position, (SIZE *) 0, (SIZE *) 0, (SIZE *)0);
}

void BlokProgressBarUpdateMinMax(
    ProgressBar *pbar, const int minValue, const int maxValue)
{
    if (!pbar) { return; }

    pbar->barMinValue = minValue;
    pbar->barMaxValue = maxValue;
}

void BlokProgressBarUpdateValue(ProgressBar *pbar, const int value)
{
    if (!pbar) { return; }

    pbar->barValue = value;
    float percent = (float) pbar->barValue / (pbar->barMaxValue - pbar->barMinValue);
    pbar->barRegion.right = pbar->barRegion.left + ((LONG)(pbar->barMaxSize * percent));
}