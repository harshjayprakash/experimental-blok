#ifndef _BLOK_RENDERTOOLS_H_
#define _BLOK_RENDERTOOLS_H_

#include "theme.h"
#include <windows.h>

typedef struct _RenderTools {
    struct _Brushes {
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
    struct _Pens {
    struct _Pens
    {
        HPEN hBaseForeground;
        HPEN hBaseBorder;
        HPEN hBaseBorderFaded;
        HPEN hPrimaryBorder;
        HPEN hPrimaryForeground;
    } pens;
} TRenderTools;

int blokRenderToolsInit(TRenderTools *pTools, const TThemePalette *pColours);

int blokRenderToolsFree(TRenderTools *pTools);

#endif /* _BLOK_RENDERTOOLS_H_ */