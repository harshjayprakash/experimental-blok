#include "toggle.h"


void blokToggleUpdateEx(
    Toggle *pToggle, const POINT *pPosition, const SIZE *pSize, const SIZE *pMargin, 
    const SIZE *pSelectMargin)
{
    if (!pToggle) { return; }

    if (pPosition != (POINT *) 0)
    {
        pToggle->position.x = pPosition->x;
        pToggle->position.y = pPosition->y;
    }

    if (pSize != (SIZE *) 0)
    {
        pToggle->size.cx = pSize->cx;
        pToggle->size.cy = pSize->cy;
    }

    if (pMargin != (SIZE *) 0)
    {
        pToggle->margin.cx = pMargin->cx;
        pToggle->margin.cy = pMargin->cy;
    }

    
    if (pSelectMargin != (SIZE *) 0)
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
}

void blokToggleUpdate(Toggle *pToggle, const POINT *pPosition)
{
    if (!pToggle) { return; }
    if (!pPosition) { return; }

    blokToggleUpdateEx(pToggle, pPosition, (SIZE *) 0, (SIZE *) 0, (SIZE *) 0);
}

void blokToggleUpdateSelected(Toggle *pToggle, const BOOL selected)
{
    if (!pToggle) { return; }

    pToggle->selected = selected;
}