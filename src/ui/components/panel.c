#include "panel.h"

void blokPanelUpdateEx(
    Panel *pPanel, const RECT *pWindowRgn, const COORD *pSize, const COORD *pMargin)
{
    if (!pPanel) { return; }
    if (!pWindowRgn) { return; }

    if (pSize != (COORD *) 0)
    {
        pPanel->size.X = pSize->X;
        pPanel->size.Y = pSize->Y;
    }

    if (pMargin != (COORD *) 0)
    {
        pPanel->margin.X = pMargin->X;
        pPanel->margin.Y = pMargin->Y;
    }

    pPanel->region.left = pWindowRgn->left + pPanel->margin.X;
    pPanel->region.top = (pWindowRgn->bottom - pPanel->size.Y) - pPanel->margin.Y;
    pPanel->region.right = (pWindowRgn->left + pPanel->size.X) - pPanel->margin.X;
    pPanel->region.bottom = pWindowRgn->bottom - pPanel->margin.Y;
}

void blokPanelUpdate(Panel *pPanel, const RECT *pWindowRgn)
{
    if (!pPanel) { return; }
    if (!pWindowRgn) { return; }

    blokPanelUpdateEx(pPanel, pWindowRgn, NULL, NULL);
}