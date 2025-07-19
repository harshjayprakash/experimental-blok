#ifndef ST_LIFECYCLE_H
#define ST_LIFECYCLE_H

#include "context.h"

int stInit(
    TContext *pContext, HINSTANCE hInstance, LPWSTR pCommandLine, DWORD showFlag);

int stRun(TContext *pContext);

int stFree(TContext *pContext);

#endif /* ST_LIFECYCLE_H */