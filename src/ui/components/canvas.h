#ifndef _BLOK_CANVAS_H_
#define _BLOK_CANVAS_H_

#include "../../model/vector.h"
#include <Windows.h>

typedef struct _Canvas {
    RECT region;
    SIZE size;
} Canvas;

void blokCanvasUpdate(Canvas *pCanvas, const RECT *pWindowRgn);

#endif // _BLOK_CANVAS_H_