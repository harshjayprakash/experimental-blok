/**
 * \file ARGS.H
 * \date 21-05-2025
 * \brief Provides the ArgsInfo structure and processing arguments routine.
 */

#ifndef _BLOK_ARGS_H_
#define _BLOK_ARGS_H_

#include <Windows.h>

/**
 * \brief Args information result.
 * 
 * \details
 * Represents all the arguments flags value to be provided to the modules.
 */
typedef struct _ArgsInfo {
    int theme;         /**< The start up theme. */
    int scaleX;        /**< The grid scale in the x direction. */
    int scaleY;        /**< The grid scale in the y direction. */
    int showConsole;   /**< If the console should be displayed.*/
} ArgsInfo;

/**
 * \brief Processes the arguments.
 * 
 * \details
 * Sets the default argument values before processing the each argument. Any duplicate 
 * arguments replaces the previous flag. The current accepted arguments involves the
 * following:
 *      "--light-theme" or "--dark-theme" to specify the start up theme
 *      "--scale" to specify the grid scaling in pixels. "--scale-x" and "--scale-y" can
 *            be used for scaling an individual axis.
 *      "--show-console" displays the debug console to showing the wprintf messages.
 * 
 * \param[in] pArgs          The arguments processed result.
 * \param[in] pCommandLine   The command line arguments.
 * \return                   0 for failure, 1 for success.
 */
int blokArgsProcess(ArgsInfo *pArgs, LPCWSTR pCommandLine);

#endif // _BLOK_ARGS_H_