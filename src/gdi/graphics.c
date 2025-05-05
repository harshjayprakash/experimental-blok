#include "graphics.h"

int blokGraphicsInit(Graphics *pGraphics, const Theme theme)
{
    if (!pGraphics) { return; }

    int disregardTheme = (theme >= BLOK_THEME_MIN && theme <= BLOK_THEME_MAX);
    pGraphics->theme = (disregardTheme) ? BLOK_THEME_UNSET : theme;

    blokColoursSet(&pGraphics->colours, pGraphics->theme);
    blokDrawingToolsInit(&pGraphics->tools, &pGraphics->colours);
}

void blokGraphicsFree(Graphics *pGraphics)
{
    if (!pGraphics) { return; }

    blokDrawingToolsFree(&pGraphics->tools);
}