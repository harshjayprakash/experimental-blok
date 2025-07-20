#include "lifecycle.h"

int stSetup(HINSTANCE hInstance, LPWSTR pCommandLine, int showFlag)
{
    if (hInstance == NULL || hInstance == INVALID_HANDLE_VALUE || pCommandLine == NULL)
    {
        return ST_EXIT_NULLPTR;
    }

    TContext *pContext = stContextGet();
    ZeroMemory(pContext, sizeof(*pContext));

    TParsedArgs args = {0};
    int ok = stArgsProcess(&args, pCommandLine);

    if (!ok)
    {
        ST_ARGS_SET_DEFAULT(args);
    }

    pContext->hInstance = hInstance;
    pContext->showFlag = showFlag;

    return stEntry(pContext, &args);
}

int stEntry(TContext* pContext, TParsedArgs *pArgs)
{
    if (pContext == NULL || pArgs == NULL)
    {
        return ST_EXIT_NULLPTR;
    }

    int ok = 0;
    int status = 0;

    TVector2 scale = {(long)pArgs->scaleX, (long)pArgs->scaleY};
    ok = stStateInit(&pContext->state, scale);

    if (!ok)
    {
        status = ST_EXIT_STATE_ERROR;
        goto stEntryCleanOnError;
    }

    ok = stGraphicsInit(&pContext->graphics, pArgs->theme);
    
    if (!ok)
    {
        status = ST_EXIT_GRAPHICS_ERROR;
        goto stEntryCleanOnError;
    }

    ok = stViewportInit(&pContext->viewport, pContext->hInstance);

    if (!ok)
    {
        status = ST_EXIT_VIEWPORT_ERROR;
        goto stEntryCleanOnError;
    }

    status = stViewportShow(&pContext->viewport, (DWORD)pContext->showFlag);

stEntryCleanOnError:

    (void)stViewportFree(&pContext->viewport, pContext->hInstance);
    (void)stGraphicsFree(&pContext->graphics);
    (void)stStateFree(&pContext->state);

    return status;
}
