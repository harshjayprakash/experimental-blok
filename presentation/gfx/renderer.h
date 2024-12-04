#ifndef __BLOK_RENDERER_H
#define __BLOK_RENDERER_H

#include <Windows.h>
#include "tools.h"

typedef struct bkRenderer
{
	bkGraphicsTools tools;
	RECT* pWindowArea;
} bkRenderer;
#endif // !__BLOK_RENDERER_H
