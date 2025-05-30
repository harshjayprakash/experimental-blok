#ifndef _BLOK_THEME_H_
#define _BLOK_THEME_H_

#include <windows.h>

typedef enum _Theme {
    BLOK_THEME_UNSET = 0,
    BLOK_THEME_DARK = 1,
    BLOK_THEME_LIGHT = 2,
} Theme;

#define BLOK_THEME_MIN 0
#define BLOK_THEME_MAX 2

typedef enum _ColourPalette {
    BLOK_COLOUR_BASE_050 = RGB(0xf9, 0xfa, 0xfb),
    BLOK_COLOUR_BASE_100 = RGB(0xf3, 0xf4, 0xf6),
    BLOK_COLOUR_BASE_200 = RGB(0xe5, 0xe7, 0xeb),
    BLOK_COLOUR_BASE_300 = RGB(0xd1, 0xd5, 0xdb),
    BLOK_COLOUR_BASE_400 = RGB(0x9c, 0xa3, 0xaf),
    BLOK_COLOUR_BASE_500 = RGB(0x6b, 0x72, 0x80),
    BLOK_COLOUR_BASE_600 = RGB(0x4b, 0x55, 0x63),
    BLOK_COLOUR_BASE_700 = RGB(0x37, 0x41, 0x51),
    BLOK_COLOUR_BASE_800 = RGB(0x1f, 0x29, 0x37),
    BLOK_COLOUR_BASE_900 = RGB(0x11, 0x18, 0x27),
    BLOK_COLOUR_BASE_950 = RGB(0x03, 0x07, 0x12),
    BLOK_COLOUR_PRIMARY_050 = RGB(0xef, 0xf6, 0xff),
    BLOK_COLOUR_PRIMARY_100 = RGB(0xdb, 0xea, 0xfe),
    BLOK_COLOUR_PRIMARY_200 = RGB(0xbf, 0xdb, 0xfe),
    BLOK_COLOUR_PRIMARY_300 = RGB(0x93, 0xc5, 0xfd),
    BLOK_COLOUR_PRIMARY_400 = RGB(0x60, 0xa5, 0xfa),
    BLOK_COLOUR_PRIMARY_500 = RGB(0x3b, 0x82, 0xf6),
    BLOK_COLOUR_PRIMARY_600 = RGB(0x25, 0x63, 0xeb),
    BLOK_COLOUR_PRIMARY_700 = RGB(0x1d, 0x4e, 0xd8),
    BLOK_COLOUR_PRIMARY_800 = RGB(0x1e, 0x40, 0xaf),
    BLOK_COLOUR_PRIMARY_900 = RGB(0x1e, 0x3a, 0x8a),
    BLOK_COLOUR_PRIMARY_950 = RGB(0x17, 0x25, 0x54),
    BLOK_COLOUR_SECONDARY_050 = RGB(0xf0, 0xfd, 0xfa),
    BLOK_COLOUR_SECONDARY_100 = RGB(0xcc, 0xfb, 0xf1),
    BLOK_COLOUR_SECONDARY_200 = RGB(0x99, 0xf6, 0xe4),
    BLOK_COLOUR_SECONDARY_300 = RGB(0x5e, 0xea, 0xd4),
    BLOK_COLOUR_SECONDARY_400 = RGB(0x2d, 0xd4, 0xbf),
    BLOK_COLOUR_SECONDARY_500 = RGB(0x14, 0xb8, 0xa6),
    BLOK_COLOUR_SECONDARY_600 = RGB(0x0d, 0x94, 0x88),
    BLOK_COLOUR_SECONDARY_700 = RGB(0x0f, 0x76, 0x6e),
    BLOK_COLOUR_SECONDARY_800 = RGB(0x11, 0x5e, 0x59),
    BLOK_COLOUR_SECONDARY_900 = RGB(0x13, 0x4e, 0x4a),
    BLOK_COLOUR_SECONDARY_950 = RGB(0x04, 0x2f, 0x2e)
} ColourPalette;

typedef enum _Colours {
    BLOK_COLOUR_050S = RGB(0xfa, 0xfa, 0xfa),
    BLOK_COLOUR_100S = RGB(0xf4, 0xf4, 0xf5),
    BLOK_COLOUR_200S = RGB(0xe4, 0xe4, 0xe7),
    BLOK_COLOUR_300S = RGB(0xd4, 0xd4, 0xd8),
    BLOK_COLOUR_400S = RGB(0xa1, 0xa1, 0xaa),
    BLOK_COLOUR_500S = RGB(0x71, 0x71, 0x7a),
    BLOK_COLOUR_600S = RGB(0x52, 0x52, 0x5b),
    BLOK_COLOUR_700S = RGB(0x3f, 0x3f, 0x46),
    BLOK_COLOUR_800S = RGB(0x27, 0x27, 0x2a),
    BLOK_COLOUR_900S = RGB(0x18, 0x18, 0x1b),
    BLOK_COLOUR_950S = RGB(0x09, 0x09, 0x0b),
    BLOK_COLOUR_000A = RGB(0xff, 0x00, 0x66),
    BLOK_COLOUR_100A = RGB(0xbe, 0x12, 0x3c),
} Colours;

typedef struct _ColourSpace {
    COLORREF surface;
    COLORREF surfaceVariant;
    COLORREF onSurface;
    COLORREF onSurfaceVariant;
    COLORREF primary;
    COLORREF primaryVariant;
    COLORREF secondary;
    COLORREF secondaryVariant;
} ColourSpace;

int blokColoursSet(ColourSpace *pColourSpace, const Theme theme);

#endif // _BLOK_THEME_H_