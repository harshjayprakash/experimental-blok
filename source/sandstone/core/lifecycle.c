/**
 * @file lifecycle.c
 * @brief Setup and Entry Implementation.
 * @author harshjayprakash
 * @date 2025-07-20
 ****************************************************************************************/

#include "lifecycle.h"

int stSetup(
    HINSTANCE hInstance, 
    LPWSTR pCommandLine, 
    int showFlag)
{
    if (hInstance == NULL || hInstance == INVALID_HANDLE_VALUE || pCommandLine == NULL)
    {
        return ST_EXIT_NULLPTR;
    }

    TContext *pContext = stContextGet();
    ZeroMemory(pContext, sizeof(*pContext));

    TParsedArgs args = {0};
    ST_ARGS_SET_DEFAULT(args);

    if (!stArgsParse(&args, pCommandLine))
    {
        (void)MessageBoxW(NULL, L"Argument Parsing Failed.", L"Blok",
                          MB_OK | MB_ICONWARNING);
    }

    pContext->hInstance = hInstance;
    pContext->showFlag = showFlag;

    return stEntry(pContext, &args);
}

int stEntry(
    TContext *pContext, 
    TParsedArgs *pArgs)
{
    if (pContext == NULL || pArgs == NULL)
    {
        return ST_EXIT_NULLPTR;
    }

    int result = ST_EXIT_SUCCESS;
    int exitCode = 0;
    TVector2 scale = {(long)pArgs->scaleX, (long)pArgs->scaleY};

    if (!stStateInit(&pContext->state, scale))
    {
        result = ST_EXIT_STATE_ERROR;
        goto stEntryCleanOnError;
    }

    if (!stGraphicsInit(&pContext->graphics, (TTheme)pArgs->theme))
    {
        result = ST_EXIT_GRAPHICS_ERROR;
        goto stEntryCleanOnError;
    }

    if (!stViewportInit(&pContext->viewport, pContext->hInstance))
    {
        result = ST_EXIT_VIEWPORT_ERROR;
        goto stEntryCleanOnError;
    }

    exitCode = stViewportShow(&pContext->viewport, (DWORD)pContext->showFlag);

stEntryCleanOnError:

    int vr = stViewportFree(&pContext->viewport, pContext->hInstance);
    int gr = stGraphicsFree(&pContext->graphics);
    int sr = stStateFree(&pContext->state);

    if (vr && gr && sr)
    {
        result = ST_EXIT_CLEANUP_ERROR;
    }

    int status = result | exitCode;

    return status;
}
