#include "lifecycle.h"
#include "cmd/args.h"

int stInit(
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
    (void)stArgsProcess(&argsResult, pContext->pCommandLine);

    if (argsResult.showConsole)
    {
        (void)stConsoleInit(&pContext->console);
    }

    (void)stStateInit(
        &pContext->state, 
        (TVector2){ argsResult.scaleX, argsResult.scaleY });
    (void)stGraphicsInit(&pContext->graphics, argsResult.theme);
    (void)stViewportInit(&pContext->viewport, pContext->hInstance);

    return 1;
}

int stRun(
    TContext *pContext)
{
    if (pContext == NULL)
    {
        return -1;
    }

    return stViewportShow(&pContext->viewport, pContext->showFlag);
}

int stFree(
    TContext *pContext)
{
    if (pContext == NULL) 
    {
        return 0;
    }

    (void)stViewportFree(&pContext->viewport, pContext->hInstance);
    (void)stGraphicsFree(&pContext->graphics);
    (void)stStateFree(&pContext->state);
    (void)stConsoleFree(&pContext->console);

    return 1;
}