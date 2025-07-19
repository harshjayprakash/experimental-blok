#include "panel.h"

int stPanelUpdateEx(
    TPanel *pPanel,
    const RECT *pWindowRgn,
    const SIZE *pSize,
    const SIZE *pMargin)
{
    if (pPanel == NULL)
    {
        return 0;
    }

    if (pWindowRgn == NULL)
    {
        return 0;
    }

    if (pSize != NULL)
    {
        pPanel->size.cx = pSize->cx;
        pPanel->size.cy = pSize->cy;
    }

    if (pMargin != NULL)
    {
        pPanel->margin.cx = pMargin->cx;
        pPanel->margin.cy = pMargin->cy;
    }

    pPanel->region.left = pWindowRgn->left + pPanel->margin.cx;
    pPanel->region.top = (pWindowRgn->bottom - pPanel->size.cy) - pPanel->margin.cy;
    pPanel->region.right = (pWindowRgn->left + pPanel->size.cx) - pPanel->margin.cx;
    pPanel->region.bottom = pWindowRgn->bottom - pPanel->margin.cy;

    return 1;
}

int stPanelUpdate(
    TPanel *pPanel,
    const RECT *pWindowRgn)
{
    if (pPanel == NULL)
    {
        return 0;
    }

    if (pWindowRgn == NULL)
    {
        return 0;
    }

    return stPanelUpdateEx(pPanel, pWindowRgn, NULL, NULL);
}