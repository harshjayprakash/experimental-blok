/**
 * @file   canvas.h
 * @brief  Canvas Declarations.
 * @author harshjayprakash
 * @date   2025-08-03
 ****************************************************************************************/

#ifndef ST_CANVAS_H
#define ST_CANVAS_H

#include <windows.h>

/**
 * @brief Represents the Base Canvas Component.
 *
 * @details
 * Stores the region area and size. Use the stCanvasUpdate function to manage these
 * attributes.
 */
typedef struct _Canvas
{
    RECT region; /**< Canvas region. */
    SIZE size; /**< Canvas size. */
} TCanvas;

/**
 * @brief Update or initialises the canvas values.
 *
 * @details
 * Sizes the canvas to match the window's client area.
 *
 * @param[in, out] pCanvas      Pointer to the canvas to be updated.
 * @param[in]      pWindowRgn   Pointer to the window client region.
 * @return `1` for success, `0` for failure.
 *
 * @remark
 * This function must be called once for the initialisation.
 */
int stCanvasUpdate(TCanvas *pCanvas, const RECT *pWindowRgn);

#endif /* ST_CANVAS_H */