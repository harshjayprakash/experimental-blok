#include "drawtools.h"

#define __BLOK_FREE_WINGDI_OBJECT(winGdiObject) \
    if (winGdiObject)                           \
    {                                           \
        (void) DeleteObject(winGdiObject);      \
        winGdiObject = (void *) 0;              \
    }                                           

void blokDrawingToolsInit(DrawingTools *tools, const ColourSpace *colours)
{
    if (!tools) { return; }
    if (!colours) { return; }

    tools->surfaceBrush = CreateSolidBrush(colours->surface);
    tools->surfaceVariantBrush = CreateSolidBrush(colours->surfaceVariant);
    tools->primaryBrush = CreateSolidBrush(colours->primary);
    tools->primaryVariantBrush = CreateSolidBrush(colours->primaryVariant);
    tools->secondaryBrush = CreateSolidBrush(colours->secondary);
    tools->secondaryVariantBrush = CreateSolidBrush(colours->secondaryVariant);
    tools->onSurfacePen = CreatePen(PS_SOLID, 1, colours->onSurface);
    tools->onSurfaceVariantPen = CreatePen(PS_SOLID, 1, colours->onSurfaceVariant);
    tools->onPrimaryPen = CreatePen(PS_SOLID, 1, colours->primary);
    tools->onPrimaryVariantPen = CreatePen(PS_SOLID, 1, colours->primaryVariant);
}

void blokDrawingToolsFree(DrawingTools *tools)
{
    if (!tools) { return; }

    __BLOK_FREE_WINGDI_OBJECT(tools->surfaceBrush);
    __BLOK_FREE_WINGDI_OBJECT(tools->surfaceVariantBrush);
    __BLOK_FREE_WINGDI_OBJECT(tools->primaryBrush);
    __BLOK_FREE_WINGDI_OBJECT(tools->primaryVariantBrush);
    __BLOK_FREE_WINGDI_OBJECT(tools->secondaryBrush);
    __BLOK_FREE_WINGDI_OBJECT(tools->secondaryVariantBrush);
    __BLOK_FREE_WINGDI_OBJECT(tools->onSurfacePen);
    __BLOK_FREE_WINGDI_OBJECT(tools->onSurfaceVariantPen);
    __BLOK_FREE_WINGDI_OBJECT(tools->onPrimaryPen);
    __BLOK_FREE_WINGDI_OBJECT(tools->onPrimaryVariantPen);
}