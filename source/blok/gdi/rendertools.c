#include "rendertools.h"

#define BLOK_DELETE_OBJECT(hObject)                                                      \
    if (hObject != NULL)                                                                 \
    {                                                                                    \
        (void)DeleteObject(hObject);                                                     \
        hObject = NULL;                                                                  \
    }              

int blokRenderToolsInit(
    TRenderTools *pTools,
    const TThemePalette *pColours)
{
    if (pTools == NULL) {
        return 0;
    }

    if (pColours == NULL) {
        return 0;
    }

    pTools->brushes.hBaseBackground = CreateSolidBrush(pColours->baseBackground);
    pTools->brushes.hBaseBackgroundFaded = CreateSolidBrush(
        pColours->baseBackgroundFaded);
    pTools->brushes.hBaseBackgroundMedium = CreateSolidBrush(
        pColours->baseBackgroundMedium);
    pTools->brushes.hPrimaryBackground = CreateSolidBrush(pColours->primaryBackground);
    pTools->brushes.hPrimaryBackgroundFaded = CreateSolidBrush(
        pColours->primaryBackgroundFaded);
    
    pTools->pens.hBaseForeground = CreatePen(PS_SOLID, 1, pColours->baseForeground);
    pTools->pens.hBaseBorder = CreatePen(PS_SOLID, 1, pColours->baseBorder);
    pTools->pens.hBaseBorderFaded = CreatePen(PS_SOLID, 1, pColours->baseBorderFaded);
    pTools->pens.hPrimaryBorder = CreatePen(PS_SOLID, 1, pColours->primaryBorder);
    pTools->pens.hPrimaryForeground = CreatePen(
        PS_SOLID, 1, pColours->primaryForeground);

    int brushCheck = (
        pTools->brushes.hBaseBackground != NULL 
        && pTools->brushes.hBaseBackgroundFaded != NULL
        && pTools->brushes.hBaseBackgroundMedium != NULL
        && pTools->brushes.hPrimaryBackground != NULL
        && pTools->brushes.hPrimaryBackgroundFaded != NULL
    );

    int penCheck = (
        pTools->pens.hBaseForeground != NULL
        && pTools->pens.hBaseBorder != NULL
        && pTools->pens.hBaseBorderFaded != NULL
        && pTools->pens.hPrimaryBorder != NULL
        && pTools->pens.hPrimaryForeground != NULL
    );


    return (brushCheck && penCheck);
}

int blokRenderToolsFree(
    TRenderTools *pTools)
{
    if (pTools == NULL)
    {
        return 0;
    }

    BLOK_DELETE_OBJECT(pTools->brushes.hBaseBackground);
    BLOK_DELETE_OBJECT(pTools->brushes.hBaseBackgroundFaded);
    BLOK_DELETE_OBJECT(pTools->brushes.hBaseBackgroundMedium);
    BLOK_DELETE_OBJECT(pTools->brushes.hPrimaryBackground);
    BLOK_DELETE_OBJECT(pTools->brushes.hPrimaryBackgroundFaded);
    BLOK_DELETE_OBJECT(pTools->pens.hBaseForeground);
    BLOK_DELETE_OBJECT(pTools->pens.hBaseBorder);
    BLOK_DELETE_OBJECT(pTools->pens.hBaseBorderFaded);
    BLOK_DELETE_OBJECT(pTools->pens.hPrimaryBorder);
    BLOK_DELETE_OBJECT(pTools->pens.hPrimaryForeground);

    return 1;
}