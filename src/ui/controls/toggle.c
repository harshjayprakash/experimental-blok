#include "toggle.h"


void BlokToggleUpdateEx(
    Toggle *toggle, const POINT *position, const SIZE *size, const SIZE *margin, 
    const SIZE *selectMargin)
{
    if (!toggle) { return; }

    if (position != (POINT *) 0)
    {
        toggle->position.x = position->x;
        toggle->position.y = position->y;
    }

    if (size != (SIZE *) 0)
    {
        toggle->size.cx = size->cx;
        toggle->size.cy = size->cy;
    }

    if (margin != (SIZE *) 0)
    {
        toggle->margin.cx = margin->cx;
        toggle->margin.cy = margin->cy;
    }

    
    if (selectMargin != (SIZE *) 0)
    {
        toggle->selectMargin.cx = selectMargin->cx;
        toggle->selectMargin.cy = selectMargin->cy;
    }

    toggle->region.left = toggle->position.x + toggle->margin.cx;
    toggle->region.top = toggle->position.y + toggle->margin.cy;
    toggle->region.right = (toggle->position.x + toggle->size.cx) - toggle->margin.cx;
    toggle->region.bottom = (toggle->position.y + toggle->size.cy) - toggle->margin.cx;

    (void) CopyRect(&toggle->selectRegion, &toggle->region);

    toggle->selectRegion.left += toggle->selectMargin.cx;
    toggle->selectRegion.top += toggle->selectMargin.cy;
    toggle->selectRegion.right -= toggle->selectMargin.cx;
    toggle->selectRegion.bottom -= toggle->selectMargin.cy;
}

void BlokToggleUpdate(Toggle *toggle, const POINT *position)
{
    if (!toggle) { return; }
    if (!position) { return; }

    BlokToggleUpdateEx(toggle, position, (SIZE *) 0, (SIZE *) 0, (SIZE *) 0);
}

void BlokToggleUpdateSelected(Toggle *toggle, const BOOL selected)
{
    if (!toggle) { return; }

    toggle->selected = selected;
}