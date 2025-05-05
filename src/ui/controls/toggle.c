#include "toggle.h"


int blokToggleUpdateEx(
    Toggle *pToggle, const POINT *pPosition, const SIZE *pSize, const SIZE *pMargin, 
    const SIZE *pSelectMargin)
{
    if (pToggle == NULL)
        return 0;

    if (pPosition != NULL)
    {
        pToggle->position.x = pPosition->x;
        pToggle->position.y = pPosition->y;
    }

    if (pSize != NULL)
    {
        pToggle->size.cx = pSize->cx;
        pToggle->size.cy = pSize->cy;
    }

    if (pMargin != NULL)
    {
        pToggle->margin.cx = pMargin->cx;
        pToggle->margin.cy = pMargin->cy;
    }

    
    if (pSelectMargin != NULL)
    {
        pToggle->selectMargin.cx = pSelectMargin->cx;
        pToggle->selectMargin.cy = pSelectMargin->cy;
    }

    pToggle->region.left = pToggle->position.x + pToggle->margin.cx;
    pToggle->region.top = pToggle->position.y + pToggle->margin.cy;
    pToggle->region.right = (pToggle->position.x + pToggle->size.cx) - pToggle->margin.cx;
    pToggle->region.bottom = (pToggle->position.y + pToggle->size.cy) - pToggle->margin.cx;

    (void) CopyRect(&pToggle->selectRegion, &pToggle->region);

    pToggle->selectRegion.left += pToggle->selectMargin.cx;
    pToggle->selectRegion.top += pToggle->selectMargin.cy;
    pToggle->selectRegion.right -= pToggle->selectMargin.cx;
    pToggle->selectRegion.bottom -= pToggle->selectMargin.cy;

    return 1;
}

int blokToggleUpdate(Toggle *pToggle, const POINT *pPosition)
{
    if (pToggle == NULL)
        return 0;

    if (pPosition == NULL)
        return 0;

    return blokToggleUpdateEx(pToggle, pPosition, NULL, NULL, NULL);
}

int blokToggleUpdateSelected(Toggle *pToggle, const BOOL selected)
{
    if (pToggle == NULL)
        return 0;

    pToggle->selected = selected;

    return 1;
}