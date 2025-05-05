#ifndef _BLOK_PROGRESSBAR_H_
#define _BLOK_PROGRESSBAR_H_

#include <Windows.h>

typedef struct _ProgressBar {
    RECT region;
    POINT position;
    SIZE size;
    SIZE margin;
    RECT barRegion;
    SIZE barMargin;
    INT barMaxSize;
    INT barMaxPoint;
    INT barMinPoint;
    INT barMinValue;
    INT barMaxValue;
    INT barValue;
} ProgressBar;

void blokProgressBarUpdateEx(
    ProgressBar *pPbar, const POINT *pPosition, const SIZE *pSize, const SIZE *pMargin,
    const SIZE *pBarMargin);

void blokProgressBarUpdate(ProgressBar *pPbar, const POINT *pPosition);

void blokProgressBarUpdateMinMax(
    ProgressBar *pPbar, const int minValue, const int maxValue);

void blokProgressBarUpdateValue(ProgressBar *pPbar, const int value);

#endif // _BLOK_PROGRESSBAR_H_