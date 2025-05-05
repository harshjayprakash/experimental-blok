#include "text.h"

void blokTextUpdateEx(Text *pText, const POINT *pPoint, const SIZE *pSize, const SIZE *pMargin)
{
    if (!pText) { return; }

    if (pPoint != (POINT *) 0)
    {
        pText->position.x = pPoint->x;
        pText->position.y = pPoint->y;
    }

    if (pSize != (SIZE *) 0)
    {
        pText->size.cx = pSize->cx;
        pText->size.cy = pSize->cy;
    }

    if (pMargin != (SIZE *) 0)
    {
        pText->margin.cx = pMargin->cx;
        pText->margin.cy = pMargin->cy;
    }

    pText->region.left = pText->position.x + pText->margin.cx;
    pText->region.top = pText->position.y + pText->margin.cy;
    pText->region.right = (pText->position.x + pText->size.cx) - pText->margin.cx;
    pText->region.bottom = (pText->position.y + pText->size.cy) - pText->margin.cx;
}

void blokTextUpdate(Text *text, const POINT *position)
{
    if (!text) { return; }
    if (!position) { return; }

    blokTextUpdateEx(text, position, (SIZE *) 0, (SIZE *) 0);
}