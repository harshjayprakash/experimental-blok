#ifndef ST_CORE_LIFECYCLE_H
#define ST_CORE_LIFECYCLE_H

#include "args.h"
#include "context.h"
#include <windows.h>

typedef enum _ExitStatus
{
    ST_EXIT_SUCCESS = 0,
    ST_EXIT_NULLPTR = 1,
    ST_EXIT_STATE_ERROR = 2,
    ST_EXIT_GRAPHICS_ERROR = 3,
    ST_EXIT_VIEWPORT_ERROR = 4,
} TExitStatus;

int stSetup(HINSTANCE hInstance, LPWSTR pCommandLine, int showFlag);

int stEntry(TContext *pContext, TParsedArgs *pArgs);

#endif /* ST_CORE_LIFECYCLE_H */