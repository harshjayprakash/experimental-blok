#ifndef _BLOK_LIFECYCLE_H_
#define _BLOK_LIFECYCLE_H_

#include "context.h"

int blokInit(
    TContext *pContext, HINSTANCE hInstance, LPWSTR pCommandLine, DWORD showFlag);

int blokRun(TContext *pContext);

int blokFree(TContext *pContext);

#endif /* _BLOK_LIFECYCLE_H_ */