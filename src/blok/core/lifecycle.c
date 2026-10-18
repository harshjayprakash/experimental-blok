#include "lifecycle.h"

int BlokSetup(HINSTANCE hInstance, LPWSTR pCommandLine, int showFlag)
{
    if (hInstance == NULL || hInstance == INVALID_HANDLE_VALUE || pCommandLine == NULL)
    {
        return BLOK_EXIT_NULLPTR;
    }

    TContext *pContext = BlokContextGet();
    ZeroMemory(pContext, sizeof(*pContext));

    TParsedArgs args = {0};
    BLOK_ARGS_SET_DEFAULT(args);

    if (!BlokArgsParse(&args, pCommandLine))
    {
        (void)MessageBoxW(NULL, L"Argument Parsing Failed.", L"Blok",
                          MB_OK | MB_ICONWARNING);
    }

    pContext->hInstance = hInstance;
    pContext->showFlag = showFlag;

    return BlokEntry(pContext, &args);
}

int BlokEntry(TContext *pContext, TParsedArgs *pArgs)
{
    if (pContext == NULL || pArgs == NULL)
    {
        return BLOK_EXIT_NULLPTR;
    }

    int result = BLOK_EXIT_SUCCESS;
    int exitCode = 0;
    TVector2 scale = {(long)pArgs->scaleX, (long)pArgs->scaleY};

    if (!BlokStateInit(&pContext->state, scale))
    {
        result = BLOK_EXIT_STATE_ERROR;
        goto onBlokError;
    }

    if (!BlokGraphicsInit(&pContext->graphics, (TTheme)pArgs->theme))
    {
        result = BLOK_EXIT_GRAPHICS_ERROR;
        goto onBlokError;
    }

    if (!BlokViewportInit(&pContext->viewport, pContext->hInstance))
    {
        result = BLOK_EXIT_VIEWPORT_ERROR;
        goto onBlokError;
    }

    exitCode = BlokViewportShow(&pContext->viewport, (DWORD)pContext->showFlag);

onBlokError:

    int vr = BlokViewportFree(&pContext->viewport, pContext->hInstance);
    int gr = BlokGraphicsFree(&pContext->graphics);
    int sr = BlokStateFree(&pContext->state);

    if (!vr && !gr && !sr)
    {
        result = BLOK_EXIT_CLEANUP_ERROR;
    }

    int status = result | exitCode;

    return status;
}
