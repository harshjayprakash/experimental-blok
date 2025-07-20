/**
 * @file context.h
 * @brief Application Context and Helper Declarations.
 * @author harshjayprakash
 * @date 2025-07-20
 ****************************************************************************************/

#ifndef ST_CONTEXT_H
#define ST_CONTEXT_H

#include "../ui/viewport.h"
#include "../state/state.h"
#include "../gdi/graphics.h"
#include <windows.h>

/**
 * @brief Represents the Application Context.
 *
 * @details
 *  Contains configuration, data and handles for the application.
 *
 * @remark
 *  The stSetup and stEntry functions initialise and clean up the context.
 */
typedef struct _Context
{
    /**
     * @brief Handle to application instance.
     */
    HINSTANCE hInstance;

    /**
     * @brief How the window will be displayed.
     */
    int showFlag;

    /**
     * @brief Graphics configuration.
     */
    TGraphics graphics;

    /**
     * @brief Graphical user interface.
     */
    TViewport viewport;

    /**
     * @brief Entity states.
     */
    TObjectState state;
} TContext;

/**
 * @brief Retrieves a pointer to the application context.
 *
 * @details
 *  This function stores a statically stores the instance of the application context and
 *  a reference to this is returned.
 *
 * @return A pointer to TContext.
 *
 * @remark
 *  The caller should avoid directly calling this function in favour of retrieving
 *  the specific parts required.
 * @remark
 *  The caller must not free this block of memory.
 */
TContext *stContextGet(void);

/**
 * @brief Retrieves a pointer to the graphics module.
 *
 * @details
 *  This function provides a wrapper for stContextGet and returning only the TGraphics
 *  portion.
 * 
 * @return A pointer to TGraphics.
 *
 * @remark
 *  The caller must not free this block of memory. For lifetime management, please
 *  refer to the stGraphicsInit and stGraphicsFree functions.
 */
TGraphics *stContextGetGraphics(void);

/**
 * @brief Retrieves a pointer to the viewport module.
 * 
 * @details
 *  This function provides a wrapper for stContextGet and returning only the TViewport
 *  portion.
 * 
 * @return A pointer to TViewport
 * 
 * @remark
 *  The caller must not free this block of memory. For lifetime management, please
 *  refer to the stViewportInit and stViewportFree functions.
 */
TViewport *stContextGetViewport(void);

/**
 * @brief Retrieves a pointer to the object state module.
 * 
 * @details
 *  This function provides a wrapper for stContextGet and returning only the TObjectState
 *  portion.
 * 
 * @return A pointer to TObjectState.
 * 
 * @remark
 *  The caller must not free this block of memory. For lifetime management, please
 *  refer to the stStateInit and stStateFree functions.
 */
TObjectState *stContextGetObjectState(void);

#endif /* ST_CONTEXT_H */