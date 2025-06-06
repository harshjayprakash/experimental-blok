#ifndef _BLOK_RENDERTOOLS_H_
#define _BLOK_RENDERTOOLS_H_

#include "theme.h"
#include <windows.h>

typedef struct _RenderTools {
    struct {
        HBRUSH hBaseBackground;
        HBRUSH hBaseBackgroundFaded;
        HBRUSH hBaseBackgroundMedium;
        HBRUSH hPrimaryBackground;
        HBRUSH hPrimaryBackgroundFaded;
    } brushes;
    struct {
        HPEN hBaseForeground;
        HPEN hBaseBorder;
        HPEN hBaseBorderFaded;
        HPEN hPrimaryBorder;
        HPEN hPrimaryForeground;
    } pens;
} RenderTools;

int blokRenderToolsInit(RenderTools *pTools, const ThemePalette *pColours);

int blokRenderToolsFree(RenderTools *pTools);

#endif /* _BLOK_RENDERTOOLS_H_ */