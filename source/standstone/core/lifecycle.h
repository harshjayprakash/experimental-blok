#ifndef ST_CORE_LIFECYCLE_H
#define ST_CORE_LIFECYCLE_H

#include "../cmd/args.h"
#include "../context.h"
#include <minwindef.h>

int stSetup(HINSTANCE hInstance, LPWSTR pCommandLine, int showFlag);

int stEntry(TContext *pContext, void *pArgs);

#endif /* ST_CORE_LIFECYCLE_H */