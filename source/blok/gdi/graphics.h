#ifndef _BLOK_GRAPHICS_H_
#define _BLOK_GRAPHICS_H_

#include "theme.h"
#include "drawtools.h"
#include "rendertools.h"

typedef struct _Graphics {
    Theme theme;
    ColourSpace colours;
    DrawingTools tools;
    RenderTools ztools;
    ThemePalette zcolours;
} Graphics;

int blokGraphicsInit(Graphics *pGraphics, const Theme theme);

int blokGraphicsFree(Graphics *pGraphics);

#endif // _BLOK_GRAPHICS_H_