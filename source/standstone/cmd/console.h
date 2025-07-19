/**
 * @file console.h
 * @brief Console lifecycle declarations.
 * @author harshjayprakash
 * @date 2025-07-19
 ****************************************************************************************/

#ifndef ST_CONSOLE_H
#define ST_CONSOLE_H

#include <stdio.h>

/**
 * @brief Holds the console initialisation results.
 * 
 * This structure receives the resulting values from allocating the console
 * within `blokConsoleInit`.
 * 
 * @remarks
 * - The data within this structure must not be modified.
 */
typedef struct _ConsoleInfo
{
    /**
     * @brief Whether the console has been initialised.
     * 
     * - Zero -> Not initialised.
     * - Non-Zero -> Initialised.
     */
    int isInitialised;

    /**
     * @brief Whether an error occurred when allocating the stdout file stream.
     * 
     * - Zero -> Success.
     * - Non-Zero -> Failure.
     */
    int errorOnAlloc;

    /**
     * @brief The standard output stream.
     */
    FILE *pStandardOut;
} TConsoleInfo;

/**
 * @brief Initialises the console.
 * 
 * This function attempts to allocate a console and attaches the standard out file
 * stream. Updates the `TConsoleInfo`. Failure automatically frees any resources
 * allocated.
 * 
 * @param[out] pConsoleInfo A pointer to a valid `TConsoleInfo` structure.
 * @return One if allocation was successful; zero otherwise.
 * 
 * @remarks
 * - The caller is responsible for allocating a valid `TConsoleInfo`.
 * - The caller is responsible for calling `blokConsoleFree` when cleaning up.
 * - This can only be called once as a limitation of `AllocConsole`.
 */
int stConsoleInit(TConsoleInfo *pConsoleInfo);

/**
 * @brief Free the console.
 * 
 * Frees the existing console and closes the attached standard out file stream. Updates
 * the `TConsoleInfo`.
 * 
 * @param[out] pConsoleInfo A pointer to a valid `TConsoleInfo` structure.
 * @return One if releasing the console was successful; zero otherwise.
 * 
 * @remarks
 * - The caller is responsible for using the same structure instance used within the
 *   `blokConsoleInit`.
 */
int stConsoleFree(TConsoleInfo *pConsoleInfo);

#endif /* ST_CONSOLE_H */