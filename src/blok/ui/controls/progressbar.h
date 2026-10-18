#ifndef BLOK_PROGRESSBAR_H
#define BLOK_PROGRESSBAR_H

#include <windows.h>

typedef struct _ProgressBar
{
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
} TProgressBar;

int BlokProgressBarUpdateEx(TProgressBar *pPbar, const POINT *pPosition, const SIZE *pSize,
                          const SIZE *pMargin, const SIZE *pBarMargin);

int BlokProgressBarUpdate(TProgressBar *pPbar, const POINT *pPosition);

int BlokProgressBarUpdateValueEx(TProgressBar *pPbar, const int minValue,
                               const int maxValue, const int value);

int BlokProgressBarUpdateMinMax(TProgressBar *pPbar, const int minValue,
                              const int maxValue);

int BlokProgressBarUpdateValue(TProgressBar *pPbar, const int value);

#endif /* BLOK_PROGRESSBAR_H */