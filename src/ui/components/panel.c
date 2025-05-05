#include "panel.h"

int blokPanelUpdateEx(
    Panel *pPanel, const RECT *pWindowRgn, const COORD *pSize, const COORD *pMargin)
{
    if (pPanel == NULL)
        return 0;

    if (pWindowRgn == NULL)
        return 0;

    if (pSize != NULL)
    {
        pPanel->size.X = pSize->X;
        pPanel->size.Y = pSize->Y;
    }

    if (pMargin != NULL)
    {
        pPanel->margin.X = pMargin->X;
        pPanel->margin.Y = pMargin->Y;
    }

    pPanel->region.left = pWindowRgn->left + pPanel->margin.X;
    pPanel->region.top = (pWindowRgn->bottom - pPanel->size.Y) - pPanel->margin.Y;
    pPanel->region.right = (pWindowRgn->left + pPanel->size.X) - pPanel->margin.X;
    pPanel->region.bottom = pWindowRgn->bottom - pPanel->margin.Y;

    return 1;
}

int blokPanelUpdate(Panel *pPanel, const RECT *pWindowRgn)
{
    if (pPanel == NULL)
        return 0;

    if (pWindowRgn == NULL)
        return 0;

    return blokPanelUpdateEx(pPanel, pWindowRgn, NULL, NULL);
}