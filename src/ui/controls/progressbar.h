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
    ProgressBar *pbar, const POINT *position, const SIZE *size, const SIZE *margin,
    const SIZE *barMargin);

void blokProgressBarUpdate(ProgressBar *pbar, const POINT *position);

void blokProgressBarUpdateMinMax(
    ProgressBar *pbar, const int minValue, const int maxValue);

void blokProgressBarUpdateValue(ProgressBar *pbar, const int value);

#endif // _BLOK_PROGRESSBAR_H_