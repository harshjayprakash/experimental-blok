#include "drawtools.h"

#define __BLOK_FREE_WINGDI_OBJECT(winGdiObject) \
    if (winGdiObject)                           \
    {                                           \
        (void) DeleteObject(winGdiObject);      \
        winGdiObject = (void *) 0;              \
    }                                           

void blokDrawingToolsInit(DrawingTools *pTools, const ColourSpace *pColours)
{
    if (!pTools) { return; }
    if (!pColours) { return; }

    pTools->hSurfaceBrush = CreateSolidBrush(pColours->surface);
    pTools->hSurfaceVariantBrush = CreateSolidBrush(pColours->surfaceVariant);
    pTools->hPrimaryBrush = CreateSolidBrush(pColours->primary);
    pTools->hPrimaryVariantBrush = CreateSolidBrush(pColours->primaryVariant);
    pTools->hSecondaryBrush = CreateSolidBrush(pColours->secondary);
    pTools->hSecondaryVariantBrush = CreateSolidBrush(pColours->secondaryVariant);
    pTools->hOnSurfacePen = CreatePen(PS_SOLID, 1, pColours->onSurface);
    pTools->hOnSurfaceVariantPen = CreatePen(PS_SOLID, 1, pColours->onSurfaceVariant);
    pTools->hOnPrimaryPen = CreatePen(PS_SOLID, 1, pColours->primary);
    pTools->hOnPrimaryVariantPen = CreatePen(PS_SOLID, 1, pColours->primaryVariant);
}

void blokDrawingToolsFree(DrawingTools *pTools)
{
    if (!pTools) { return; }

    BLOK_FREE_WINGDI_OBJECT(pTools->hSurfaceBrush);
    BLOK_FREE_WINGDI_OBJECT(pTools->hSurfaceVariantBrush);
    BLOK_FREE_WINGDI_OBJECT(pTools->hPrimaryBrush);
    BLOK_FREE_WINGDI_OBJECT(pTools->hPrimaryVariantBrush);
    BLOK_FREE_WINGDI_OBJECT(pTools->hSecondaryBrush);
    BLOK_FREE_WINGDI_OBJECT(pTools->hSecondaryVariantBrush);
    BLOK_FREE_WINGDI_OBJECT(pTools->hOnSurfacePen);
    BLOK_FREE_WINGDI_OBJECT(pTools->hOnSurfaceVariantPen);
    BLOK_FREE_WINGDI_OBJECT(pTools->hOnPrimaryPen);
    BLOK_FREE_WINGDI_OBJECT(pTools->hOnPrimaryVariantPen);
}