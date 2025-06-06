#ifndef _BLOK_PANEL_H_
#define _BLOK_PANEL_H_

#include <windows.h>

typedef struct _Panel {
    RECT region;
    SIZE margin;
    POINT position;
    SIZE size;
} Panel;

int blokPanelUpdateEx(
    Panel *pPanel, const RECT *pWindowRgn, const SIZE *pSize, const SIZE *pMargin);

int blokPanelUpdate(Panel *pPanel, const RECT *pWindowRgn);

#endif // _BLOK_PANEL_H_