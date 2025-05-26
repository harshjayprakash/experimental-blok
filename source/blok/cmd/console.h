/**
 * @file CONSOLE.H
 * @date 21-05-2025
 * @brief Provides the console structure and lifecycle routines.
 */

#ifndef _BLOK_CONSOLE_H_
#define _BLOK_CONSOLE_H_

#include <stdio.h>

/**
 * @brief Console initialisation information.
 * 
 * @details
 * Represents the return values of allocating the console. This data must not be
 * modified.
 */
typedef struct _Console {
    int isInitialised;    /**< If the console is initialised. */
    int errorOnAlloc;     /**< If an error occurred opening the file stream. */
    FILE *pStandardOut;   /**< The standard out file stream.*/
} Console;

/**
 * @brief Initialises the console.
 * 
 * @details
 * Attempts to allocate a console window and open the standard out file stream. The
 * result of AllocConsole is stored in "isInitialised" and _wfreopen_s in "errorOnAlloc".
 * 
 * @param[in out] pConhost   The pointer to the console information.
 * @return                   0 for failure, 1 for success.
 */
int blokConsoleInit(Console *pConhost);

/**
 * @brief Frees the console.
 * 
 * @details
 * Frees the allocated console and closes the standard out file stream. This is based
 * on the values of the structure. Incorrect values may lead to undefined behaviour.
 * 
 * @param[in out] pConhost   The pointer to the console information
 * @return                   0 for failure, 1 for success.
 */
int blokConsoleFree(Console *pConhost);

#endif // _BLOK_CONSOLE_H_