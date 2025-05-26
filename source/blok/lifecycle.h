/**
 * @file LIFECYCLE.H
 * @date 26-05-2025
 * @brief Provides the program lifecycle functions.
 */

#ifndef _BLOK_LIFECYCLE_H_
#define _BLOK_LIFECYCLE_H_

#include "context.h"

/**
 * @brief Initialises the program.
 *
 * @details
 * Saves the given WinMain arguments, then proceeds to process the command line arguments.
 * After this the console is initialised if and only if requested. Then the other modules
 * are initialised.
 * 
 * @param[in out] pContext       The mutable pointer to the context.
 * @param[in]     hInstance      The instance handle.
 * @param[in]     pCommandLine   The command line arguments.
 * @param[in]     showFlag       The window show flag.
 * @return                       0 for failure, 1 for success. 
 */
int blokInit(Context *pContext, HINSTANCE hInstance, LPWSTR pCommandLine, DWORD showFlag);

/**
 * @brief Starts the program.
 * 
 * @details
 * A wrapper for calling the show viewport function.
 *
 * @param[in out] pContext   The mutable pointer to the context.
 * @return                   (__CONFLICT__)
 */
int blokRun(Context *pContext);

/**
 * @brief Cleans up the program.
 *
 * @details
 * Frees all the memory allocated by the program's modules.
 * 
 * @param[in out] pContext   The pointer to the context.
 * @return                   0 for failure, 1 for success. 
 */
int blokFree(Context *pContext);

#endif // _BLOK_LIFECYCLE_H_