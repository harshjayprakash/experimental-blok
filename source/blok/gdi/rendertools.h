#ifndef _BLOK_GDI_RENDER_TOOLS_H_
#define _BLOK_GDI_RENDER_TOOLS_H_

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

int zblokRenderToolsInit(RenderTools *pTools, const ThemePalette *pColours);

int zblokRenderToolsFree(RenderTools *pTools);

#endif // _BLOK_GDI_RENDER_TOOLS_H_