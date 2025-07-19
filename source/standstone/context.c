#include "context.h"

TContext *stContextGet(void)
{
    static TContext context;
    return &context;
}

TGraphics *stContextGetGraphics(void)
{
    return &stContextGet()->graphics;
}

TViewport *stContextGetViewport(void)
{
    return &stContextGet()->viewport;
}

TObjectState *stContextGetObjectState(void)
{
    return &stContextGet()->state;
}