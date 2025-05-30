#include "theme.h"

#define BLOK_LIGHT_DARK(light, dark)                                                     \
    (theme == BLOK_THEME_LIGHT) ? light : dark

int blokColoursSet(
    ColourSpace *pColourSpace,
    const Theme theme)
{
    if (pColourSpace == NULL) {
        return 0;
    }

    pColourSpace->surface = BLOK_LIGHT_DARK(BLOK_COLOUR_100S, BLOK_COLOUR_900S);
    pColourSpace->surfaceVariant = BLOK_LIGHT_DARK(BLOK_COLOUR_200S, BLOK_COLOUR_800S);
    pColourSpace->onSurface = BLOK_LIGHT_DARK(BLOK_COLOUR_900S, BLOK_COLOUR_100S);
    pColourSpace->onSurfaceVariant = BLOK_LIGHT_DARK(BLOK_COLOUR_400S, BLOK_COLOUR_500S);
    pColourSpace->primary = BLOK_LIGHT_DARK(BLOK_COLOUR_000A, BLOK_COLOUR_000A);
    pColourSpace->primaryVariant = BLOK_LIGHT_DARK(BLOK_COLOUR_100A, BLOK_COLOUR_100A);
    pColourSpace->secondary = BLOK_LIGHT_DARK(BLOK_COLOUR_500S, BLOK_COLOUR_300S);
    pColourSpace->secondaryVariant = BLOK_LIGHT_DARK(BLOK_COLOUR_400S, BLOK_COLOUR_500S);

    return 1;
}

int zblokColoursSet(
    ThemePalette *pThemePalette,
    const Theme theme)
{
    if (pThemePalette == NULL) {
        return 0;
    }

    pThemePalette->baseBackground = BLOK_LIGHT_DARK(BLOK_COLOUR_BASE_100, BLOK_COLOUR_BASE_900);
    pThemePalette->baseBackgroundFaded = BLOK_LIGHT_DARK(BLOK_COLOUR_BASE_200, BLOK_COLOUR_BASE_800);
    pThemePalette->baseBackgroundMedium = BLOK_LIGHT_DARK(BLOK_COLOUR_BASE_500, BLOK_COLOUR_BASE_400);
    pThemePalette->baseForeground = BLOK_LIGHT_DARK(BLOK_COLOUR_BASE_950, BLOK_COLOUR_BASE_050);
    pThemePalette->baseBorder = BLOK_LIGHT_DARK(BLOK_COLOUR_BASE_500, BLOK_COLOUR_BASE_400);
    pThemePalette->baseBorderFaded = BLOK_LIGHT_DARK(BLOK_COLOUR_BASE_300, BLOK_COLOUR_BASE_700);
    
    pThemePalette->primaryBackground = BLOK_LIGHT_DARK(BLOK_COLOUR_PRIMARY_700, BLOK_COLOUR_PRIMARY_400);
    pThemePalette->primaryBackgroundFaded = BLOK_LIGHT_DARK(BLOK_COLOUR_PRIMARY_100, BLOK_COLOUR_PRIMARY_900);
    pThemePalette->primaryForeground = BLOK_LIGHT_DARK(BLOK_COLOUR_PRIMARY_900, BLOK_COLOUR_PRIMARY_100);
    pThemePalette->primaryBorder = BLOK_LIGHT_DARK(BLOK_COLOUR_PRIMARY_700, BLOK_COLOUR_PRIMARY_400);

    return 0;
}