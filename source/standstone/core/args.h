/**
 * @file args.h
 * @brief Argument Parsing Declarations.
 * @author harshjayprakash
 * @date 2025-07-20
 ****************************************************************************************/

#ifndef ST_ARGS_H
#define ST_ARGS_H

#include <windows.h>

/**
 * @brief Holds the parsed command-line configuration values.
 *
 * @details
 *  This structure receives the output of `stArgsProcess` and is used to configure
 *  theme selection and grid scaling.
 */
typedef struct _ParsedArgs
{
    /**
     * @brief Theme preference selected via `--dark-theme` or `--light-theme`.
     *
     * @details
     *  This value corresponds to the TTheme enum:
     *  - `0` -> Unset / Default Dark.
     *  - `1` -> Dark theme.
     *  - `2` -> Light theme.
     */
    unsigned int theme;

    /**
     * @brief Horizontal scale factor for the grid.
     *
     * @details
     *  Set via the `--scale-x` flag.
     */
    unsigned int scaleX;

    /**
     * @brief Vertical scale factor for the grid.
     *
     * @details
     *  Set via the `--scale-y` flag.
     */
    unsigned int scaleY;
} TParsedArgs;


/**
 * @defgroup Argument Default Values
 * @{
 */

#define ST_ARGS_SCALE_DEFAULT 15

#define ST_ARGS_SET_DEFAULT(tParsedArgs)                                                \
    tParsedArgs.theme = 0;                                                              \
    tParsedArgs.scaleX = ST_ARGS_SCALE_DEFAULT;                                         \
    tParsedArgs.scaleY = ST_ARGS_SCALE_DEFAULT                                                                       

/** @} */

/**
 * @brief Parses Command Line Arguments.
 *
 * @details
 *  Interprets a Unicode command line and sets the configuration flags for theme and
 *  scale. There are no short form flags.
 *
 * @param[out] pParsedArgs  A pointer to a valid `TArgsResult` structure.
 * @param[in]  pCommandLine A null-terminated wide string with command line arguments.
 * @return One if argument parsing was successful, otherwise zero for failure.
 *
 * @remark
 *  Default flags are applied if certain flags are omitted. Any duplicate flags
 *  overwrite the previous.
 * @remark
 *  The command line must be from the wWinMain entrypoint or from the GetCommandLineW
 *  function. Any value from other sources performs undefined behaviour as this value
 *  is passed to CommandLineToArgv.
 */
int stArgsProcess(TParsedArgs *pParsedArgs, LPCWSTR pCommandLine);

#endif /* ST_ARGS_H */