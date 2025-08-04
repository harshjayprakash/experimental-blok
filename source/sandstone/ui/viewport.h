/**
 * @file   viewport.h
 * @brief  Viewport Declarations.
 * @author harshjayprakash
 * @date   2025-08-03
 ****************************************************************************************/

#ifndef ST_VIEWPORT_H
#define ST_VIEWPORT_H

#include "components/canvas.h"
#include "components/panel.h"
#include "controls/button.h"
#include "controls/progressbar.h"
#include "controls/text.h"
#include "controls/toggle.h"
#include "frame/window.h"
#include <windows.h>

/**
 * @brief The Viewport Module.
 *
 * @details
 * Contains the components required for the user interface. This is managed via the
 * stViewport* functions.
 */
typedef struct _Viewport
{
    TWindow window;                 /**< Native window data. */
    RECT region;                    /**< Window client area. */
    POINT mousePos;                 /**< Mouse position relative to the window. */
    HFONT hFont;                    /**< Font used for rendering. */
    BOOL isLeftMouseDown;           /**< Is left mouse button down. */
    BOOL isRightMouseDown;          /**< Is right mouse button down. */
    TCanvas canvas;                 /**< Canvas component. */
    BOOL isCanvasLocked;            /**< Is canvas locked. */
    BOOL isGridVisible;             /**< Is grid lines visible. */
    TPanel panel;                   /**< Action and information panel component. */
    BOOL isInterfaceVisible;        /**< Is interface visible. */
    TText coordinatesText;          /**< Box coordinates label. */
    TButton clearAllButton;         /**< Clear all button. */
    TButton generateButton;         /**< Generate one obstruct button. */
    TText obstructCountText;        /**< Obstruct count label. */
    TProgressBar obstructMemoryBar; /**< Obstruct relative memory process bar. */
    TText lockedToggleText;         /**< Locked canvas toggle label. */
    TToggle lockedToggle;           /**< Canvas locked toggle control. */
} TViewport;

/**
 * @brief Initialise the viewport.
 *
 * @details
 *  A series of operations are performed to prepare the graphical user interface.
 *  - Randomise the seed.
 *  - Attempts to initialise the native window.
 *  - Sets the default flags.
 *  - Create the font.
 *  - Initialise all the components.
 *
 * @param[in, out] pViewport   Pointer to the viewport module.
 * @param[in]      hInstance   Handle to the application instance.
 * @return `1` for success, `0` for failure.
 *
 * @remarks
 * - If the font creation fails, the application will continue using the base system font.
 * - If the native window creation fails, the application will exit. The corresponding the
 *   stViewportFree must be called.
 */
int stViewportInit(TViewport *pViewport, HINSTANCE hInstance);

/**
 * @brief Show the viewport.
 *
 * @details
 * A wrapper for the stWindowShow function.
 *
 * @param[in, out] pViewport   Pointer to the viewport module.
 * @param[in]      showFlag    Initial window display state.
 * @return `-1` for failure, or the exit code.
 */
int stViewportShow(TViewport *pViewport, DWORD showFlag);

/**
 * @brief Free the viewport.
 *
 * @details
 * Frees the allocated resources for the window and font.
 *
 * @param[in, out] pViewport   Pointer to the viewport module.
 * @param[in]      hInstance   Handle to the application instance.
 * @return `1` for success, `0` for failure.
 */
int stViewportFree(TViewport *pViewport, HINSTANCE hInstance);

#endif /* ST_VIEWPORT_H */