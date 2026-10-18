#ifndef BLOK_GRAPHICS_H
#define BLOK_GRAPHICS_H

#include "rendertools.h"
#include "theme.h"

typedef struct _Graphics
{
    TTheme currentTheme;
    TRenderTools renderTools;
    TThemePalette palette;
} TGraphics;

int BlokGraphicsInit(TGraphics *pGraphics, const TTheme theme);

int BlokGraphicsFree(TGraphics *pGraphics);

int BlokGraphicsSwitchTheme(TGraphics *pGraphics);

#endif /* BLOK_GRAPHICS_H */