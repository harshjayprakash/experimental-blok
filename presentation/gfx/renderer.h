#ifndef __BLOK_RENDERER_H
#define __BLOK_RENDERER_H

#include <Windows.h>
#include "tools.h"
#include "../../service/state.h"

typedef struct bkRenderer
{
	bkGraphicsTools tools;
	RECT* pWindowArea;
} bkRenderer;

void bkRendererInit(bkRenderer* pRenderer);

void bkRendererPaint(bkRenderer* pRenderer, bkState* state, HDC hDeviceContext, const RECT kWindowArea);

void bkRendererFree(bkRenderer* pRenderer);

#endif // !__BLOK_RENDERER_H
