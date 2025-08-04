/**
 * @file   args.h
 * @brief  Argument Parsing Declarations.
 * @author harshjayprakash
 * @date   2025-08-03
 ****************************************************************************************/

#ifndef ST_ARGS_H
#define ST_ARGS_H

#include <windows.h>

/**
 * @brief Holds the parsed command-line configuration values.
 *
 * @details
 * This structure receives the output of `stArgsProcess` and is used to configure
 * theme selection and grid scaling.
 *
 * The values inside can be set to their default values required for the program via the
 * `ST_ARGS_SET_DEFAULT` macro, passing the structure as a parameter.
 */
typedef struct _ParsedArgs
{
    unsigned int theme;  /**< Start-up theme preference. */
    unsigned int scaleX; /**< Horizontal scale factor for the grid. */
    unsigned int scaleY; /**< Vertical scale factor for the grid. */
} TParsedArgs;

#define ST_ARGS_SCALE_DEFAULT 15

#define ST_ARGS_SET_DEFAULT(tParsedArgs)                                                 \
    tParsedArgs.theme = 0;                                                               \
    tParsedArgs.scaleX = ST_ARGS_SCALE_DEFAULT;                                          \
    tParsedArgs.scaleY = ST_ARGS_SCALE_DEFAULT

/**
 * @brief Parses command-line arguments into configuration flags.
 *
 * @details
 * This function interprets a Unicode command-line string and stores the values in the
 * `TParsedArgs structure with theme and scale settings. Flags are extracted using
 * case-insensitive matching and processed in sequential order. If flags appear multiple
 * times, subsequent values override the previous ones.
 *
 * The following arguments are available:
 *      `--dark-theme`      Sets to the dark theme.
 *      `--light-theme`     Sets to the light theme.
 *      `--scale`           Sets both horizontal and vertical scaling.
 *      `--scale-x`         Sets the horizontal scaling.
 *      `--scale-y`         Sets the vertical scaling.
 *
 * The scale functions are validated with the `_ST_VALIDATE_SCALING` macro. If the value
 * is invalid, the `ST_ARGS_SCALE_DEFAULT` value is set.
 *
 * @param[out] pParsedArgs    Pointer to TParsedArgs structure.
 * @param[in]  pCommandLine   Pointer to a command-line string.
 *                            This should originate from `wWinMain` or `GetCommandLineW`.
 *
 * @return
 * `1` if parsing was successful, or `0` if inputs were invalid or parsing failed.
 *
 * @remarks
 * - Default values are applied via `ST_ARGS_SET_DEFAULT` before parsing.
 * - The `CommandLineToArgvW` function is used internally; other command-line sources may
 *   produce undefined behaviour.
 * - Flags are expected in `--flag` format with no assumptions about order. The only
 *   exception involves flags that require input directly after.
 *
 * @see TParsedArgs
 * @see TArgMode
 * @see TTheme
 */
int stArgsParse(TParsedArgs *pParsedArgs, LPCWSTR pCommandLine);

#endif /* ST_ARGS_H */