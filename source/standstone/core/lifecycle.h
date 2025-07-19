#ifndef ST_CORE_LIFECYCLE_H
#define ST_CORE_LIFECYCLE_H

#include "args.h"
#include "context.h"
#include <windows.h>

int stSetup(HINSTANCE hInstance, LPWSTR pCommandLine, int showFlag);

int stEntry(TContext *pContext, TParsedArgs *pArgs);

#endif /* ST_CORE_LIFECYCLE_H */