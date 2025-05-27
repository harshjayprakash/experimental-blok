/**
 * @file CONTEXT.H
 * @date 26-05-2025
 * @brief Provides the context structure and helper functions.
 */

#ifndef _BLOK_CONTEXT_H_
#define _BLOK_CONTEXT_H_

#include "ui/viewport.h"
#include "state/state.h"
#include "gdi/graphics.h"
#include "cmd/console.h"
#include <windows.h>

/**
 * @brief Program context. 
 * 
 * @details
 * Represents global program data.
 */
typedef struct _Context {
    HINSTANCE hInstance;   /**< The instance handle. */
    LPWSTR pCommandLine;   /**< The command line arguments. */
    DWORD showFlag;        /**< The window show flag. */
    Console console;       /**< The console initialisation data. */
    Graphics graphics;     /**< The graphics tools. */
    Viewport viewport;     /**< The user interface. */
    State state;           /**< The object state. */
    void *pResult;         /**< The NOT IMPLEMENTATED result system. */
} Context;

/**
 * @brief Get the context instance.
 * 
 * @details
 * Retrieves the global context instance statically stored within this function. The user
 * should not directly modify this instance. The ownership of the memory is not
 * transferred to the caller. 
 *
 * @return A pointer to the context instance object.
 */
Context *blokContextGet(void);

/**
 * @brief Get the graphics module instance.
 * 
 * @return A pointer to the graphics instance object.
 */
Graphics *blokContextGetGraphics(void);

/**
 * @brief Get the viewport module instance.
 * 
 * @return A pointer to the viewport instance object.
 */
Viewport *blokContextGetViewport(void);

/**
 * @brief Get the object state instance.
 * 
 * @return A pointer to the state instance object.
 */
State *blokContextGetState(void);

#endif // _BLOK_CONTEXT_H_