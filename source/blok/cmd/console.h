/**
 * @file   console.h
 * @brief  Console Allocation.
 * @author harshjayprakash
 * @date   2025-06-07
 ****************************************************************************************/

#ifndef _BLOK_CONSOLE_H_
#define _BLOK_CONSOLE_H_

#include <stdio.h>

/**
 * @brief Console initialisation information.
 * 
 * @details
 * Contains the resulting values for initialising the console and file stream. These
 * values must not be modified by the user.
 */
typedef struct _ConsoleInfo {
    /**
     * @brief If the console is initialised.
     * 
     * @details
     * A non-zero value denoting the console was initialised. A zero value for not
     * initialised. The value is determined by the `AllocConsole` function.
     */
    int isInitialised;
    
    /**
     * @brief If an error occurred while opening the file stream.
     * 
     * @details
     * A zero value for successfully opening the standard out file stream. Non-zero
     * for failure.
     */
    int errorOnAlloc;

    /**
     * @brief The standard out file stream.
     * 
     * @details
     * NULL if opening file stream fails.
     */
    FILE *pStandardOut;
} TConsoleInfo;

/**
 * @brief Allocates the console.
 * 
 * @param[in,out] pConsoleInfo The pointer to the `TConsoleInfo` structure.
 * @return A status code:
 *         - `0` if console allocation failed due to null parameter, or has previously
 *           been initialised.
 *         - `1` if console allocation was successful.
 * 
 * @pre pConsoleInfo must be a non-null pointer to the `TConsoleInfo` structure.
 * @pre pConsoleInfo must not be previously initialised.
 * 
 * @post pConsoleInfo contains the console initialisation data.
 * @post Returns a status code indicating success or failure.
 * 
 * @details
 * Attempts to allocate a console and then proceeds to open the standard out file stream.
 * The caller may check inside of the structure for more information if the operation
 * failed, but must not modify these values. The caller is responsible for calling the
 * equivalent `blokConsoleFree` function for clean-up.
 */
int blokConsoleInit(TConsoleInfo *pConsoleInfo);

/**
 * @brief Free the console.
 * 
 * @param[in,out] pConsoleInfo Pointer to the `TConsoleInfo` structure.
 * @return A status code:
 *         - `0` if freeing the console failed due to a null parameter or has not been
 *           initialised.
 *         - `1` if freeing the console was successful.
 * 
 * @pre pConsoleInfo must be a non-null pointer to the `TConsoleInfo` structure.
 * @pre pConsoleInfo must be previously initialised.
 * 
 * @post pConsoleInfo->isInitialised == 0
 * @post Returns a status code indicating success or failure.
 * 
 * @details
 * Attempts to close the file stream and free the console. The resulting values are
 * checked to calculate the return value.
 */
int blokConsoleFree(TConsoleInfo *pConsoleInfo);

#endif /* _BLOK_CONSOLE_H_ */