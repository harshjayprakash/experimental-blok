#ifndef _BLOK_CONTEXT_H_
#define _BLOK_CONTEXT_H_

#include "ui/viewport.h"
#include "state/state.h"
#include "gdi/graphics.h"
#include "cmd/console.h"
#include <windows.h>

typedef struct _Context {
    HINSTANCE hInstance;
    LPWSTR pCommandLine;
    DWORD showFlag;
    Console console;
    Graphics graphics;
    Viewport viewport;
    State state;
    void *pResult;
} Context;

Context *blokContextGet(void);

Graphics *blokContextGetGraphics(void);

Viewport *blokContextGetViewport(void);

State *blokContextGetState(void);

#endif /* _BLOK_CONTEXT_H_ */