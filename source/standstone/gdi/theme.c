/**
 * @file theme.c
 * @brief Theme setting implementation.
 * @author harshjayprakash
 * @date 2025-07-19
 ****************************************************************************************/

#include "theme.h"

#define ST_LIGHT_DARK(light, dark)                                                     \
    (theme == ST_THEME_LIGHT) ? light : dark

int stThemeApply(
    TThemePalette *pThemePalette,
    const TTheme theme)
{
    if (pThemePalette == NULL)
    {
        return 0;
    }

    pThemePalette->baseBackground = ST_LIGHT_DARK(
        ST_COLOUR_BASE_100,
        ST_COLOUR_BASE_900);
    pThemePalette->baseBackgroundFaded = ST_LIGHT_DARK(
        ST_COLOUR_BASE_200,
        ST_COLOUR_BASE_800);
    pThemePalette->baseBackgroundMedium = ST_LIGHT_DARK(
        ST_COLOUR_BASE_500,
        ST_COLOUR_BASE_400);
    pThemePalette->baseForeground = ST_LIGHT_DARK(
        ST_COLOUR_BASE_950,
        ST_COLOUR_BASE_050);
    pThemePalette->baseBorder = ST_LIGHT_DARK(
        ST_COLOUR_BASE_500,
        ST_COLOUR_BASE_400);
    pThemePalette->baseBorderFaded = ST_LIGHT_DARK(
        ST_COLOUR_BASE_300,
        ST_COLOUR_BASE_700);
    
    pThemePalette->primaryBackground = ST_LIGHT_DARK(
        ST_COLOUR_PRIMARY_700,
        ST_COLOUR_PRIMARY_400);
    pThemePalette->primaryBackgroundFaded = ST_LIGHT_DARK(
        ST_COLOUR_PRIMARY_100,
        ST_COLOUR_PRIMARY_900);
    pThemePalette->primaryForeground = ST_LIGHT_DARK(
        ST_COLOUR_PRIMARY_900,
        ST_COLOUR_PRIMARY_100);
    pThemePalette->primaryBorder = ST_LIGHT_DARK(
        ST_COLOUR_PRIMARY_700,
        ST_COLOUR_PRIMARY_400);

    return 1;
}