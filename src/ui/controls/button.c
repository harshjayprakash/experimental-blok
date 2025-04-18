#include "button.h"

void BlokButtonUpdateEx(Button *button, const POINT *pos, const SIZE *size, const SIZE *margin)
{
    if (!button) { return; }

    if (pos != (POINT *) 0)
    {
        button->position.x = pos->x;
        button->position.y = pos->y;
    }

    if (size != (SIZE *) 0)
    {
        button->size.cx = size->cx;
        button->size.cy = size->cy;
    }

    if (margin != (SIZE *) 0)
    {
        button->margin.cx = margin->cx;
        button->margin.cy = margin->cy;
    }

    button->region.left = button->position.x + button->margin.cx;
    button->region.top = button->position.y + button->margin.cy;
    button->region.right = (button->position.x + button->size.cx) - button->margin.cx;
    button->region.bottom = (button->position.y + button->size.cy) - button->margin.cx;
}

void BlokButtonUpdate(Button *button, const POINT *position)
{
    if (!button) { return; }
    if (!position) { return; }

    BlokButtonUpdateEx(button, position, (SIZE *) 0, (SIZE *) 0);
}