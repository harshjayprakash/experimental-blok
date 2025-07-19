#include "lifecycle.h"
#include <handleapi.h>

int stSetup(HINSTANCE hInstance, LPWSTR pCommandLine, int showFlag)
{
    if (hInstance == NULL || hInstance == INVALID_HANDLE_VALUE || pCommandLine == NULL)
    {
        return 1;
    }

    TContext *pContext = stContextGet();
    void *pArgs;

    return stEntry(pContext, &pArgs);
}

int stEntry(TContext* pContext, void *pArgs)
{
    return 0;
}
