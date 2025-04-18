#include "text.h"

void BlokTextUpdateEx(Text *text, const POINT *point, const SIZE *size, const SIZE *margin)
{
    if (!text) { return; }

    if (point != (POINT *) 0)
    {
        text->position.x = point->x;
        text->position.y = point->y;
    }

    if (size != (SIZE *) 0)
    {
        text->size.cx = size->cx;
        text->size.cy = size->cy;
    }

    if (margin != (SIZE *) 0)
    {
        text->margin.cx = margin->cx;
        text->margin.cy = margin->cy;
    }

    text->region.left = text->position.x + text->margin.cx;
    text->region.top = text->position.y + text->margin.cy;
    text->region.right = (text->position.x + text->size.cx) - text->margin.cx;
    text->region.bottom = (text->position.y + text->size.cy) - text->margin.cx;
}

void BlokTextUpdate(Text *text, const POINT *position)
{
    if (!text) { return; }
    if (!position) { return; }

    BlokTextUpdateEx(text, position, (SIZE *) 0, (SIZE *) 0);
}