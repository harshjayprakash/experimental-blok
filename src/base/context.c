#include "context.h"

Context *BlokContextGet(void)
{
    static Context context;
    return &context;
}

Graphics *BlokContextGetGraphics(void)
{
    return &BlokContextGet()->graphics;
}

Viewport *BlokContextGetViewport(void)
{
    return &BlokContextGet()->viewport;
}

State *BlokContextGetState(void)
{
    return &BlokContextGet()->state;
}