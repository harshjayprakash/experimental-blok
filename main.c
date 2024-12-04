/*****************************************************************//**
 * \file   main.c
 * \brief  Contains the entrypoint into the program.
 * 
 * \author Harsh Jayprakash
 * \date   04th of December 2024
 *********************************************************************/

#define STRICT 1
#include <Windows.h>
#include "core/program.h"

/**
 * The entrypoint into the windows program.
 * 
 * \param hInstance - The handle to the program instance.
 * \param hPrevInstance - Previous version of the handle to the program. Not Used.
 * \param lpCmdLine - The command line.
 * \param nCmdShow - Specifies how the window will be shown.
 * \return Integer - 0 for success.
 */
int APIENTRY wWinMain(
	_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine,
	_In_ INT nCmdShow)
{
	bkProgram program;
	bkInit(&program, hInstance, hPrevInstance, lpCmdLine, nCmdShow);
	bkRun(&program);
	bkFree(&program);
	return 0;
}
