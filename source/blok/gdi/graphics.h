#ifndef _BLOK_GRAPHICS_H_
#define _BLOK_GRAPHICS_H_

#include "theme.h"
#include "drawtools.h"

typedef struct _Graphics {
    Theme theme;
    ColourSpace colours;
    DrawingTools tools;
} Graphics;

int blokGraphicsInit(Graphics *pGraphics, const Theme theme);

int blokGraphicsFree(Graphics *pGraphics);

#endif // _BLOK_GRAPHICS_H_