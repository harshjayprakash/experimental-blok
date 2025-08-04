/**
 * @file   text.c
 * @brief  Text Implementation
 * @author harshjayprakash
 * @date   2025-08-04
 ****************************************************************************************/

#include "text.h"

int stTextUpdateEx(TText *pText, const POINT *pPoint, const SIZE *pSize,
                   const SIZE *pMargin)
{
    if (pText == NULL)
    {
        return 0;
    }

    if (pPoint != NULL)
    {
        pText->position.x = pPoint->x;
        pText->position.y = pPoint->y;
    }

    if (pSize != NULL)
    {
        pText->size.cx = pSize->cx;
        pText->size.cy = pSize->cy;
    }

    if (pMargin != NULL)
    {
        pText->margin.cx = pMargin->cx;
        pText->margin.cy = pMargin->cy;
    }

    pText->region.left = pText->position.x + pText->margin.cx;
    pText->region.top = pText->position.y + pText->margin.cy;
    pText->region.right = (pText->position.x + pText->size.cx) - pText->margin.cx;
    pText->region.bottom = (pText->position.y + pText->size.cy) - pText->margin.cx;

    return 1;
}

int stTextUpdate(TText *pText, const POINT *pPosition)
{
    if (pText == NULL || pPosition == NULL)
    {
        return 0;
    }

    return stTextUpdateEx(pText, pPosition, NULL, NULL);
}