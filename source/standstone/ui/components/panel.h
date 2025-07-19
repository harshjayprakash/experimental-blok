#ifndef ST_PANEL_H
#define ST_PANEL_H

#include <windows.h>

typedef struct _Panel
{
    RECT region;
    SIZE margin;
    POINT position;
    SIZE size;
} TPanel;

int stPanelUpdateEx(
    TPanel *pPanel, const RECT *pWindowRgn, const SIZE *pSize, const SIZE *pMargin);

int stPanelUpdate(TPanel *pPanel, const RECT *pWindowRgn);

#endif /* ST_PANEL_H */