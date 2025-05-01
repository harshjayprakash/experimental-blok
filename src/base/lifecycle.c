#include "lifecycle.h"
#include "../cmd/args.h"

void blokInit(Context *context, HINSTANCE instance, LPWSTR commandLine, DWORD showFlag)
{
    if (!context) { return; }

    context->instance = instance;
    context->commandLine = commandLine;
    context->showFlag = showFlag;

    ArgsInfo argsResult;
    blokArgsProcess(context->commandLine, &argsResult);

    if (argsResult.showConsole)
    {
        blokConsoleInit(&context->console);
    }

    blokStateInit(&context->state, (VectorII){argsResult.scaleX, argsResult.scaleY});
    blokGraphicsInit(&context->graphics, argsResult.theme);
    blokViewportInit(&context->viewport, context->instance);
}

void blokRun(Context *context)
{
    if (!context) { return; }

    blokViewportShow(&context->viewport, context->showFlag);
}

void blokFree(Context *context)
{
    if (!context) { return; }

    blokViewportFree(&context->viewport, context->instance);
    blokGraphicsFree(&context->graphics);
    blokStateFree(&context->state);
    blokConsoleFree(&context->console);
}