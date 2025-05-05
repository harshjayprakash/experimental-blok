#include "button.h"

void blokButtonUpdateEx(Button *pButton, const POINT *pPos, const SIZE *pSize, const SIZE *pMargin)
{
    if (!pButton) { return; }

    if (pPos != (POINT *) 0)
    {
        pButton->position.x = pPos->x;
        pButton->position.y = pPos->y;
    }

    if (pSize != (SIZE *) 0)
    {
        pButton->size.cx = pSize->cx;
        pButton->size.cy = pSize->cy;
    }

    if (pMargin != (SIZE *) 0)
    {
        pButton->margin.cx = pMargin->cx;
        pButton->margin.cy = pMargin->cy;
    }

    pButton->region.left = pButton->position.x + pButton->margin.cx;
    pButton->region.top = pButton->position.y + pButton->margin.cy;
    pButton->region.right = (pButton->position.x + pButton->size.cx) - pButton->margin.cx;
    pButton->region.bottom = (pButton->position.y + pButton->size.cy) - pButton->margin.cx;
}

void blokButtonUpdate(Button *pButton, const POINT *pPos)
{
    if (!pButton) { return; }
    if (!pPos) { return; }

    blokButtonUpdateEx(pButton, pPos, (SIZE *) 0, (SIZE *) 0);
}