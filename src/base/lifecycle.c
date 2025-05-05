#include "lifecycle.h"
#include "../cmd/args.h"

int blokInit(Context *pContext, HINSTANCE hInstance, LPWSTR pCommandLine, DWORD showFlag)
{
    if (pContext == NULL)
        return 0;

    pContext->hInstance = hInstance;
    pContext->pCommandLine = pCommandLine;
    pContext->showFlag = showFlag;

    ArgsInfo argsResult;
    blokArgsProcess(&argsResult, pContext->pCommandLine);

    if (argsResult.showConsole)
        blokConsoleInit(&pContext->console);

    blokStateInit(&pContext->state, (VectorII){argsResult.scaleX, argsResult.scaleY});
    blokGraphicsInit(&pContext->graphics, argsResult.theme);
    blokViewportInit(&pContext->viewport, pContext->hInstance);

    return 1;
}

int blokRun(Context *pContext)
{
    if (pContext == NULL)
        return 0;

    blokViewportShow(&pContext->viewport, pContext->showFlag);

    return 1;
}

int blokFree(Context *pContext)
{
    if (pContext == NULL)
        return 0;

    blokViewportFree(&pContext->viewport, pContext->hInstance);
    blokGraphicsFree(&pContext->graphics);
    blokStateFree(&pContext->state);
    blokConsoleFree(&pContext->console);

    return 1;
}