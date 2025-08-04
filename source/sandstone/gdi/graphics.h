/**
 * @file   graphics.h
 * @brief  Graphics Declarations.
 * @author harshjayprakash
 * @date   2025-08-03
 ****************************************************************************************/

#ifndef ST_GRAPHICS_H
#define ST_GRAPHICS_H

#include "rendertools.h"
#include "theme.h"

/**
 * @brief Graphics context.
 *
 * @details
 * This structure contains the theming and tools used to paint the user interface. This is
 * managed via the `stGraphicsInit` and `stGraphicsFree` lifecycle functions.
 *
 * @remarks
 * - The caller must not modify these values directly.
 */
typedef struct _Graphics
{
    TTheme currentTheme;      /**< Current application theme */
    TRenderTools renderTools; /**< Render tools. */
    TThemePalette palette;    /**< Theme colours. */
} TGraphics;

/**
 * @brief Initialise the graphics context.
 * 
 * @details
 * This function validates the given theme, and then proceeds to apply the theme palette,
 * and initialise the render tools.
 * 
 * @param[out] pGraphics   Pointer to the graphics context.
 * @param[in]  theme       Theme to be set.
 * @return `1` for success, `0` on failure.
 * 
 * @remarks
 * - An invalid theme will default to the dark theme as a fallback.
 * - Memory is allocated, the corresponding free function stGraphics Free must be called
 *   on clean up.
 */
int stGraphicsInit(TGraphics *pGraphics, const TTheme theme);

/**
 * @brief Free the graphics context.
 *
 * @details
 * This function provides a wrapper for cleaning up the render tools.
 *
 * @param[out] pGraphics   Pointer to the graphics context.
 * @return `1` for success, `0` on failure.
 */
int stGraphicsFree(TGraphics *pGraphics);

/**
 * @brief Reload the graphics context.
 * 
 * @details
 * This function switches the theme and reloads the graphics, internally calling the
 * free and initialise lifecycle functions.
 * 
 * @param[out] pGraphics   Pointer to the graphics context.
 * @return `1` for success, `0` on failure.
 */
int stGraphicsSwitchTheme(TGraphics *pGraphics);

#endif /* ST_GRAPHICS_H */