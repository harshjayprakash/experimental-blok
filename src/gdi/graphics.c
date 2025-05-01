#include "graphics.h"

#define __BLOK_IS_VALID_THEME(theme) \
    (theme >= BLOK_THEME_MIN && theme <= BLOK_THEME_MAX)

#define __BLOK_DISREGARD_THEME(disregard) \
    (disregard) ? BLOK_THEME_UNSET : theme

void blokGraphicsInit(Graphics *gfx, const Theme theme)
{
    if (!gfx) { return; }

    int disregard = !__BLOK_IS_VALID_THEME(theme);
    gfx->theme = __BLOK_DISREGARD_THEME(disregard);

    blokColoursSet(&gfx->colours, gfx->theme);
    blokDrawingToolsInit(&gfx->tools, &gfx->colours);
}

void blokGraphicsFree(Graphics *gfx)
{
    if (!gfx) { return; }

    blokDrawingToolsFree(&gfx->tools);
}