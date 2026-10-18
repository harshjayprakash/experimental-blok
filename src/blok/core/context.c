#include "context.h"

TContext *BlokContextGet(void)
{
    static TContext context;
    return &context;
}

TGraphics *BlokContextGetGraphics(void)
{
    return &BlokContextGet()->graphics;
}

TViewport *BlokContextGetViewport(void)
{
    return &BlokContextGet()->viewport;
}

TObjectState *BlokContextGetObjectState(void)
{
    return &BlokContextGet()->state;
}