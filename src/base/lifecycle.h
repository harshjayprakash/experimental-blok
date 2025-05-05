#ifndef _BLOK_LIFECYCLE_H_
#define _BLOK_LIFECYCLE_H_

#include "context.h"

void blokInit(Context *pContext, HINSTANCE hInstance, LPWSTR pCommandLine, DWORD showFlag);

void blokRun(Context *pContext);

void blokFree(Context *pContext);

#endif // _BLOK_LIFECYCLE_H_