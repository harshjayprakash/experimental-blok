/**
 * @file theme.h
 * @brief Theme and colour palette definitions.
 * @author harshjayprakash
 * @date 2025-07-19
 ****************************************************************************************/

#ifndef _BLOK_THEME_H_
#define _BLOK_THEME_H_

#include <windows.h>

/**
 * @brief Theme.
 * 
 * Denotes the application theme.
 */
typedef enum _Theme
{
    BLOK_THEME_UNSET = 0,
    BLOK_THEME_DARK = 1,
    BLOK_THEME_LIGHT = 2,
} TTheme;

/**
 * @defgroup Theme Min Max.
 * @brief The minimum and maximum values of theme.
 * @{
 */

#define BLOK_THEME_MIN 0
#define BLOK_THEME_MAX 2

/** @} */

/**
 * @brief Defines semantic colours constants.
 * 
 * Provides tone-scaled values from Tailwind's `stone` and `rose` palette used throughout
 * the application to represent the layered neutral and accent colours. Each colour uses
 * the `RGB()` macro from the Windows API and follows a consistant naming pattern.
 * 
 * @remarks
 * - `BASE_*` shades refects the surface colours.
 * - `PRIMARY_*` shades correspond to the accent colours.
 * - All values are compatible with Win32 `COLORREF`.
 * - This enumeration should not be used to style the user interface directly.
 */
typedef enum _ColourPalette
{
    /**
     * @defgroup Base surface colours.
     * @{
     */

    BLOK_COLOUR_BASE_050 = RGB(0xfa, 0xfa, 0xf9),
    BLOK_COLOUR_BASE_100 = RGB(0xf5, 0xf5, 0xf4),
    BLOK_COLOUR_BASE_200 = RGB(0xe7, 0xe5, 0xe4),
    BLOK_COLOUR_BASE_300 = RGB(0xd6, 0xd3, 0xd1),
    BLOK_COLOUR_BASE_400 = RGB(0xa8, 0xa2, 0x9e),
    BLOK_COLOUR_BASE_500 = RGB(0x78, 0x71, 0x6c),
    BLOK_COLOUR_BASE_600 = RGB(0x57, 0x53, 0x4e),
    BLOK_COLOUR_BASE_700 = RGB(0x44, 0x40, 0x3c),
    BLOK_COLOUR_BASE_800 = RGB(0x29, 0x25, 0x24),
    BLOK_COLOUR_BASE_900 = RGB(0x1c, 0x19, 0x17),
    BLOK_COLOUR_BASE_950 = RGB(0x0c, 0x0a, 0x09),

    /** @} */

    /**
     * @defgroup Primary accent colours.
     * @{
     */

    BLOK_COLOUR_PRIMARY_050 = RGB(0xff, 0xf1, 0xf2),
    BLOK_COLOUR_PRIMARY_100 = RGB(0xff, 0xe4, 0xe6),
    BLOK_COLOUR_PRIMARY_200 = RGB(0xfe, 0xcd, 0xd3),
    BLOK_COLOUR_PRIMARY_300 = RGB(0xfd, 0xa4, 0xaf),
    BLOK_COLOUR_PRIMARY_400 = RGB(0xfb, 0x71, 0x85),
    BLOK_COLOUR_PRIMARY_500 = RGB(0xf4, 0x3f, 0x5e),
    BLOK_COLOUR_PRIMARY_600 = RGB(0xe1, 0x1d, 0x48),
    BLOK_COLOUR_PRIMARY_700 = RGB(0xbe, 0x12, 0x3c),
    BLOK_COLOUR_PRIMARY_800 = RGB(0x9f, 0x12, 0x39),
    BLOK_COLOUR_PRIMARY_900 = RGB(0x88, 0x13, 0x37),
    BLOK_COLOUR_PRIMARY_950 = RGB(0x4c, 0x05, 0x19)

    /** @} */

} TColourPalette;

/**
 * @brief Defines the semantic theme palette.
 * 
 * Provides the colour values available based on the selected theme. This is set via
 * the `blokThemeSet` function.
 * 
 * @remarks
 * - Avoid direct modification.
 */
typedef struct _ThemePalette
{
    COLORREF baseBackground;
    COLORREF baseBackgroundFaded;
    COLORREF baseBackgroundMedium;
    COLORREF baseForeground;
    COLORREF baseBorder;
    COLORREF baseBorderFaded;
    COLORREF primaryBackground;
    COLORREF primaryBackgroundFaded;
    COLORREF primaryForeground;
    COLORREF primaryBorder;
} TThemePalette;

/**
 * @brief Sets the theme.
 * 
 * Assigns the colours within the theme palette based on the provided theme.
 * 
 * @param[out] pThemePalette A valid pointer to the `TThemePalette`.
 * @param[in]  theme         The theme to be set. 
 * @return One if assignment was succesful. zero otherwise.
 */
int blokThemeSet(TThemePalette *pThemePalette, const TTheme theme);

#endif /* _BLOK_THEME_H_ */