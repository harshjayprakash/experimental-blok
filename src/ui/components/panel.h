#ifndef _BLOK_PANEL_H_
#define _BLOK_PANEL_H_

#include "../../model/vector.h"
#include <Windows.h>

typedef struct _Panel {
    RECT region;
    COORD margin;
    COORD position;
    COORD size;
} Panel;

int blokPanelUpdateEx(
    Panel *pPanel, const RECT *pWindowRgn, const COORD *pSize, const COORD *pMargin);

int blokPanelUpdate(Panel *pPanel, const RECT *pWindowRgn);

#endif // _BLOK_PANEL_H_