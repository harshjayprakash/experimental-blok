#ifndef _BLOK_DRAWTOOLS_H_
#define _BLOK_DRAWTOOLS_H_

#include "theme.h"
#include <Windows.h>

typedef struct _DrawingTools {
    HBRUSH hSurfaceBrush;
    HBRUSH hSurfaceVariantBrush;
    HBRUSH hPrimaryBrush;
    HBRUSH hPrimaryVariantBrush;
    HBRUSH hSecondaryBrush;
    HBRUSH hSecondaryVariantBrush;
    HPEN hOnSurfacePen;
    HPEN hOnSurfaceVariantPen;
    HPEN hOnPrimaryPen;
    HPEN hOnPrimaryVariantPen;
} DrawingTools;

int blokDrawingToolsInit(DrawingTools *pTools, const ColourSpace *pColours);

int blokDrawingToolsFree(DrawingTools *pTools);

#endif // _BLOK_DRAWTOOLS_H_