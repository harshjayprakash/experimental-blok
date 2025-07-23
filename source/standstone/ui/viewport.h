/**
 * @file viewport.h
 * @brief Viewport Declarations.
 * @author harshjayprakash
 * @date 2025-07-23
 ****************************************************************************************/

#ifndef ST_VIEWPORT_H
#define ST_VIEWPORT_H

#include "controls/button.h"
#include "controls/text.h"
#include "controls/progressbar.h"
#include "controls/toggle.h"
#include "components/canvas.h"
#include "components/panel.h"
#include "frame/window.h"
#include <windows.h>

/**
 * @brief The Viewport Module.
 * 
 * @details
 *  Contains the components required for the user interface. This is managed via the
 *  stViewport* functions.
 */
typedef struct _Viewport
{
    /** @brief The native window data. */
    TWindow window;
    /** @brief The window client area. */
    RECT region;
    /** @brief The mouse position relative to the window. */
    POINT mousePos;
    /** @brief The font used for rendering. */
    HFONT hFont;
    /** @brief Is left mouse button down. */
    BOOL isLeftMouseDown;
    /** @brief Is right mouse button down. */
    BOOL isRightMouseDown;

    /** @brief The canvas component. */
    TCanvas canvas;
    /** @brief Is canvas locked. */
    BOOL isCanvasLocked;
    /** @brief Is grid lines visible. */
    BOOL isGridVisible;

    /** @brief The action and information panel component. */
    TPanel panel;
    /** @brief Is interface visible. */
    BOOL isInterfaceVisible;
    /** @brief The box coordinates label. */
    TText coordinatesText;
    /** @brief The clear all button. */
    TButton clearAllButton;
    /** @brief The generate one obstruct button. */
    TButton generateButton;
    /** @brief The obstruct count label. */
    TText obstructCountText;
    /** @brief The obstruct relative memory process bar. */
    TProgressBar obstructMemoryBar;
    /** @brief The locked canvas toggle label. */
    TText lockedToggleText;
    /** @brief The canvas locked toggle control. */
    TToggle lockedToggle;
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
 * @param[in, out] pViewport A valid pointer to the TViewport.
 * @param[in]      hInstance The handle to the application instance.
 * @return 1 for success, 0 for failure.
 * 
 * @remark
 *  If the font creation fails, the application will continue using the base system
 *  font.
 * @remark
 *  If the native window creation fails, the application will exit. The corresponding the
 *  stViewportFree must be called.
 */
int stViewportInit(TViewport *pViewport, HINSTANCE hInstance);

/**
 * @brief Show the viewport.
 * 
 * @details
 *  A wrapper for the stWindowShow function.
 * 
 * @param[in, out] pViewport A valid pointer to the TViewport.
 * @param[in]      showFlag  How the window will be displayed.
 * @return -1 for failure, or the exit code.
 */
int stViewportShow(TViewport *pViewport, DWORD showFlag);

/**
 * @brief Free the viewport.
 * 
 * @details
 *  Frees the allocated resources for the window and font.
 * 
 * @param[in, out] pViewport A valid pointer to the TViewport.
 * @param[in]      hInstance The handle to the application instance.
 * @return 1 for success, 0 for failure.
 */
int stViewportFree(TViewport *pViewport, HINSTANCE hInstance);

#endif /* ST_VIEWPORT_H */