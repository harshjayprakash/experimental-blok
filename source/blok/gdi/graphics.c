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

    (void)blokColoursSet(&pGraphics->colours, pGraphics->theme);
    (void)blokRenderToolsInit(&pGraphics->tools, &pGraphics->colours);

    return 1;
}

int blokGraphicsFree(
    Graphics *pGraphics)
{
    if (pGraphics == NULL) {
        return 0;
    }

    return blokRenderToolsFree(&pGraphics->tools);
}