#ifndef ST_CORE_LIFECYCLE_H
#define ST_CORE_LIFECYCLE_H

#include "../cmd/args.h"
#include "../context.h"
#include <minwindef.h>

typedef TContext stContext;
typedef TArgsResult stParsedArgs;

int stSetup(HINSTANCE hInstance, LPWSTR pCommandLine, int showFlag);

int stEntry(stContext *pContext, stParsedArgs *pArgs);

#endif /* ST_CORE_LIFECYCLE_H */