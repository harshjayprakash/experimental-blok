#ifndef _BLOK_LIFECYCLE_H_
#define _BLOK_LIFECYCLE_H_

#include "context.h"

int blokInit(Context *pContext, HINSTANCE hInstance, LPWSTR pCommandLine, DWORD showFlag);

int blokRun(Context *pContext);

int blokFree(Context *pContext);

#endif /* _BLOK_LIFECYCLE_H_ */