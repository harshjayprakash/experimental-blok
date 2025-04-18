#include "theme.h"

#define __BLOK_LIGHT_DARK(light, dark) \
    (theme == BLOK_THEME_LIGHT) ? light : dark

void BlokColoursSet(ColourSpace *colours, const Theme theme)
{
    if (!colours) { return; }

    colours->surface = __BLOK_LIGHT_DARK(BLOK_COLOUR_100S, BLOK_COLOUR_900S);
    colours->surfaceVariant = __BLOK_LIGHT_DARK(BLOK_COLOUR_200S, BLOK_COLOUR_800S);
    colours->onSurface = __BLOK_LIGHT_DARK(BLOK_COLOUR_900S, BLOK_COLOUR_100S);
    colours->onSurfaceVariant = __BLOK_LIGHT_DARK(BLOK_COLOUR_400S, BLOK_COLOUR_500S);
    colours->primary = __BLOK_LIGHT_DARK(BLOK_COLOUR_000A, BLOK_COLOUR_000A);
    colours->primaryVariant = __BLOK_LIGHT_DARK(BLOK_COLOUR_100A, BLOK_COLOUR_100A);
    colours->secondary = __BLOK_LIGHT_DARK(BLOK_COLOUR_500S, BLOK_COLOUR_300S);
    colours->secondaryVariant = __BLOK_LIGHT_DARK(BLOK_COLOUR_400S, BLOK_COLOUR_500S);
}