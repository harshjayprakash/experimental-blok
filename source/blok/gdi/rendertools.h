/**
 * @file rendertools.h
 * @brief Render tools structure and lifecycle declaration.
 * @author harshjayprakash
 * @date 2025-07-19
 ****************************************************************************************/

#ifndef _BLOK_RENDERTOOLS_H_
#define _BLOK_RENDERTOOLS_H_

#include "theme.h"
#include <windows.h>

/**
 * @brief Rendering tools.
 * 
 * This structure contains all the rendering tools (pens and brushes) required for
 * painting the user interface.
 */
typedef struct _RenderTools
{
    /**
     * @brief Brushes.
     * 
     * This structure provides the brushes, named semantically based on use.
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
     * This structure provides the pens, named semantically based on use.
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
 * Attempts to create all the brushes and pens.
 * 
 * @param[out] pTools   A valid pointer to `TRenderTools`.
 * @param[in]  pColours A valid pointer to `TThemePalette`.
 * @return One if initialisation was successful; zero otherwise.
 * 
 * @remarks
 * - Assumes that the theme palette has been set before this function call.
 * - Memory is allocated, the corresponding `blokRenderToolsFree` function must be
 *   called on clean up.
 */
int blokRenderToolsInit(TRenderTools *pTools, const TThemePalette *pColours);

/**
 * @brief Free the render tools.
 * 
 * Frees all the allocated brushes and pens.
 * 
 * @param[out] pTools A valid pointer to `TRenderTools`.
 * @return One if clean up is successful; zero otherwise.
 */
int blokRenderToolsFree(TRenderTools *pTools);

#endif /* _BLOK_RENDERTOOLS_H_ */