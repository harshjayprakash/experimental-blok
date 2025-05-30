#include "graphics.h"

int blokGraphicsInit(
    Graphics *pGraphics,
    const Theme theme)
{
    if (pGraphics == NULL) {
        return 0;
    }

    int disregardTheme = (theme >= BLOK_THEME_MIN && theme <= BLOK_THEME_MAX);
    pGraphics->theme = (!disregardTheme) ? BLOK_THEME_UNSET : theme;

    (void)zblokColoursSet(&pGraphics->zcolours, pGraphics->theme);
    (void)zblokRenderToolsInit(&pGraphics->ztools, &pGraphics->zcolours);

    return 1;
}

int blokGraphicsFree(
    Graphics *pGraphics)
{
    if (pGraphics == NULL) {
        return 0;
    }

    return zblokRenderToolsFree(&pGraphics->ztools);
}