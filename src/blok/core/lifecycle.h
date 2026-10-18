#ifndef BLOK_LIFECYCLE_H
#define BLOK_LIFECYCLE_H

#include "args.h"
#include "context.h"
#include <windows.h>

typedef enum _ExitStatus
{
    BLOK_EXIT_SUCCESS = (0x0 << 6),
    BLOK_EXIT_NULLPTR = (0x1 << 6),
    BLOK_EXIT_STATE_ERROR = (0x2 << 6),
    BLOK_EXIT_GRAPHICS_ERROR = (0x3 << 6),
    BLOK_EXIT_VIEWPORT_ERROR = (0x4 << 6),
    BLOK_EXIT_CLEANUP_ERROR = (0x5 << 6),
    BLOK_EXIT_INSTANCE_RUNNING = (0x6 << 6),
    BLOK_EXIT_INSTANCE_CHECK_ERROR = (0x7 << 6),
} TExitStatus;

int BlokSetup(HINSTANCE hInstance, LPWSTR pCommandLine, int showFlag);

int BlokEntry(TContext *pContext, TParsedArgs *pArgs);

#endif /* BLOK_LIFECYCLE_H */