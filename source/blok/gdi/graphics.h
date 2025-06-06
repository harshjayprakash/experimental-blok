#ifndef _BLOK_GRAPHICS_H_
#define _BLOK_GRAPHICS_H_

#include "theme.h"
#include "rendertools.h"

typedef struct _Graphics {
    TTheme currentTheme;
    TRenderTools renderTools;
    TThemePalette palette;
} TGraphics;

int blokGraphicsInit(TGraphics *pGraphics, const TTheme theme);

int blokGraphicsFree(TGraphics *pGraphics);

#endif /* _BLOK_GRAPHICS_H_ */