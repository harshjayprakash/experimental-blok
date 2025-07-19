#include "lifecycle.h"
#include <handleapi.h>

int stSetup(HINSTANCE hInstance, LPWSTR pCommandLine, int showFlag)
{
    if (hInstance == NULL || hInstance == INVALID_HANDLE_VALUE || pCommandLine == NULL)
    {
        return 1;
    }

    stContext *pContext = blokContextGet();
    stParsedArgs pArgs;

    return stEntry(pContext, &pArgs);
}

int stEntry(stContext* pContext, stParsedArgs* pArgs)
{
    return 0;
}
