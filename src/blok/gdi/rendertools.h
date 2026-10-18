#ifndef BLOK_RENDERTOOLS_H
#define BLOK_RENDERTOOLS_H

#include "theme.h"
#include <windows.h>

typedef struct _RenderTools
{
    struct _Brushes
    {
        HBRUSH hBaseBackground;
        HBRUSH hBaseBackgroundFaded;
        HBRUSH hBaseBackgroundMedium;
        HBRUSH hPrimaryBackground;
        HBRUSH hPrimaryBackgroundFaded;
    } brushes;
    struct _Pens
    {
        HPEN hBaseForeground;
        HPEN hBaseBorder;
        HPEN hBaseBorderFaded;
        HPEN hPrimaryBorder;
        HPEN hPrimaryForeground;
    } pens;
} TRenderTools;

int BlokRenderToolsInit(TRenderTools *pTools, const TThemePalette *pColours);

int BlokRenderToolsFree(TRenderTools *pTools);

#endif /* BLOK_RENDERTOOLS_H */