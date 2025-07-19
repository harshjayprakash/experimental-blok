#ifndef ST_CONTEXT_H
#define ST_CONTEXT_H

#include "../ui/viewport.h"
#include "../state/state.h"
#include "../gdi/graphics.h"
#include <windows.h>

typedef struct _Context
{
    HINSTANCE hInstance;
    int showFlag;
    TGraphics graphics;
    TViewport viewport;
    TObjectState state;
} TContext;

TContext *stContextGet(void);

TGraphics *stContextGetGraphics(void);

TViewport *stContextGetViewport(void);

TObjectState *stContextGetObjectState(void);

#endif /* ST_CONTEXT_H */