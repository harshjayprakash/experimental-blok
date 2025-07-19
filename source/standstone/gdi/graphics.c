/**
 * @file graphics.c
 * @brief Graphics lifecycle implementation.
 * @author harshjayprakash
 * @date 2025-07-19
 ****************************************************************************************/

#include "graphics.h"

int blokGraphicsInit(
    TGraphics *pGraphics,
    const TTheme theme)
{
    if (pGraphics == NULL)
    {
        return 0;
    }

    int disregardTheme = (theme >= BLOK_THEME_MIN && theme <= BLOK_THEME_MAX);
    pGraphics->currentTheme = (!disregardTheme) ? BLOK_THEME_UNSET : theme;

    int success = blokThemeSet(&pGraphics->palette, pGraphics->currentTheme);
    if (!success)
    {
        return 0;
    }

    return blokRenderToolsInit(&pGraphics->renderTools, &pGraphics->palette);
}

int blokGraphicsFree(
    TGraphics *pGraphics)
{
    if (pGraphics == NULL)
    {
        return 0;
    }

    return blokRenderToolsFree(&pGraphics->renderTools);
}