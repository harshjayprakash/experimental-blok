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

	RECT user = {
		state->user.position.x,
		state->user.position.y,
		state->user.position.x + state->user.size.width,
		state->user.position.y + state->user.size.height
	};
	(void)FillRect(hDeviceContext, &user, pRenderer->tools.aquaBrush);

	(void)SelectObject(hDeviceContext, pRenderer->tools.darkBlueBrush);
	(void)SelectObject(hDeviceContext, pRenderer->tools.greyPen);
	if (state->showInterface)
	{
		(void)Rectangle(
			hDeviceContext,
			kWindowArea.left + 10,
			kWindowArea.bottom - 60,
			kWindowArea.right - 10,
			kWindowArea.bottom - 10
		);
	}
}

void bkRendererFree(bkRenderer* pRenderer)
{
	if (!pRenderer) return;
	bkGraphicsToolsFree(&pRenderer->tools);
}
