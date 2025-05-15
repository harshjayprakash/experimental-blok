#include "context.h"

Context *blokContextGet(
    void)
{
    static Context context;
    return &context;
}

Graphics *blokContextGetGraphics(
    void)
{
    return &blokContextGet()->graphics;
}

Viewport *blokContextGetViewport(
    void)
{
    return &blokContextGet()->viewport;
}

State *blokContextGetState(
    void)
{
    return &blokContextGet()->state;
}