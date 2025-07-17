/**
 * @file args.h
 * @brief Argument parsing declarations.
 * 
 * Defines the configuration structure and API used to process command-line arguments for
 * theme selection, grid scaling and console visibility. All input is expected in the
 * Unicode format and parsed using Windows-specific command-line functions.
 * 
 * @author harshjayprakash
 * @date 2025-07-17
 ****************************************************************************************/

#ifndef _BLOK_ARGS_H_
#define _BLOK_ARGS_H_

#include <windows.h>

/**
 * @brief Holds the parsed command-line configuration values.
 * 
 * This structure receives the output of `blokArgsProcess` and is used to configure
 * theme selection, grid and box scale, and console visibility.
 */
typedef struct _ArgsResult {
    /**
     * @brief Theme preference selected via `--dark-theme` or `--light-theme`.
     * 
     * - `0` -> Unset / Default Dark.
     * - `1` -> Dark theme.
     * - `2` -> Light theme.
     */
    unsigned int theme;

    /**
     * @brief Horizontal scale factor for the grid.
     * 
     * Set via the `--scale-x` flag.
     */
    unsigned int scaleX;

    /**
     * @brief Vertical scale factor for the grid.
     * 
     * Set via the `--scale-y` flag.
     */
    unsigned int scaleY;

    /**
     * @brief Whether to show the console at launch.
     * 
     * Set via the `--show-console` flag.
     */
    unsigned int showConsole;
} TArgsResult;

/**
 * @brief Parses command-line arguments into a populated TArgsResult structure.
 * 
 * This function interprets a Unicode command line and sets configuration flags for the
 * theme, scale, and console visibility. There are no short form flags.
 * 
 * @param[out] pArgs        A pointer to a valid TArgsResult structure.
 * @param[in]  pCommandLine A null-terminated wide string from `wWinMain` or 
 *                          `GetCommandLineW`.
 * @return One if argument parsing was successful; zero otherwise.
 * 
 * @remarks
 * - The caller is responsible for allocating a valid `TArgsResult`.
 * - Default flags are applied if certain flags are omitted.
 * - Undefined behaviour for command-line strings from other sources.
 */
int blokArgsProcess(TArgsResult *pArgs, LPCWSTR pCommandLine);

#endif /* _BLOK_ARGS_H_ */