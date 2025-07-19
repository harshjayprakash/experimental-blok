#include "context.h"

TContext *blokContextGet(void)
{
    static TContext context;
    return &context;
}

TGraphics *blokContextGetGraphics(void)
{
    return &blokContextGet()->graphics;
}

TViewport *blokContextGetViewport(void)
{
    return &blokContextGet()->viewport;
}

TObjectState *blokContextGetObjectState(void)
{
    return &blokContextGet()->state;
}