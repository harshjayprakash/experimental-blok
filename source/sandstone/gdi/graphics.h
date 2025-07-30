/**
 * @file graphics.h
 * @brief Graphics Declarations.
 * @author harshjayprakash
 * @date 2025-07-20
 ****************************************************************************************/

#ifndef ST_GRAPHICS_H
#define ST_GRAPHICS_H

#include "theme.h"
#include "rendertools.h"

/**
 * @brief Graphics context.
 * 
 * @details
 *  Contains the theming and tools used to paint the user interface. This is managed via
 *  the stGraphicsInit and stGraphicsFree functions.
 */
typedef struct _Graphics
{
    /**
     * @brief The current application theme.
     * 
     * @details
     *  Set by the parsed arguments on start-up.
     */
    TTheme currentTheme;

    /**
     * @brief The rendering tools.
     * 
     * @details
     *  Provides the pens and brushes used to paint on the window. This type contains
     *  its own lifetime functions.
     */
    TRenderTools renderTools;

    /**
     * @brief The theme palette.
     * 
     * @details
     *  Provides the available colours based on the application theme.
     */
    TThemePalette palette;
} TGraphics;

/**
 * @brief Initialise the graphics.
 * 
 * @details
 *  Validates the given theme, and then proceeds to set the theme palette and initialise
 *  the render tools.
 * 
 * @param[out] pGraphics A valid pointer to TGraphics.
 * @param[in]  theme     The theme to be set.
 * @return One on success, zero on failure.
 * 
 * @remark
 *  An invalid theme will default to the dark theme as a fallback.
 * @remark
 *  Memory is allocated, the corresponding free function stGraphics Free must be called
 *  on clean up.
 */
int stGraphicsInit(TGraphics *pGraphics, const TTheme theme);

/**
 * @brief Free the graphics.
 * 
 * @details
 *  Provides a wrapper for cleaning up the render tools.
 * 
 * @param[out] pGraphics A valid pointer to TGraphics.
 * @return One on success, zero on failure.
 */
int stGraphicsFree(TGraphics *pGraphics);


int stGraphicsSwitchTheme(TGraphics *pGraphics);

#endif /* ST_GRAPHICS_H */