#include "drawtools.h"

#define BLOK_DELETE_OBJECT(hObject)                                                      \
    if (hObject != NULL)                                                                 \
    {                                                                                    \
        (void) DeleteObject(hObject);                                                    \
        hObject = NULL;                                                                  \
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

    BLOK_DELETE_OBJECT(pTools->hSurfaceBrush);
    BLOK_DELETE_OBJECT(pTools->hSurfaceVariantBrush);
    BLOK_DELETE_OBJECT(pTools->hPrimaryBrush);
    BLOK_DELETE_OBJECT(pTools->hPrimaryVariantBrush);
    BLOK_DELETE_OBJECT(pTools->hSecondaryBrush);
    BLOK_DELETE_OBJECT(pTools->hSecondaryVariantBrush);
    BLOK_DELETE_OBJECT(pTools->hOnSurfacePen);
    BLOK_DELETE_OBJECT(pTools->hOnSurfaceVariantPen);
    BLOK_DELETE_OBJECT(pTools->hOnPrimaryPen);
    BLOK_DELETE_OBJECT(pTools->hOnPrimaryVariantPen);
}