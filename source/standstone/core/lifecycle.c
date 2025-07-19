#include "lifecycle.h"

int stSetup(HINSTANCE hInstance, LPWSTR pCommandLine, int showFlag)
{
    if (hInstance == NULL || hInstance == INVALID_HANDLE_VALUE || pCommandLine == NULL)
    {
        return 1;
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
        return 2;
    }

    int ok = 0;
    int status = 0;

    TVector2 scale = {(long)pArgs->scaleX, (long)pArgs->scaleY};
    ok = stStateInit(&pContext->state, scale);

    if (!ok)
    {
        status = 3;
        goto stEntryCleanOnError;
    }

    ok = stGraphicsInit(&pContext->graphics, pArgs->theme);
    
    if (!ok)
    {
        status = 4;
        goto stEntryCleanOnError;
    }

    ok = stViewportInit(&pContext->viewport, pContext->hInstance);

    if (!ok)
    {
        status = 5;
        goto stEntryCleanOnError;
    }

    status = stViewportShow(&pContext->viewport, (DWORD)pContext->showFlag);

stEntryCleanOnError:

    (void)stViewportFree(&pContext->viewport, pContext->hInstance);
    (void)stGraphicsFree(&pContext->graphics);
    (void)stStateFree(&pContext->state);

    return status;
}
