/**
 * @file rendertools.c
 * @brief Render tools lifecycle implementation.
 * @author harshjayprakash
 * @date 2025-07-19
 ****************************************************************************************/

#include "rendertools.h"

#define ST_DELETE_OBJECT(hObject)                                                        \
    if (hObject != NULL)                                                                 \
    {                                                                                    \
        (void)DeleteObject(hObject);                                                     \
        hObject = NULL;                                                                  \
    }              

int stRenderToolsInit(
    TRenderTools *pTools,
    const TThemePalette *pColours)
{
    if (pTools == NULL || pColours == NULL)
    {
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

int stRenderToolsFree(
    TRenderTools *pTools)
{
    if (pTools == NULL)
    {
        return 0;
    }

    ST_DELETE_OBJECT(pTools->brushes.hBaseBackground);
    ST_DELETE_OBJECT(pTools->brushes.hBaseBackgroundFaded);
    ST_DELETE_OBJECT(pTools->brushes.hBaseBackgroundMedium);
    ST_DELETE_OBJECT(pTools->brushes.hPrimaryBackground);
    ST_DELETE_OBJECT(pTools->brushes.hPrimaryBackgroundFaded);
    ST_DELETE_OBJECT(pTools->pens.hBaseForeground);
    ST_DELETE_OBJECT(pTools->pens.hBaseBorder);
    ST_DELETE_OBJECT(pTools->pens.hBaseBorderFaded);
    ST_DELETE_OBJECT(pTools->pens.hPrimaryBorder);
    ST_DELETE_OBJECT(pTools->pens.hPrimaryForeground);

    return 1;
}