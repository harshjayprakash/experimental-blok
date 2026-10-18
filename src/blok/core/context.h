#ifndef BLOK_CONTEXT_H
#define BLOK_CONTEXT_H

#include "../gdi/graphics.h"
#include "../state/state.h"
#include "../ui/viewport.h"
#include <windows.h>

typedef struct _Context
{
    HINSTANCE hInstance;
    int showFlag;
    TGraphics graphics;
    TViewport viewport;
    TObjectState state;
} TContext;

TContext *BlokContextGet(void);

TGraphics *BlokContextGetGraphics(void);

TViewport *BlokContextGetViewport(void);

TObjectState *BlokContextGetObjectState(void);

#endif /* BLOK_CONTEXT_H */