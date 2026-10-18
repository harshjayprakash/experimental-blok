#ifndef BLOK_PANEL_H
#define BLOK_PANEL_H

#include <windows.h>

typedef struct _Panel
{
    RECT region;
    SIZE margin;
    POINT position;
    SIZE size;
} TPanel;

int BlokPanelUpdateEx(TPanel *pPanel, const RECT *pWindowRgn, const SIZE *pSize,
                    const SIZE *pMargin);

int BlokPanelUpdate(TPanel *pPanel, const RECT *pWindowRgn);

#endif /* BLOK_PANEL_H */