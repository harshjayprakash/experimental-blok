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
 * Contains the resulting processed arguments by the "blokArgsProcess" routine. This
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
     * Denotes whether the console should initialised on startup. This shows the log
     * messages of the program.
     */
    int showConsole;
} TArgsResult;

/**
 * @brief Process the command line.
 * 
 * @pre pCommandLine must be a valid obtained from `wWinMain` or `GetCommandLineW`.
 * @pre pArgs must be a non-null pointer to a `TArgsResult` structure.
 * @post pArgs contains the parsed arguments.
 * @post Duplicate arguments overwrite the previous occurrences.
 * @post Returns a status code:
 *       - `0` if parsing failed due to any of the arguments with the value of NULL.
 *       - `1` if parsing was successful.
 *
 * @param[in,out] pArgs Pointer to the `TArgsResult` structure.
 * @param[in] pCommandLine Command line string.
 * @return Status code (0 = failure, 1 = success).
 *
 * @details
 * Applies default values before proceeding to process arguments. Argument detection is
 * case insensitive. The `pArgs` memory is managed by the caller.
 */
int blokArgsProcess(TArgsResult *pArgs, LPCWSTR pCommandLine);

#endif /* _BLOK_ARGS_H_ */