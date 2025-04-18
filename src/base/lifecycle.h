#ifndef _BLOK_LIFECYCLE_H_
#define _BLOK_LIFECYCLE_H_

#include "context.h"

void BlokInit(Context *context, HINSTANCE instance, LPWSTR commandLine, DWORD showFlag);

void BlokRun(Context *context);

void BlokFree(Context *context);

#endif // _BLOK_LIFECYCLE_H_