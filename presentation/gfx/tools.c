#include "tools.h"
#include "colours.h"

void bkGraphicsToolsInit(bkGraphicsTools* pGfxTools)
{
	if (!pGfxTools) return;
	pGfxTools->darkBlueBrush = CreateSolidBrush(bkDarkBlue);
}

void bkGraphicsToolsFree(bkGraphicsTools* pGfxTools)
{
	if (!pGfxTools) return;
	if (pGfxTools->darkBlueBrush) (void)DeleteObject(pGfxTools->darkBlueBrush);
}
