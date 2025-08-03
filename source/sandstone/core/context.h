/**
 * @file   context.h
 * @brief  Application Context and Helper Declarations.
 * @author harshjayprakash
 * @date   2025-08-03
 ****************************************************************************************/

#ifndef ST_CONTEXT_H
#define ST_CONTEXT_H

#include "../gdi/graphics.h"
#include "../state/state.h"
#include "../ui/viewport.h"
#include <windows.h>

/**
 * @brief Represents the Application Context.
 *
 * @details
 * This structure is required by the application to function. The information stored
 * involves the configuration of the graphics, user interface, entities drawn and
 * Windows handles.
 *
 * @remarks
 * - The `stSetup` and `stEntry` functions initialise and clean up the context. The
 *   caller must not attempt to manually free resources.
 */
typedef struct _Context
{
    HINSTANCE hInstance; /**< Handle to application instance. */
    int showFlag;        /**< Initial display window state. */
    TGraphics graphics;  /**< Graphics configuration. */
    TViewport viewport;  /**< The user interface. */
    TObjectState state;  /**< Entity states. */
} TContext;

/**
 * @brief Returns the shared static context object.
 *
 * @details
 * Provides access to the singleton `TContext` instance, which encapsulates graphics,
 * viewport, and object state data for the application.
 *
 * @return Pointer to the internal static `TContext` object.
 *
 * @remarks
 * - The context is statically allocated and initialised on first access. Callers must
 *   not assume ownership or attempt deallocation.
 * - It is discouraged to retrieve the context as whole, please use the other
 *   functions to retrieve the portion of the context required.
 *
 * @see stContextGetGraphics
 * @see stContextGetViewport
 * @see stContextGetObjectState
 */
TContext *stContextGet(void);

/**
 * @brief Accesses the graphics module from the shared context.
 *
 * @return Pointer to the `TGraphics` object within the static context.
 *
 * @see stContextGet
 */
TGraphics *stContextGetGraphics(void);

/**
 * @brief Accesses the viewport module from the shared context.
 *
 * @return Pointer to the `TViewport` object within the static context.
 *
 * @see stContextGet
 */
TViewport *stContextGetViewport(void);

/**
 * @brief Accesses the object state module from the shared context.
 *
 * @return Pointer to the `TObjectState` object within the static context.
 *
 * @see stContextGet
 */
TObjectState *stContextGetObjectState(void);

#endif /* ST_CONTEXT_H */