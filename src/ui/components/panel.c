#include "panel.h"

void blokPanelUpdateEx(
    Panel *panel, const RECT *windowRegion, const COORD *size, const COORD *margin)
{
    if (!panel) { return; }
    if (!windowRegion) { return; }

    if (size != (COORD *) 0)
    {
        panel->size.X = size->X;
        panel->size.Y = size->Y;
    }

    if (margin != (COORD *) 0)
    {
        panel->margin.X = margin->X;
        panel->margin.Y = margin->Y;
    }

    panel->region.left = windowRegion->left + panel->margin.X;
    panel->region.top = (windowRegion->bottom - panel->size.Y) - panel->margin.Y;
    panel->region.right = (windowRegion->left + panel->size.X) - panel->margin.X;
    panel->region.bottom = windowRegion->bottom - panel->margin.Y;
}

void blokPanelUpdate(Panel *panel, const RECT *windowRegion)
{
    if (!panel) { return; }
    if (!windowRegion) { return; }

    blokPanelUpdateEx(panel, windowRegion, NULL, NULL);
}