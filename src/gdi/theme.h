#ifndef _BLOK_THEME_H_
#define _BLOK_THEME_H_

#include <Windows.h>

typedef enum _Theme {
    BLOK_THEME_UNSET = 0,
    BLOK_THEME_DARK = 1,
    BLOK_THEME_LIGHT = 2,
} Theme;

#define BLOK_THEME_MIN 0
#define BLOK_THEME_MAX 2

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

void BlokColoursSet(ColourSpace *colours, const Theme theme);

#endif // _BLOK_THEME_H_