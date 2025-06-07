/**
 * @file   args.h
 * @brief  Argument Processing.
 * @author harshjayprakash
 * @date   2025-06-07
 ****************************************************************************************/

#ifndef _BLOK_ARGS_H_
#define _BLOK_ARGS_H_

#include <windows.h>

/**
 * @brief Resulting arguments.
 * 
 * @details
 * Contains the resulting processed arguments by the `blokArgsProcess` routine. This
 * result provides the configuration to the rest of the program modules. These values
 * must not be modified by the user.
 */
typedef struct _ArgsResult {
    /**
     * @brief The start up theme.
     * 
     * @details
     * Denotes the theme the program should start with. This value is set via the
     * "--light-theme" or "--dark-theme" command line arguments.
     */
    int theme;

    /**
     * @brief The grid scale in the x direction.
     * 
     * @details
     * This value denotes the x axis grid scale and box width. This value is set via the
     * "--scale-x [int]" argument.
     */
    int scaleX;

    /**
     * @brief The grid scale in the y direction.
     * 
     * @details
     * This value denotes the x axis grid scale and box width. This value is set via the
     * "--scale-y [int]" argument.
     */
    int scaleY;

    /**
     * @brief If the console should be visible.
     * 
     * @details
     * Denotes whether the console should initialised on start-up. This shows the log
     * messages of the program.
     */
    int showConsole;
} TArgsResult;

/**
 * @brief Process the command line.
 * 
 * @param[in,out] pArgs Pointer to the `TArgsResult` structure.
 * @param[in] pCommandLine Command line string.
 * @return A status code:
 *         - `0` if parsing failed due to any of the function arguments are NULL.
 *         - `1` if parsing was successful.
 * 
 * @pre pArgs must be a non-null pointer to the `TArgsResult` structure.
 * @pre pCommandLine must be a valid string obtained from `wWinMain` or `GetCommandLineW`.
 * 
 * @post pArgs contains the parsed arguments.
 * @post Returns a status code indicating success or failure.
 * 
 * @details
 * Applies default values to `pArgs` before proceeding to process arguments. Argument
 * detection is case insensitive. Duplicate arguments overwrites the last occurrence.
 */
int blokArgsProcess(TArgsResult *pArgs, LPCWSTR pCommandLine);

#endif /* _BLOK_ARGS_H_ */