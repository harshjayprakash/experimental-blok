#ifndef __BLOK_PANEL_H
#define __BLOK_PANEL_H

#include <Windows.h>

typedef struct bkPanel
{
	RECT region;
	int show;
} bkPanel;

void bkComponentPanelInit(bkPanel* pPanel);

void bkComponentPanelRender(bkPanel* pPanel);

void bkComponentPanelFree(bkPanel* pPanel);

#endif // !__BLOK_PANEL_H
