#include "lifecycle.h"
#include "../cmd/args.h"

void BlokInit(Context *context, HINSTANCE instance, LPWSTR commandLine, DWORD showFlag)
{
    if (!context) { return; }

    context->instance = instance;
    context->commandLine = commandLine;
    context->showFlag = showFlag;

    ArgsInfo argsResult;
    BlokArgsProcess(context->commandLine, &argsResult);

    if (argsResult.showConsole)
    {
        BlokConsoleInit(&context->console);
    }

    BlokStateInit(&context->state, (VectorII){argsResult.scaleX, argsResult.scaleY});
    BlokGraphicsInit(&context->graphics, argsResult.theme);
    BlokViewportInit(&context->viewport, context->instance);
}

void BlokRun(Context *context)
{
    if (!context) { return; }

    BlokViewportShow(&context->viewport, context->showFlag);
}

void BlokFree(Context *context)
{
    if (!context) { return; }

    BlokViewportFree(&context->viewport, context->instance);
    BlokGraphicsFree(&context->graphics);
    BlokStateFree(&context->state);
    BlokConsoleFree(&context->console);
}