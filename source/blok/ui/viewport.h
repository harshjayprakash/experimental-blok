/**
 * @file VIEWPORT.H
 * @date 27-05-2025
 * @brief Provides the Viewport structure and lifecycle functions.
 */

#ifndef _BLOK_VIEWPORT_H_
#define _BLOK_VIEWPORT_H_

#include "controls/button.h"
#include "controls/text.h"
#include "controls/progressbar.h"
#include "controls/toggle.h"
#include "components/canvas.h"
#include "components/panel.h"
#include "frame/window.h"
#include <Windows.h>

/**
 * @brief The Viewport.
 * 
 * @details
 * Provides all the user interface data.
 */
typedef struct _Viewport {
    Window window;                   /**< The window information. */
    RECT region;                     /**< The window client region area. */
    POINT mousePos;                  /**< The mouse position relative to the window. */
    HFONT hFont;                     /**< The interface font. */
    BOOL isLeftMouseDown;            /**< If the left mouse is down. */
    BOOL isRightMouseDown;           /**< If the right mouse is down. */

    Canvas canvas;                   /**< The canvas bounds information. */
    int isCanvasLocked;              /**< If the canvas has been locked. */
    int isGridVisible;               /**< If the grid lines are visible. */

    Panel panel;                     /**< The panel bounds information. */
    int isInterfaceVisible;          /**< If the panel is visible. */
    Text coordinatesText;            /**< The box coordinates label. */
    Button clearAllButton;           /**< The clear all obstructs button. */
    Button generateButton;           /**< The generate obstruct button. */
    Text obstructCountText;          /**< The obstruct count label. */
    ProgressBar obstructMemoryBar;   /**< The obstruct dynamic list memory bar. */
    Text lockedToggleText;           /**< The locked toggle text. */
    Toggle lockedToggle;             /**< The canvas lock toggle. */
} Viewport;

/**
 * @brief Initialise the Viewport.
 * 
 * @details
 * Randomises the seed to time. Initialises the window, setting the default state values.
 * Attempts to the create the font. Then proceeds to initialise all the components and
 * controls.
 * 
 * @param[in out] pViewport   The pointer to the viewport.
 * @param[in]     hInstance   The instance handle.
 * @return                    0 for failure, 1 for success. 
 */
int blokViewportInit(Viewport *pViewport, HINSTANCE hInstance);

/**
 * @brief Show the Viewport.
 * 
 * @details
 * A wrapper for showing the window.
 * 
 * @param[in out] pViewport   The pointer to the viewport.
 * @param[in]     showFlag    The window show flag.
 * @return                    (__CONFLICT__)
 */
int blokViewportShow(Viewport *pViewport, DWORD showFlag);

/**
 * @brief Free the Viewport.
 * 
 * @details
 * Cleans up the allocated font and the window.
 * 
 * @param[in out] pViewport   The pointer to the viewport.
 * @param[in]     hInstance   The instance handle.
 * @return                    0 for failure, 1 for success.
 */
int blokViewportFree(Viewport *pViewport, HINSTANCE hInstance);

#endif // _BLOK_VIEWPORT_H_