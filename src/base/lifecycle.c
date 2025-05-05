#include "lifecycle.h"
#include "../cmd/args.h"

void blokInit(Context *pContext, HINSTANCE hInstance, LPWSTR pCommandLine, DWORD showFlag)
{
    if (!pContext) { return; }

    pContext->hInstance = hInstance;
    pContext->pCommandLine = pCommandLine;
    pContext->showFlag = showFlag;

    ArgsInfo argsResult;
    blokArgsProcess(pContext->pCommandLine, &argsResult);

    if (argsResult.showConsole)
    {
        blokConsoleInit(&pContext->console);
    }

    blokStateInit(&pContext->state, (VectorII){argsResult.scaleX, argsResult.scaleY});
    blokGraphicsInit(&pContext->graphics, argsResult.theme);
    blokViewportInit(&pContext->viewport, pContext->hInstance);
}

void blokRun(Context *pContext)
{
    if (!pContext) { return; }

    blokViewportShow(&pContext->viewport, pContext->showFlag);
}

void blokFree(Context *pContext)
{
    if (!pContext) { return; }

    blokViewportFree(&pContext->viewport, pContext->hInstance);
    blokGraphicsFree(&pContext->graphics);
    blokStateFree(&pContext->state);
    blokConsoleFree(&pContext->console);
}