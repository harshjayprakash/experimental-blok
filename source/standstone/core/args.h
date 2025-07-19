/**
 * @file args.h
 * @brief Argument parsing declarations.
 * @author harshjayprakash
 * @date 2025-07-19
 ****************************************************************************************/

#ifndef ST_ARGS_H
#define ST_ARGS_H

#include <windows.h>

/**
 * @brief Holds the parsed command-line configuration values.
 *
 * This structure receives the output of `blokArgsProcess` and is used to configure
 * theme selection, grid and box scale, and console visibility.
 */
typedef struct _ParsedArgs
{
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
} TParsedArgs;

#define ST_ARGS_SCALE_DEFAULT 15

#define ST_ARGS_SET_DEFAULT(a)                                                          \
    a.theme = 0;                                                                        \
    a.scaleX = ST_ARGS_SCALE_DEFAULT;                                                   \
    a.scaleY = ST_ARGS_SCALE_DEFAULT                                                                       

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
int stArgsProcess(TParsedArgs *pParsedArgs, LPCWSTR pCommandLine);

#endif /* ST_ARGS_H */