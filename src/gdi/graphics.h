#ifndef _BLOK_GRAPHICS_H_
#define _BLOK_GRAPHICS_H_

#include "theme.h"
#include "drawtools.h"

typedef struct _Graphics {
    Theme theme;
    ColourSpace colours;
    DrawingTools tools;
} Graphics;

void blokGraphicsInit(Graphics *pGraphics, const Theme theme);

void blokGraphicsFree(Graphics *pGraphics);

#endif // _BLOK_GRAPHICS_H_