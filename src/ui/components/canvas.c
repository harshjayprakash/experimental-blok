#include "canvas.h"

void BlokCanvasUpdate(Canvas *canvas, const RECT *windowRegion)
{
    if (!canvas) { return; }
    if (!windowRegion) { return; }

    (void) CopyRect(&canvas->region, windowRegion);

    canvas->size.cx = canvas->region.right - canvas->region.left;
    canvas->size.cy = canvas->region.bottom - canvas->region.top;
}