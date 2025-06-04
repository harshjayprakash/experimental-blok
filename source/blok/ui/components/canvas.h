/**
 * @file CANVAS.H
 * @date 01-06-2025
 * @brief Provides the canvas structure and update routine.
 */

#ifndef _BLOK_CANVAS_H_
#define _BLOK_CANVAS_H_

#include <windows.h>

/**
 * @brief Canvas Component
 *
 * @details
 * Represents the canvas component.
 */
typedef struct _Canvas {
    RECT region;   /**< The canvas region. */
    SIZE size;     /**< The canvas size. */
} Canvas;

/**
 * @brief Update the canvas.
 *
 * @details
 * Reassigns the canvas area based on the provided window region.
 * 
 * @param[in out] pCanvas      The canvas to be updated.
 * @param[in]     pWindowRgn   The updated window region.
 * @return                     0 for failure, 1 for success.
 */
int blokCanvasUpdate(Canvas *pCanvas, const RECT *pWindowRgn);

#endif // _BLOK_CANVAS_H_