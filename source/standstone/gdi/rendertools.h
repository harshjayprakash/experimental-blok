/**
 * @file rendertools.h
 * @brief Render Tools Declarations.
 * @author harshjayprakash
 * @date 2025-07-20
 ****************************************************************************************/

#ifndef ST_RENDERTOOLS_H
#define ST_RENDERTOOLS_H

#include "theme.h"
#include <windows.h>

/**
 * @brief Rendering tools.
 * 
 * @details
 *  Contains all the rendering tools required for painting the user interface. The default
 *  configuration for HBRUSH is creating a solid brush based on the theme palette. HPEN
 *  follows the same principle with the PS_SOLID and 1 as the thickness.
 */
typedef struct _RenderTools
{
    /**
     * @brief Brushes.
     * 
     * @details
     *  Provides the brushes, named semantically based on use.
     */
    struct _Brushes
    {
        HBRUSH hBaseBackground;
        HBRUSH hBaseBackgroundFaded;
        HBRUSH hBaseBackgroundMedium;
        HBRUSH hPrimaryBackground;
        HBRUSH hPrimaryBackgroundFaded;
    } brushes;

    /**
     * @brief Pens.
     * 
     * @details
     *  Provides the pens, named semantically based on use.
     */
    struct _Pens
    {
        HPEN hBaseForeground;
        HPEN hBaseBorder;
        HPEN hBaseBorderFaded;
        HPEN hPrimaryBorder;
        HPEN hPrimaryForeground;
    } pens;
} TRenderTools;

/**
 * @brief Initialise the render tools.
 * 
 * @details
 *  Attempts to create all the brushes and pens.
 * 
 * @param[out] pTools   A valid pointer to TRenderTools.
 * @param[in]  pColours A valid pointer to TThemePalette.
 * @return One for success, zero for failure.
 * 
 * @remark
 *  The function assumes that theme palette has been set before this. A zeroed theme
 *  palette will likely result in a blank window.
 * @remark
 *  Memory is allocated, the corresponding stRenderToolsFree function must be called
 *  on clean-up.
 * @remark
 *  All allocated brushes and pens are checked against null to calculate the return
 *  value. If a single brush or pen creation fails, the function will return 1. In
 *  this case, the caller must clean-up, before re-attempting.
 */
int stRenderToolsInit(TRenderTools *pTools, const TThemePalette *pColours);

/**
 * @brief Free the render tools.
 * 
 * @details
 *  Frees all the allocated brushes and pens.
 * 
 * @param[out] pTools A valid pointer to TRenderTools.
 * @return One for success, zero for failure.
 * 
 * @remark
 *  This function checks if the Gdi objects are valid before attempting to free them.
 */
int stRenderToolsFree(TRenderTools *pTools);

#endif /* ST_RENDERTOOLS_H */