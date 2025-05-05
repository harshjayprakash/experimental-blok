#include "graphics.h"

#define __BLOK_IS_VALID_THEME(theme) \
    (theme >= BLOK_THEME_MIN && theme <= BLOK_THEME_MAX)

#define __BLOK_DISREGARD_THEME(disregard) \
    (disregard) ? BLOK_THEME_UNSET : theme

void blokGraphicsInit(Graphics *pGraphics, const Theme theme)
{
    if (!pGraphics) { return; }

    int disregard = !BLOK_IS_VALID_THEME(theme);
    pGraphics->theme = BLOK_DISREGARD_THEME(disregard);

    blokColoursSet(&pGraphics->colours, pGraphics->theme);
    blokDrawingToolsInit(&pGraphics->tools, &pGraphics->colours);
}

void blokGraphicsFree(Graphics *pGraphics)
{
    if (!pGraphics) { return; }

    blokDrawingToolsFree(&pGraphics->tools);
}