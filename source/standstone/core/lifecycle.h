/**
 * @file lifecycle.h
 * @brief Setup and Entry Declarations.
 * @author harshjayprakash
 * @date 2025-07-20
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
 *  Represents specific application termination states returned from the lifecycle
 *  functions (stSetup and stEntry).
 * 
 * @remark
 *  These exit codes are passed to `wWinMain` and provide diagnostics on potential
 *  errors, when initialising the application.
 */
typedef enum _ExitStatus
{
    /**
     * @brief Application exited successfully with no errors.
     */
    ST_EXIT_SUCCESS = 0,

    /**
     * @brief A required pointer was NULL during initialisation.
     *
     * @details
     *  Returned from stSetup or stEntry, if any required arguments are NULL.
     */
    ST_EXIT_NULLPTR = 1,

    /**
     * @brief The application object state module initialisation failed.
     */
    ST_EXIT_STATE_ERROR = 2,

    /**
     * @brief The application graphics module initialisation failed.
     */
    ST_EXIT_GRAPHICS_ERROR = 3,

    /**
     * @brief The application viewport module initialisation failed.
     */
    ST_EXIT_VIEWPORT_ERROR = 4,
} TExitStatus;

/**
 * @brief Setup Sandstone.
 *
 * @details
 *  Zero initialises the application context and then proceeds to parse the arguments.
 *  The application instance and show flag is saved within the context.
 * 
 * @param[in] hInstance    A valid handle to the application instance.
 * @param[in] pCommandLine The command line arguments.
 * @param[in] showFlag     How the window should be displayed.
 * @return Zero for success, non-zero for failure. For specific return values, please
 *         refer to TExitStatus.
 * 
 * @remark
 *  This function must be called from wWinMain as an entrypoint into the Sandstone
 *  application. stEntry is called internally.
 * @remark
 *  The showFlag value is not checked and will be passed to ShowWindow.
 */
int stSetup(HINSTANCE hInstance, LPWSTR pCommandLine, int showFlag);

/**
 * @brief Sandstone Entry.
 *
 * @details
 *  Initialises all the contextual modules, based on the provided parsed arguments. All
 *  memory is freed when exiting this function.
 * 
 * @param[in, opt] pContext A valid pointer to the application context.
 * @param[in]      pArgs    A valid pointer to the TParsedArgs structure.
 * @return Zero for success, non-zero for failure. For specific return values, please
 *         refer to TExitStatus.
 * 
 * @remark
 *  This function should not be called by the user. It is called by stSetup,
 *  providing the valid arguments, after setup. An attempt to call this function may lead
 *  to undefined behaviour.
 * @remark
 *  If any of the initialisation of modules fails, the function will exit, returning the
 *  appropriate exit code (passed to wWinMain). Any memory allocated is cleaned up.
 */
int stEntry(TContext *pContext, TParsedArgs *pArgs);

#endif /* ST_LIFECYCLE_H */