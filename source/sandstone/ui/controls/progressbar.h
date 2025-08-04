/**
 * @file   progressbar.h
 * @brief  Progress Bar Declarations
 * @author harshjayprakash
 * @date   2025-08-04
 ****************************************************************************************/

#ifndef ST_PROGRESSBAR_H
#define ST_PROGRESSBAR_H

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

int stProgressBarUpdateEx(TProgressBar *pPbar, const POINT *pPosition, const SIZE *pSize,
                          const SIZE *pMargin, const SIZE *pBarMargin);

int stProgressBarUpdate(TProgressBar *pPbar, const POINT *pPosition);

int stProgressBarUpdateValueEx(TProgressBar *pPbar, const int minValue,
                               const int maxValue, const int value);

int stProgressBarUpdateMinMax(TProgressBar *pPbar, const int minValue,
                              const int maxValue);

int stProgressBarUpdateValue(TProgressBar *pPbar, const int value);

#endif /* ST_PROGRESSBAR_H */