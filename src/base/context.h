#ifndef _BLOK_CONTEXT_H_
#define _BLOK_CONTEXT_H_

#include "../ui/viewport.h"
#include "../store/state.h"
#include "../gdi/graphics.h"
#include "../cmd/console.h"
#include <Windows.h>

typedef struct _Context {
    HINSTANCE instance;
    LPWSTR commandLine;
    DWORD showFlag;
    Console console;
    Graphics graphics;
    Viewport viewport;
    State state;
    void *result;
} Context;

Context *BlokContextGet(void);

Graphics *BlokContextGetGraphics(void);

Viewport *BlokContextGetViewport(void);

State *BlokContextGetState(void);

#endif // _BLOK_CONTEXT_H_