#ifndef __BLOK_CANVAS_H
#define __BLOK_CANVAS_H

typedef struct bkCanvas
{
	int locked;
} bkCanvas;

void bkComponentCanvasInit(bkCanvas* pCanvas);

void bkComponentCanvasRender(bkCanvas* pCanvas);

void bkComponentCanvasFree(bkCanvas* pCanvas);

#endif // !__BLOK_CANVAS_H
