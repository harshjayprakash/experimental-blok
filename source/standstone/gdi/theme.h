/**
 * @file theme.h
 * @brief Theme and colour palette definitions.
 * @author harshjayprakash
 * @date 2025-07-19
 ****************************************************************************************/

#ifndef ST_THEME_H
#define ST_THEME_H

#include <windows.h>

/**
 * @brief Theme.
 * 
 * Denotes the application theme.
 */
typedef enum _Theme
{
    ST_THEME_UNSET = 0,
    ST_THEME_DARK = 1,
    ST_THEME_LIGHT = 2,
} TTheme;

/**
 * @defgroup Theme Min Max.
 * @brief The minimum and maximum values of theme.
 * @{
 */

#define ST_THEME_MIN 0
#define ST_THEME_MAX 2

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

    ST_COLOUR_BASE_050 = RGB(0xf9, 0xfa, 0xfb),
    ST_COLOUR_BASE_100 = RGB(0xf3, 0xf4, 0xf6),
    ST_COLOUR_BASE_200 = RGB(0xe5, 0xe7, 0xeb),
    ST_COLOUR_BASE_300 = RGB(0xd1, 0xd5, 0xdb),
    ST_COLOUR_BASE_400 = RGB(0x9c, 0xa3, 0xaf),
    ST_COLOUR_BASE_500 = RGB(0x6b, 0x72, 0x80),
    ST_COLOUR_BASE_600 = RGB(0x4b, 0x55, 0x63),
    ST_COLOUR_BASE_700 = RGB(0x37, 0x41, 0x51),
    ST_COLOUR_BASE_800 = RGB(0x1f, 0x29, 0x37),
    ST_COLOUR_BASE_900 = RGB(0x11, 0x18, 0x27),
    ST_COLOUR_BASE_950 = RGB(0x03, 0x07, 0x12),

    /** @} */

    /**
     * @defgroup Primary accent colours.
     * @{
     */

    ST_COLOUR_PRIMARY_050 = RGB(0xef, 0xf6, 0xff),
    ST_COLOUR_PRIMARY_100 = RGB(0xdb, 0xea, 0xfe),
    ST_COLOUR_PRIMARY_200 = RGB(0xbf, 0xdb, 0xfe),
    ST_COLOUR_PRIMARY_300 = RGB(0x93, 0xc5, 0xfd),
    ST_COLOUR_PRIMARY_400 = RGB(0x60, 0xa5, 0xfa),
    ST_COLOUR_PRIMARY_500 = RGB(0x3b, 0x82, 0xf6),
    ST_COLOUR_PRIMARY_600 = RGB(0x25, 0x63, 0xeb),
    ST_COLOUR_PRIMARY_700 = RGB(0x1d, 0x4e, 0xd8),
    ST_COLOUR_PRIMARY_800 = RGB(0x1e, 0x40, 0xaf),
    ST_COLOUR_PRIMARY_900 = RGB(0x1e, 0x3a, 0x8a),
    ST_COLOUR_PRIMARY_950 = RGB(0x17, 0x25, 0x54)

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
int stThemeSet(TThemePalette *pThemePalette, const TTheme theme);

#endif /* ST_THEME_H */