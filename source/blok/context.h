#ifndef _BLOK_CONTEXT_H_
#define _BLOK_CONTEXT_H_

#include "ui/viewport.h"
#include "state/state.h"
#include "gdi/graphics.h"
#include "cmd/console.h"
#include <windows.h>

typedef struct _Context
{
    HINSTANCE hInstance;
    LPWSTR pCommandLine;
    DWORD showFlag;
    TConsoleInfo console;
    TGraphics graphics;
    TViewport viewport;
    TObjectState state;
    void *pResult;
} TContext;

TContext *blokContextGet(void);

TGraphics *blokContextGetGraphics(void);

TViewport *blokContextGetViewport(void);

TObjectState *blokContextGetObjectState(void);

#endif /* _BLOK_CONTEXT_H_ */