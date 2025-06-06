#include "graphics.h"

int blokGraphicsInit(
    TGraphics *pGraphics,
    const TTheme theme)
{
    if (pGraphics == NULL) {
        return 0;
    }

    int disregardTheme = (theme >= BLOK_THEME_MIN && theme <= BLOK_THEME_MAX);
    pGraphics->currentTheme = (!disregardTheme) ? BLOK_THEME_UNSET : theme;

    (void)blokColoursSet(&pGraphics->palette, pGraphics->currentTheme);
    (void)blokRenderToolsInit(&pGraphics->renderTools, &pGraphics->palette);

    return 1;
}

int blokGraphicsFree(
    TGraphics *pGraphics)
{
    if (pGraphics == NULL) {
        return 0;
    }

    return blokRenderToolsFree(&pGraphics->renderTools);
}