/**
 * @file LIFECYCLE.C
 * @date 26-05-2025
 * @brief Implementation of the program lifecycle routines.
 */

#include "lifecycle.h"
#include "cmd/args.h"

int blokInit(
    Context *pContext,
    HINSTANCE hInstance,
    LPWSTR pCommandLine,
    DWORD showFlag)
{
    if (pContext == NULL) {
        return 0;
    }

    pContext->hInstance = hInstance;
    pContext->pCommandLine = pCommandLine;
    pContext->showFlag = showFlag;

    ArgsInfo argsResult;
    (void)blokArgsProcess(&argsResult, pContext->pCommandLine);

    if (argsResult.showConsole) {
        (void)blokConsoleInit(&pContext->console);
    }

    (void)blokStateInit(
        &pContext->state, 
        (VectorII){ argsResult.scaleX, argsResult.scaleY });
    (void)blokGraphicsInit(&pContext->graphics, argsResult.theme);
    (void)blokViewportInit(&pContext->viewport, pContext->hInstance);

    return 1;
}

int blokRun(
    Context *pContext)
{
    if (pContext == NULL) {
        return -1;
    }

    return blokViewportShow(&pContext->viewport, pContext->showFlag);
}

int blokFree(
    Context *pContext)
{
    if (pContext == NULL) {
        return 0;
    }

    (void)blokViewportFree(&pContext->viewport, pContext->hInstance);
    (void)blokGraphicsFree(&pContext->graphics);
    (void)blokStateFree(&pContext->state);
    (void)blokConsoleFree(&pContext->console);

    return 1;
}