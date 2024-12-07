/*****************************************************************//**
 * \file   program.h
 * \brief  Contains base program functions and structure.
 * 
 * \author Harsh Jayprakash
 * \date   04 of December 2024
 *********************************************************************/

#ifndef __BLOK_PROGRAM_H
#define __BLOK_PROGRAM_H

#define STRICT 1
#include <Windows.h>
#include "args.h"
#include "../presentation/window.h"

typedef struct bkProgram
{
	bkArgs args;
	bkWindow window;
} bkProgram;

void bkInit(
	bkProgram* pProgram, HINSTANCE hInstance, HINSTANCE hPreviousInstance,
	LPWSTR pCommandLine, int showFlag);

void bkRun(bkProgram* pProgram);

void bkFree(bkProgram* pProgram);

#endif // !__BLOK_PROGRAM_H
