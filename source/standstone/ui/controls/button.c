#include "button.h"

int stButtonUpdateEx(
    TButton *pButton,
    const POINT *pPos,
    const SIZE *pSize,
    const SIZE *pMargin)
{
    if (pButton == NULL)
    {
        return 0;
    }

    if (pPos != NULL)
    {
        pButton->position.x = pPos->x;
        pButton->position.y = pPos->y;
    }

    if (pSize != NULL)
    {
        pButton->size.cx = pSize->cx;
        pButton->size.cy = pSize->cy;
    }

    if (pMargin != NULL)
    {
        pButton->margin.cx = pMargin->cx;
        pButton->margin.cy = pMargin->cy;
    }

    pButton->region.left = pButton->position.x + pButton->margin.cx;
    pButton->region.top = pButton->position.y + pButton->margin.cy;
    pButton->region.right = (pButton->position.x + pButton->size.cx) - pButton->margin.cx;
    pButton->region.bottom = (pButton->position.y + pButton->size.cy) - pButton->margin.cx;

    return 1;
}

int stButtonUpdate(
    TButton *pButton,
    const POINT *pPos)
{
    if (pButton == NULL || pPos == NULL)
    {
        return 0;
    }

    return stButtonUpdateEx(pButton, pPos, NULL, NULL);
}