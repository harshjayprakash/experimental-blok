#include "graphics.h"

int BlokGraphicsInit(TGraphics *pGraphics, const TTheme theme)
{
    if (pGraphics == NULL)
    {
        return 0;
    }

    int disregardTheme = (theme >= BLOK_THEME_MIN && theme <= BLOK_THEME_MAX);
    pGraphics->currentTheme = (!disregardTheme) ? BLOK_THEME_UNSET : theme;

    if (!BlokThemeApply(&pGraphics->palette, pGraphics->currentTheme))
    {
        return 0;
    }

    return BlokRenderToolsInit(&pGraphics->renderTools, &pGraphics->palette);
}

int BlokGraphicsFree(TGraphics *pGraphics)
{
    if (pGraphics == NULL)
    {
        return 0;
    }

    return BlokRenderToolsFree(&pGraphics->renderTools);
}

int BlokGraphicsSwitchTheme(TGraphics *pGraphics)
{
    if (pGraphics == NULL)
    {
        return 0;
    }

    TTheme currentTheme = pGraphics->currentTheme;
    TTheme newTheme = ((currentTheme == BLOK_THEME_DARK || currentTheme == BLOK_THEME_UNSET)
                           ? BLOK_THEME_LIGHT
                           : BLOK_THEME_DARK);

    if (!BlokGraphicsFree(pGraphics))
    {
        return 0;
    }

    if (!BlokGraphicsInit(pGraphics, newTheme))
    {
        return 0;
    }

    return 1;
}