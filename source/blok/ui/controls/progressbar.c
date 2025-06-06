#include "progressbar.h"

int blokProgressBarUpdateEx(
    TProgressBar *pPbar,
    const POINT *pPosition,
    const SIZE *pSize,
    const SIZE *pMargin,
    const SIZE *pBarMargin)
{
    if (pPbar == NULL) {
        return 0;
    }

    if (pPosition != NULL) {
        pPbar->position.x = pPosition->x;
        pPbar->position.y = pPosition->y;
    }

    if (pSize != NULL) {
        pPbar->size.cx = pSize->cx;
        pPbar->size.cy = pSize->cy;
    }

    if (pMargin != NULL) {
        pPbar->margin.cx = pMargin->cx;
        pPbar->margin.cy = pMargin->cy;
    }

    if (pBarMargin != NULL) {
        pPbar->barMargin.cx = pBarMargin->cx;
        pPbar->barMargin.cy = pBarMargin->cy;
    }

    pPbar->region.left = pPbar->position.x + pPbar->margin.cx;
    pPbar->region.top = pPbar->position.y + pPbar->margin.cy;
    pPbar->region.right = (pPbar->position.x + pPbar->size.cx) - pPbar->margin.cx;
    pPbar->region.bottom = (pPbar->position.y + pPbar->size.cy) - pPbar->margin.cx;

    (void)CopyRect(&pPbar->barRegion, &pPbar->region);

    pPbar->barRegion.left += pPbar->barMargin.cx;
    pPbar->barRegion.top += pPbar->barMargin.cy;
    pPbar->barRegion.right -= pPbar->barMargin.cx;
    pPbar->barRegion.bottom -= pPbar->barMargin.cy;

    pPbar->barMinPoint = (pPbar->region.left + pPbar->barMargin.cx);
    pPbar->barMaxPoint = (pPbar->region.right - pPbar->barMargin.cx);
    pPbar->barMaxSize = pPbar->barMaxPoint - pPbar->barMinPoint;

    return 1;
}

int blokProgressBarUpdate(
    TProgressBar *pPbar,
    const POINT *pPosition)
{
    if (pPbar == NULL) {
        return 0;
    }

    if (pPosition == NULL) {
        return 0;
    }

    return blokProgressBarUpdateEx(pPbar, pPosition, NULL, NULL, NULL);
}

int blokProgressBarUpdateMinMax(
    TProgressBar *pPbar,
    const int minValue,
    const int maxValue)
{
    if (pPbar == NULL) {
        return 0;
    }

    pPbar->barMinValue = minValue;
    pPbar->barMaxValue = maxValue;

    return 1;
}

int blokProgressBarUpdateValue(
    TProgressBar *pPbar,
    const int value)
{
    if (pPbar == NULL) {
        return 0;
    }

    pPbar->barValue = value;
    float percent = (float) pPbar->barValue / (pPbar->barMaxValue - pPbar->barMinValue);
    pPbar->barRegion.right = pPbar->barRegion.left + ((LONG)(pPbar->barMaxSize * percent));

    return 1;
}