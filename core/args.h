/*****************************************************************//**
 * \file   args.h
 * \brief  Contains the `bkArgs` type.
 * 
 * \author Harsh Jayprakash
 * \date   04th of December 2024
 *********************************************************************/

#ifndef __BLOK_ARGS_H
#define __BLOK_ARGS_H

#define STRICT 1
#include <Windows.h>

typedef struct bkArgs
{
	HINSTANCE hInstance;
	HINSTANCE hPreviousInstance;
	LPWSTR pCommandLine;
	int showFlag;
} bkArgs;

#endif // !__BLOK_ARGS_H
