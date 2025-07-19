/**
 * @file graphics.c
 * @brief Graphics lifecycle implementation.
 * @author harshjayprakash
 * @date 2025-07-19
 ****************************************************************************************/

#include "graphics.h"

int stGraphicsInit(
    TGraphics *pGraphics,
    const TTheme theme)
{
    if (pGraphics == NULL)
    {
        return 0;
    }

    int disregardTheme = (theme >= ST_THEME_MIN && theme <= ST_THEME_MAX);
    pGraphics->currentTheme = (!disregardTheme) ? ST_THEME_UNSET : theme;

    int success = stThemeSet(&pGraphics->palette, pGraphics->currentTheme);
    if (!success)
    {
        return 0;
    }

    return stRenderToolsInit(&pGraphics->renderTools, &pGraphics->palette);
}

int stGraphicsFree(
    TGraphics *pGraphics)
{
    if (pGraphics == NULL)
    {
        return 0;
    }

    return stRenderToolsFree(&pGraphics->renderTools);
}