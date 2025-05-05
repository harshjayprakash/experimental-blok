#include "theme.h"

#define BLOK_LIGHT_DARK(light, dark)                                                     \
    (theme == BLOK_THEME_LIGHT) ? light : dark

void blokColoursSet(ColourSpace *pColourSpace, const Theme theme)
{
    if (!pColourSpace) { return; }

    pColourSpace->surface = BLOK_LIGHT_DARK(BLOK_COLOUR_100S, BLOK_COLOUR_900S);
    pColourSpace->surfaceVariant = BLOK_LIGHT_DARK(BLOK_COLOUR_200S, BLOK_COLOUR_800S);
    pColourSpace->onSurface = BLOK_LIGHT_DARK(BLOK_COLOUR_900S, BLOK_COLOUR_100S);
    pColourSpace->onSurfaceVariant = BLOK_LIGHT_DARK(BLOK_COLOUR_400S, BLOK_COLOUR_500S);
    pColourSpace->primary = BLOK_LIGHT_DARK(BLOK_COLOUR_000A, BLOK_COLOUR_000A);
    pColourSpace->primaryVariant = BLOK_LIGHT_DARK(BLOK_COLOUR_100A, BLOK_COLOUR_100A);
    pColourSpace->secondary = BLOK_LIGHT_DARK(BLOK_COLOUR_500S, BLOK_COLOUR_300S);
    pColourSpace->secondaryVariant = BLOK_LIGHT_DARK(BLOK_COLOUR_400S, BLOK_COLOUR_500S);
}