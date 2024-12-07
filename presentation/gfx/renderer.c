#include "renderer.h"

void bkRendererInit(bkRenderer* pRenderer)
{
	if (!pRenderer) return;
	bkGraphicsToolsInit(&pRenderer->tools);
}

void bkRendererPaint(bkRenderer* pRenderer, bkState* state, HDC hDeviceContext, const RECT kWindowArea)
{
	if (!pRenderer || !state) return;
	(void)FillRect(hDeviceContext, &kWindowArea, pRenderer->tools.darkBlueBrush);
}

void bkRendererFree(bkRenderer* pRenderer)
{
	if (!pRenderer) return;
	bkGraphicsToolsFree(&pRenderer->tools);
}
