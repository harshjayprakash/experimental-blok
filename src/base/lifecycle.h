#ifndef _BLOK_LIFECYCLE_H_
#define _BLOK_LIFECYCLE_H_

#include "context.h"

void blokInit(Context *context, HINSTANCE instance, LPWSTR commandLine, DWORD showFlag);

void blokRun(Context *context);

void blokFree(Context *context);

#endif // _BLOK_LIFECYCLE_H_