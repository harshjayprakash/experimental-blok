#ifndef __BLOK_PROGRAM_H
#define __BLOK_PROGRAM_H

#define STRICT 1
#include <Windows.h>
#include "args.h"

typedef struct bkProgram
{
	bkArgs args;
} bkProgram;

void bkInit(
	bkProgram* pProgram, HINSTANCE hInstance, HINSTANCE hPreviousInstance,
	LPWSTR pCommandLine, int showFlag);

void bkRun(bkProgram* pProgram);

void bkFree(bkProgram* pProgram);

#endif // !__BLOK_PROGRAM_H
