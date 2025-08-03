/**
 * @file   lifecycle.h
 * @brief  Setup and Entry Declarations.
 * @author harshjayprakash
 * @date   2025-07-28
 ****************************************************************************************/

#ifndef ST_LIFECYCLE_H
#define ST_LIFECYCLE_H

#include "args.h"
#include "context.h"
#include <windows.h>

/**
 * @brief Semantic exit codes.
 *
 * @details
 * Represents specific application termination states returned from the lifecycle
 * functions (`stSetup` and `stEntry`).

 * The exit codes are bit-shifted to prevent clashing with the exit code from
 * `PostQuitMessage`.
 *
 * @remark
 * - These exit codes are passed to `wWinMain` and provide diagnostics on potential
 *   errors, when initialising the application.
 */
typedef enum _ExitStatus
{
    ST_EXIT_SUCCESS = (0x0 << 6), /**< Application exited successfully with no errors. */
    ST_EXIT_NULLPTR =
        (0x1 << 6), /**< A required pointer was NULL during initialisation. */
    ST_EXIT_STATE_ERROR = (0x2 << 6), /**< Object state module initialisation failed. */
    ST_EXIT_GRAPHICS_ERROR = (0x3 << 6),   /**< Graphics module initialisation failed. */
    ST_EXIT_VIEWPORT_ERROR = (0x4 << 6),   /**< Viewport module initialisation failed. */
    ST_EXIT_CLEANUP_ERROR = (0x5 << 6),    /**< Clean-up operation failed. */
    ST_EXIT_INSTANCE_RUNNING = (0x6 << 6), /**< Existing instance is running. */
    ST_EXIT_INSTANCE_CHECK_ERROR = (0x7 << 6), /**< Instance mutex creation failed. */
} TExitStatus;

/**
 * @brief Setup.
 *
 * @details
 * This function zero initialises the application context and then proceeds to parse the
 * arguments. The provided instance handle and show flag are saved within the context.
 *
 * @param[in] hInstance      Handle to the application instance.
 * @param[in] pCommandLine   Pointer to the command-line.
 * @param[in] showFlag       Initial window display state.
 * @return Zero for success, non-zero for failure. For specific return values, please
 *         refer to TExitStatus.
 *
 * @remarks
 * - This function must be called from wWinMain as an entrypoint into the Sandstone
 *   application. stEntry is called internally.
 * - The showFlag value is not checked and will be passed to ShowWindow.
 *
 * @see stEntry
 * @see TContext
 * @see stArgsParse
 * @see TParsedArgs
 */
int stSetup(HINSTANCE hInstance, LPWSTR pCommandLine, int showFlag);

/**
 * @brief Entry.
 *
 * @details
 * This function initialises all the contextual modules, based on the provided parsed
 * arguments. All memory is freed when exiting this function.
 *
 * @param[in, opt] pContext   Pointer to application context.
 * @param[in]      pArgs      Pointer to parsed arguments.
 * @return Zero for success, non-zero for failure. For specific return values, please
 *         refer to TExitStatus.
 *
 * @remarks
 * - This function should not be called by the user. It is called by stSetup,
 *   providing the valid arguments, after setup. An attempt to call this function may
 *   lead to undefined behaviour.
 * - If any of the initialisation of modules fails, the function will exit, returning
 *   the appropriate exit code (passed to wWinMain). Any memory allocated is cleaned up.
 *
 * @see TContext
 * @see TParsedArgs
 */
int stEntry(TContext *pContext, TParsedArgs *pArgs);

#endif /* ST_LIFECYCLE_H */