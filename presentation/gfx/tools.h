#ifndef __BLOK_TOOLS_H
#define __BLOK_TOOLS_H

#define STRICT 1
#include <Windows.h>

typedef struct bkGraphicsTools
{
	HBRUSH darkBlueBrush;
} bkGraphicsTools;

void bkGraphicsToolsInit(bkGraphicsTools* pGfxTools);

void bkGraphicsToolsFree(bkGraphicsTools* pGfxTools);

#endif // !__BLOK_TOOLS_H
