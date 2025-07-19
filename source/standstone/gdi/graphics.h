/**
 * @file graphics.h
 * @brief Graphics context and lifecycle declarations.
 * @author harshjayprakash
 * @date 2025-07-19
 ****************************************************************************************/

#ifndef ST_GRAPHICS_H
#define ST_GRAPHICS_H

#include "theme.h"
#include "rendertools.h"

/**
 * @brief Graphics context.
 * 
 * This structure contains the colour theme and the tools used to paint the user
 * interface.
 */
typedef struct _Graphics
{
    /**
     * @brief The current application theme.
     * 
     * This is set by the result within the `TArgsResult` on startup.
     */
    TTheme currentTheme;

    /**
     * @brief The rendering tools.
     * 
     * Provides the pens and brushes used to paint on the window.
     */
    TRenderTools renderTools;

    /**
     * @brief The theme palette.
     * 
     * Provides the available colours based on the application theme.
     */
    TThemePalette palette;
} TGraphics;

/**
 * @brief Initialise the graphics.
 * 
 * This function validates the given theme and initialise the theme palette and render
 * tools.
 * 
 * @param[out] pGraphics A valid pointer to the `TGraphics` structure.
 * @param[in]  theme     The theme to be set.
 * @return One if initialisation was successful; zero otherwise.
 * 
 * @remarks
 * - The caller is responsible for allocating a valid `TGraphics` structure.
 * - An invalid theme will default in the dark theme.
 * - Memory is allocated, the corresponding free function must be called on clean up.
 */
int stGraphicsInit(TGraphics *pGraphics, const TTheme theme);

/**
 * @brief Free the graphics.
 * 
 * This function provides a wrapper for freeing the allocated render tools.
 * 
 * @param[out] pGraphics A valid pointer to the `TGraphics` structure.
 * @return One if clean up was successful; zero otherwise.
 */
int stGraphicsFree(TGraphics *pGraphics);

#endif /* ST_GRAPHICS_H */