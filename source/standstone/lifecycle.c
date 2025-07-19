#include "lifecycle.h"
#include "cmd/args.h"

int blokInit(
    TContext *pContext,
    HINSTANCE hInstance,
    LPWSTR pCommandLine,
    DWORD showFlag)
{
    if (pContext == NULL)
    {
        return 0;
    }

    pContext->hInstance = hInstance;
    pContext->pCommandLine = pCommandLine;
    pContext->showFlag = showFlag;

    TArgsResult argsResult;
    (void)blokArgsProcess(&argsResult, pContext->pCommandLine);

    if (argsResult.showConsole)
    {
        (void)blokConsoleInit(&pContext->console);
    }

    (void)blokStateInit(
        &pContext->state, 
        (TVector2){ argsResult.scaleX, argsResult.scaleY });
    (void)blokGraphicsInit(&pContext->graphics, argsResult.theme);
    (void)blokViewportInit(&pContext->viewport, pContext->hInstance);

    return 1;
}

int blokRun(
    TContext *pContext)
{
    if (pContext == NULL)
    {
        return -1;
    }

    return blokViewportShow(&pContext->viewport, pContext->showFlag);
}

int blokFree(
    TContext *pContext)
{
    if (pContext == NULL) 
    {
        return 0;
    }

    (void)blokViewportFree(&pContext->viewport, pContext->hInstance);
    (void)blokGraphicsFree(&pContext->graphics);
    (void)blokStateFree(&pContext->state);
    (void)blokConsoleFree(&pContext->console);

    return 1;
}