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

void BlokPanelUpdateEx(
    Panel *panel, const RECT *windowRegion, const COORD *size, const COORD *margin);

void BlokPanelUpdate(Panel *panel, const RECT *windowRegion);

#endif // _BLOK_PANEL_H_