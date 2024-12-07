#include "tools.h"
#include "colours.h"

void bkGraphicsToolsInit(bkGraphicsTools* pGfxTools)
{
	if (!pGfxTools) return;
	pGfxTools->darkBlueBrush = CreateSolidBrush(bkDarkBlue);
	pGfxTools->aquaBrush = CreateSolidBrush(bkAqua);
	pGfxTools->blackBrush = CreateSolidBrush(bkBlack);
	pGfxTools->whiteBrush = CreateSolidBrush(bkWhite);
}

void bkGraphicsToolsFree(bkGraphicsTools* pGfxTools)
{
	if (!pGfxTools) return;
	if (pGfxTools->darkBlueBrush) (void)DeleteObject(pGfxTools->darkBlueBrush);
	if (pGfxTools->aquaBrush) (void)DeleteObject(pGfxTools->aquaBrush);
	if (pGfxTools->blackBrush) (void)DeleteObject(pGfxTools->blackBrush);
	if (pGfxTools->whiteBrush) (void)DeleteObject(pGfxTools->whiteBrush);
}
